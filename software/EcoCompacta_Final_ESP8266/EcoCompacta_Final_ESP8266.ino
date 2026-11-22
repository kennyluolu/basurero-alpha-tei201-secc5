/*
  EcoCompacta - Monitor de llenado ESP8266 (version de preparacion final)
  Controlador: NodeMCU ESP8266. Este firmware NO acciona compactacion.
  Estado: pendiente de compilacion y pruebas en hardware final.
  Calibrar DISTANCIA_VACIO_CM y DISTANCIA_LLENO_CM con el basurero fisico.
  IMPORTANTE: ECHO HC-SR04 a GPIO de 3.3V mediante divisor/level shifter.
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

constexpr uint8_t PIN_TRIG = D1;  // GPIO5
constexpr uint8_t PIN_ECHO = D2;  // GPIO4 - con adaptacion de nivel
constexpr uint8_t LED_VERDE = D5;
constexpr uint8_t LED_AZUL = D6;  // LED pendiente de validar fisicamente
constexpr uint8_t LED_ROJO = D7;

// Valores iniciales, NO mediciones confirmadas del prototipo final.
constexpr float DISTANCIA_VACIO_CM = 30.0f;
constexpr float DISTANCIA_LLENO_CM = 3.0f;
constexpr unsigned long INTERVALO_MEDICION_MS = 1000UL;

const char *WIFI_SSID = "EcoCompacta-Final";
const char *WIFI_PASS = "basurero123"; // reemplazar si se publica en produccion

ESP8266WebServer servidor(80);
float distanciaCm = -1.0f;
float porcentajeLlenado = 0.0f;
bool lecturaValida = false;
unsigned long ultimaMedicionMs = 0;

float leerDistanciaCm() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(3);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  const unsigned long tiempo = pulseIn(PIN_ECHO, HIGH, 6000UL);
  if (tiempo == 0) return -1.0f;

  const float distancia = tiempo * 0.0343f / 2.0f;
  if (distancia < 2.0f || distancia > 80.0f) return -1.0f;
  return distancia;
}

void actualizarIndicadores() {
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_AZUL, LOW);
  digitalWrite(LED_ROJO, LOW);

  if (!lecturaValida) return;
  if (porcentajeLlenado < 50.0f) digitalWrite(LED_VERDE, HIGH);
  else if (porcentajeLlenado < 80.0f) digitalWrite(LED_AZUL, HIGH);
  else digitalWrite(LED_ROJO, HIGH);
}

void medirNivel() {
  // Se descartan lecturas sin eco; se necesitan >=2 de 3 lecturas.
  float muestras[3] = {-1.0f, -1.0f, -1.0f};
  uint8_t n = 0;
  for (uint8_t i = 0; i < 3; ++i) {
    const float d = leerDistanciaCm();
    if (d > 0) muestras[n++] = d;
    if (i < 2) delay(65); // separar disparos del HC-SR04
  }

  if (n < 2 || DISTANCIA_VACIO_CM <= DISTANCIA_LLENO_CM) {
    lecturaValida = false;
    distanciaCm = -1.0f;
    actualizarIndicadores();
    Serial.println(F("Sin lectura valida / revisar calibracion"));
    return;
  }
  // Ordenar muestras validas (maximo 3).
  for (uint8_t i = 0; i < n; ++i) {
    for (uint8_t j = i + 1; j < n; ++j) {
      if (muestras[j] < muestras[i]) {
        const float aux = muestras[i];
        muestras[i] = muestras[j];
        muestras[j] = aux;
      }
    }
  }
  distanciaCm = (n == 3) ? muestras[1] : (muestras[0] + muestras[1]) / 2.0f;
  porcentajeLlenado = constrain(
    100.0f * (DISTANCIA_VACIO_CM - distanciaCm) /
    (DISTANCIA_VACIO_CM - DISTANCIA_LLENO_CM),
    0.0f, 100.0f
  );
  lecturaValida = true;
  actualizarIndicadores();

  Serial.print(F("Distancia: "));
  Serial.print(distanciaCm, 1);
  Serial.print(F(" cm | Llenado estimado: "));
  Serial.print(porcentajeLlenado, 1);
  Serial.println(F("%"));
}

void enviarJSON() {
  String json = F("{\"valido\":");
  json += lecturaValida ? F("true") : F("false");
  json += F(",\"distancia_cm\":");
  json += lecturaValida ? String(distanciaCm, 1) : F("null");
  json += F(",\"llenado_pct\":");
  json += lecturaValida ? String(porcentajeLlenado, 1) : F("null");
  json += F(",\"estado\":\"");
  if (!lecturaValida) json += F("sin lectura");
  else if (porcentajeLlenado < 50.0f) json += F("disponible");
  else if (porcentajeLlenado < 80.0f) json += F("medio");
  else json += F("lleno");
  json += F("\"}");
  servidor.send(200, "application/json; charset=utf-8", json);
}

void enviarPagina() {
  const char HTML[] PROGMEM = R"HTML(
<!doctype html><html lang="es"><head>
<meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>EcoCompacta | Nivel de llenado</title>
<style>
  *{box-sizing:border-box}body{margin:0;background:#101b22;color:#eff6f4;font-family:system-ui,Arial,sans-serif;display:grid;min-height:100vh;place-items:center;padding:20px}
  main{width:min(100%,450px);background:#1c2e36;border:1px solid #38505a;border-radius:20px;padding:30px}
  .tag{font-size:.78rem;letter-spacing:.15em;color:#9cb2b5;text-transform:uppercase}h1{font-size:2rem;margin:10px 0 22px}
  .numero{font-size:5rem;font-weight:800;line-height:1.1}.sub{color:#b8ced0;margin:8px 0 20px}
  .barra{height:15px;background:#344650;border-radius:12px;overflow:hidden}.progreso{height:100%;width:0;background:#4edca6;transition:width .3s}
  .estado{display:inline-block;margin-top:20px;padding:8px 13px;background:#30464d;border-radius:20px}
  small{display:block;color:#91a9af;margin-top:26px;line-height:1.6}
</style></head><body><main>
<div class="tag">Prototipo TEI201 - ESP8266</div><h1>EcoCompacta</h1>
<div class="numero" id="p">--%</div><div class="sub" id="d">Esperando sensor...</div>
<div class="barra"><div class="progreso" id="b"></div></div>
<div class="estado" id="e">Conectando...</div>
<small>Estimacion por sensor ultrasonico. Requiere calibracion con el recipiente real. Compactacion no controlada por esta interfaz.</small>
</main><script>
async function actualizar(){
 try{
  const r=await fetch('/api/estado',{cache:'no-store'});if(!r.ok)throw new Error('HTTP');
  const s=await r.json();
  if(!s.valido){
   document.getElementById('p').textContent='--%';
   document.getElementById('d').textContent='Sin lectura valida';
   document.getElementById('e').textContent='Revisar sensor';
   document.getElementById('b').style.width='0%';return;
  }
  const p=Math.max(0,Math.min(100,Number(s.llenado_pct)));
  document.getElementById('p').textContent=p.toFixed(1)+'%';
  document.getElementById('d').textContent='Distancia: '+Number(s.distancia_cm).toFixed(1)+' cm';
  document.getElementById('e').textContent=s.estado;
  const bar=document.getElementById('b');bar.style.width=p+'%';
  bar.style.background=p>=80?'#ff7979':p>=50?'#85bbff':'#4edca6';
 }catch(e){document.getElementById('e').textContent='Sin conexion';}
}
actualizar();setInterval(actualizar,1000);
</script></body></html>
)HTML";
  servidor.send_P(200, PSTR("text/html; charset=utf-8"), HTML);
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_AZUL, OUTPUT);
  pinMode(LED_ROJO, OUTPUT);
  digitalWrite(PIN_TRIG, LOW);
  actualizarIndicadores();

  WiFi.mode(WIFI_AP);
  WiFi.softAP(WIFI_SSID, WIFI_PASS);
  servidor.on("/", HTTP_GET, enviarPagina);
  servidor.on("/api/estado", HTTP_GET, enviarJSON);
  servidor.onNotFound([](){ servidor.send(404, "text/plain", "No encontrado"); });
  servidor.begin();

  Serial.println(F("EcoCompacta - WiFi listo"));
  Serial.print(F("IP: "));
  Serial.println(WiFi.softAPIP());
  medirNivel();
  ultimaMedicionMs = millis();
}

void loop() {
  servidor.handleClient();
  if (millis() - ultimaMedicionMs >= INTERVALO_MEDICION_MS) {
    ultimaMedicionMs = millis();
    medirNivel();
  }
}
