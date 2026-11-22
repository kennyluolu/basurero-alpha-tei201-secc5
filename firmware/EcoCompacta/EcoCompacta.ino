/*
  EcoCompacta - entrega final TEI201 (ESP8266 + HC-SR04 + LittleFS)
  Estado 22-11-2026: PROPUESTA de firmware, aún NO probado ni compilado en hardware.
  Solo monitoreo. NO controla compactación ni motores.
  Pines verificados con codigo Alpha; revisar conexión REAL antes de energizar.
  ECHO HC-SR04 5V -> divisor/convertidor a 3.3V -> ESP8266 D2.
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <LittleFS.h>

const uint8_t TRIG = D1, ECHO = D2;
const uint8_t LED_VERDE = D5, LED_AZUL = D6, LED_ROJO = D7;
const float DISTANCIA_VACIO_CM = 30.0f;  // EJEMPLO: calibrar en recipiente real
const float DISTANCIA_LLENO_CM = 3.0f;   // EJEMPLO: calibrar con interferencias reales
const unsigned long PERIODO_SENSOR_MS = 1000UL;
const unsigned long PERIODO_CSV_MS = 30000UL; // Reducir escrituras en flash
const size_t MAX_CSV_BYTES = 160000U;
const char* SSID = "EcoCompacta-Final";
const char* CLAVE = "basurero123";
const char* RUTA_LOG = "/historico.csv";
const char* RUTA_LOG_ANT = "/historico_anterior.csv";
ESP8266WebServer servidor(80);

bool lecturaValida = false;
bool calibracionValida = false;
bool almacenamientoOK = false;
float distancia = -1.0f;
float porcentaje = 0.0f;
uint32_t sesion = 0;
unsigned long ultimoSensorMs = 0, ultimoCsvMs = 0;
bool seRegistroMuestra = false;

void configurarLeds() {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_ROJO, LOW);
  if (!lecturaValida || !calibracionValida) return;
  if (porcentaje < 50.0f) digitalWrite(LED_VERDE, HIGH);
  else if (porcentaje < 80.0f) digitalWrite(LED_AZUL, HIGH);
  else digitalWrite(LED_ROJO, HIGH);
}

float leerUnaDistancia() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(3);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  const unsigned long us = pulseIn(ECHO, HIGH, 6500UL);
  if (us == 0) return -1.0f;
  const float cm = us * 0.0343f * 0.5f;
  if (cm < 2.0f || cm > 100.0f) return -1.0f;
  return cm;
}

void medir() {
  float a[3] = {-1.0f,-1.0f,-1.0f};
  uint8_t n = 0;
  for (uint8_t i = 0; i < 3; ++i) {
    float cm = leerUnaDistancia();
    if (cm > 0.0f) a[n++] = cm;
    if (i < 2) delay(65); // Evita interferencia entre pulsos
  }
  calibracionValida = DISTANCIA_VACIO_CM > DISTANCIA_LLENO_CM;
  lecturaValida = n >= 2;
  if (!lecturaValida) {
    distancia = -1.0f;
    configurarLeds();
    Serial.println(F("Lectura no valida"));
    return;
  }
  if (a[1] < a[0]) {float t=a[0];a[0]=a[1];a[1]=t;}
  if (n == 3) {
    if (a[2] < a[1]) {float t=a[1];a[1]=a[2];a[2]=t;}
    if (a[1] < a[0]) {float t=a[0];a[0]=a[1];a[1]=t;}
    distancia = a[1]; // Mediana de tres lecturas
  } else distancia = 0.5f*(a[0]+a[1]); // Promedio si hay dos
  if (calibracionValida) {
    porcentaje = constrain(
      100.0f*(DISTANCIA_VACIO_CM-distancia)/
      (DISTANCIA_VACIO_CM-DISTANCIA_LLENO_CM),0.0f,100.0f);
  }
  configurarLeds();
  if (!calibracionValida) {
    Serial.printf("Distancia=%.1f cm | calibracion invalida\n",distancia);
  } else {
    Serial.printf("Distancia=%.1f cm | Nivel=%.1f%%\n",distancia,porcentaje);
  }
}

bool escribirCabeceraSiFalta() {
  if (!almacenamientoOK) return false;
  if (LittleFS.exists(RUTA_LOG)) return true;
  File f=LittleFS.open(RUTA_LOG,"w");
  if (!f) return false;
  f.println(F("sesion,tiempo_s,distancia_cm,llenado_pct"));
  f.close();
  return true;
}

void guardarEnCSV() {
  if (!almacenamientoOK || !lecturaValida || !calibracionValida) return;
  if (!escribirCabeceraSiFalta()) {almacenamientoOK=false; return;}
  File prueba=LittleFS.open(RUTA_LOG,"r");
  if (!prueba) {almacenamientoOK=false; return;}
  const size_t actual = prueba.size();
  prueba.close();
  if (actual >= MAX_CSV_BYTES) {
    if (LittleFS.exists(RUTA_LOG_ANT)) LittleFS.remove(RUTA_LOG_ANT);
    if (!LittleFS.rename(RUTA_LOG,RUTA_LOG_ANT)) {
      Serial.println(F("No se pudo rotar historico"));
      almacenamientoOK=false;
      return;
    }
    if (!escribirCabeceraSiFalta()) {almacenamientoOK=false;return;}
  }
  File f=LittleFS.open(RUTA_LOG,"a");
  if (!f) {almacenamientoOK=false;return;}
  f.print(sesion); f.print(',');
  f.print(millis()/1000UL); f.print(',');
  f.print(distancia,2); f.print(',');
  f.println(porcentaje,2);
  f.close();
  seRegistroMuestra = true;
}

void iniciarAlmacenamiento() {
  almacenamientoOK=LittleFS.begin();
  if (!almacenamientoOK) {
    Serial.println(F("ERROR LittleFS: sin persistencia, revisar Flash Size"));
    return; // No formatear para evitar perdida de datos
  }
  uint32_t anterior=0;
  if (LittleFS.exists("/sesion.txt")) {
    File f=LittleFS.open("/sesion.txt","r");
    if (f) {anterior=(uint32_t)f.parseInt();f.close();}
  }
  sesion=anterior+1;
  File f=LittleFS.open("/sesion.txt","w");
  if (!f) almacenamientoOK=false;
  else {f.println(sesion); f.close();}
  if (almacenamientoOK && !escribirCabeceraSiFalta()) almacenamientoOK=false;
  Serial.println(almacenamientoOK ? F("LittleFS lista") : F("Fallo CSV"));
}

void enviarEstado() {
  String s=F("{\"lectura_valida\":");
  s+=lecturaValida ? F("true") : F("false");
  s+=F(",\"calibracion_valida\":");
  s+=calibracionValida ? F("true") : F("false");
  s+=F(",\"almacenamiento_ok\":");
  s+=almacenamientoOK ? F("true") : F("false");
  s+=F(",\"historial_registrado\":");
  s+=seRegistroMuestra ? F("true") : F("false");
  s+=F(",\"distancia_cm\":");
  s+=lecturaValida ? String(distancia,1) : String(F("null"));
  s+=F(",\"llenado_pct\":");
  s+=lecturaValida ? String(porcentaje,1) : String(F("null"));
  s+=F(",\"sesion\":"); s+=String(sesion);
  s+=F(",\"estado\":\"");
  if (!lecturaValida) s+=F("Sin lectura");
  else if (!calibracionValida) s+=F("Distancia disponible; calibracion pendiente");
  else if (porcentaje < 50.0f) s+=F("Disponible");
  else if (porcentaje < 80.0f) s+=F("Medio lleno");
  else s+=F("Lleno: evaluar compactar o vaciar");
  s+=F("\"}");
  servidor.send(200,"application/json; charset=utf-8",s);
}

void enviarCSV(const char* ruta) {
  if (!almacenamientoOK) {servidor.send(503,"text/plain","LittleFS no disponible");return;}
  File f=LittleFS.open(ruta,"r");
  if (!f) {servidor.send(404,"text/plain","Archivo CSV no encontrado");return;}
  servidor.streamFile(f,"text/csv; charset=utf-8");
  f.close();
}

const char PAGINA[] PROGMEM = R"PAGE(
<!doctype html><html lang="es"><head><meta charset="utf-8">
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>EcoCompacta | Dashboard</title><style>
*{box-sizing:border-box}body{font-family:system-ui,sans-serif;background:#0d161e;color:#eff7f3;margin:0;padding:20px}
main{max-width:810px;margin:auto}header{margin:20px 0 27px}.tag{color:#92ccc0;letter-spacing:.18em;font-size:12px}
h1{font-size:38px;margin:8px 0}h2{font-size:19px}.grid{display:grid;grid-template-columns:1fr 1fr;gap:16px}
.card{background:#1a2934;border:1px solid #344650;border-radius:18px;padding:22px;margin:0 0 17px}
.valor{font-size:64px;font-weight:750;letter-spacing:-.05em}.muted{color:#b1c6cf}.bar{height:16px;border-radius:12px;background:#38515b;overflow:hidden}
#fill{height:100%;width:0;background:#46d69f;transition:width .3s}#chart{display:block;width:100%;height:210px}
label{font-weight:700}a{color:#8fdfc7}small{color:#90aab4;line-height:1.6}
@media(max-width:520px){.grid{grid-template-columns:1fr}.valor{font-size:54px}}
</style></head><body><main>
<header><div class="tag">TEI201 · ESP8266 · MONITOREO REAL</div><h1>EcoCompacta</h1><p class="muted">Nivel de llenado de papel seco</p></header>
<section class="grid">
<div class="card"><div class="muted">Ocupación estimada</div><div class="valor" id="nivel">--%</div>
<div class="bar"><div id="fill"></div></div></div>
<div class="card"><div class="muted">Distancia del sensor</div><div class="valor" id="dist">--</div><span class="muted">centímetros</span></div>
</section>
<section class="card"><label>Acción recomendada</label><p id="accion">Esperando medición...</p><small id="storage">Comprobando almacenamiento…</small></section>
<section class="card"><h2>Histórico de mediciones</h2><canvas id="chart" width="760" height="210"></canvas>
<p class="muted" id="meta">Esperando histórico…</p><a href="/api/historico" download="historico.csv">Descargar CSV</a></section>
<p><small>Se mide distancia, no volumen exacto. Los registros usan sesión de encendido y segundos desde inicio, no hora de calendario (sin RTC). El sistema no acciona motores.</small></p>
</main><script>
const el=id=>document.getElementById(id);
async function refrescar(){
 try{
  const r=await fetch('/api/estado',{cache:'no-store'});
  if(!r.ok)throw Error();
  const x=await r.json();el('storage').textContent=x.almacenamiento_ok?'Histórico persistente LittleFS: activo':'ATENCIÓN: almacenamiento LittleFS no disponible';
  if(!x.lectura_valida){
   el('nivel').textContent='--%';el('dist').textContent='--';
   el('accion').textContent='Sensor sin lectura válida: revisar posición, cableado y objetos';el('fill').style.width='0%';return;
  }
  if(!x.calibracion_valida){
   el('nivel').textContent='--%';el('dist').textContent=Number(x.distancia_cm).toFixed(1);
   el('accion').textContent='Distancia disponible; falta calibrar vacío y lleno';el('fill').style.width='0%';return;
  }
  const p=Number(x.llenado_pct);
  el('nivel').textContent=p.toFixed(1)+'%';el('dist').textContent=Number(x.distancia_cm).toFixed(1);
  el('fill').style.width=p+'%';
  el('fill').style.background=p>=80?'#f98181':p>=50?'#ffcb75':'#46d69f';
  el('accion').textContent=x.estado;
 }catch(e){el('accion').textContent='Sin conexión con ESP8266';}
}
function graficar(a){
 const cv=el('chart'),c=cv.getContext('2d'),W=cv.width,H=cv.height,pad=32;
 c.clearRect(0,0,W,H);
 c.strokeStyle='#526672';c.lineWidth=1;
 for(let z=0;z<=4;z++){
  const y=H-pad-(H-2*pad)*z/4;
  c.beginPath();c.moveTo(pad,y);c.lineTo(W-pad,y);c.stroke();
  c.fillStyle='#a8bdc6';c.font='12px sans-serif';c.fillText(z*25+'%',2,y+4);
 }
 if(!a.length){c.fillStyle='#b1c6cf';c.font='14px sans-serif';c.fillText('Aún no hay datos guardados',pad+20,H/2);return;}
 c.beginPath();c.lineWidth=3;c.strokeStyle='#48deb0';
 a.forEach((x,i)=>{
  const X=pad+(W-2*pad)*(a.length===1?.5:i/(a.length-1));
  const Y=H-pad-(H-2*pad)*Math.min(100,Math.max(0,x))/100;
  if(i===0)c.moveTo(X,Y);else c.lineTo(X,Y);
 });c.stroke();
}
async function historial(){
 try{
  const r=await fetch('/api/historico',{cache:'no-store'});if(!r.ok)throw Error();
  const t=await r.text(),lines=t.trim().split(/\r?\n/).slice(1);
  const data=lines.map(line=>line.split(',')).filter(v=>v.length>=4&&isFinite(Number(v[3]))).map(v=>Number(v[3]));
  graficar(data.slice(-100));
  el('meta').textContent=data.length+' registros guardados (últimos 100 en el gráfico).';
 }catch(e){graficar([]);el('meta').textContent='Histórico no disponible';}
}
refrescar();historial();setInterval(refrescar,1000);setInterval(historial,30000);
</script></body></html>
)PAGE";

void enviarPagina() {
  servidor.send_P(200,PSTR("text/html; charset=utf-8"),PAGINA);
}

void setup() {
  Serial.begin(115200);
  pinMode(TRIG,OUTPUT);pinMode(ECHO,INPUT);
  pinMode(LED_VERDE,OUTPUT);pinMode(LED_AZUL,OUTPUT);pinMode(LED_ROJO,OUTPUT);
  digitalWrite(TRIG,LOW);configurarLeds();
  iniciarAlmacenamiento();
  WiFi.mode(WIFI_AP);
  WiFi.softAP(SSID,CLAVE);
  servidor.on("/",HTTP_GET,enviarPagina);
  servidor.on("/api/estado",HTTP_GET,enviarEstado);
  servidor.on("/api/historico",HTTP_GET,[](){enviarCSV(RUTA_LOG);});
  servidor.on("/api/historico-anterior",HTTP_GET,[](){enviarCSV(RUTA_LOG_ANT);});
  servidor.onNotFound([](){servidor.send(404,"text/plain","Ruta no encontrada");});
  servidor.begin();
  medir();guardarEnCSV();ultimoSensorMs=millis();ultimoCsvMs=millis();
  Serial.print(F("Conectar a "));Serial.println(SSID);
  Serial.print(F("Abrir http://"));Serial.println(WiFi.softAPIP());
}

void loop() {
  servidor.handleClient();
  unsigned long ahora=millis();
  if(ahora-ultimoSensorMs >= PERIODO_SENSOR_MS) {
    ultimoSensorMs=ahora;medir();
  }
  if(ahora-ultimoCsvMs >= PERIODO_CSV_MS) {
    ultimoCsvMs=ahora;guardarEnCSV();
  }
}
