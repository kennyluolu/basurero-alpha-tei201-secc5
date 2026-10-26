#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#define TRIG D1
#define ECHO D2
#define VERDE D5
#define AZUL D6
#define ROJO D7
ESP8266WebServer web(80);
float distancia = -1;
float porcentaje = 0;
bool lecturaOK = false;
void medir() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  unsigned long t = pulseIn(ECHO, HIGH, 30000);
  digitalWrite(VERDE, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(ROJO, LOW);
  if (t == 0) {
    lecturaOK = false;
    Serial.println("SIN LECTURA");
    return;
  }
  distancia = t * 0.0343 / 2.0;
  if (distancia < 2 || distancia > 30) {
    lecturaOK = false;
    Serial.print("FUERA DE RANGO: ");
    Serial.println(distancia);
    return;
  }
  lecturaOK = true;
  porcentaje = constrain(
    (30.0 - distancia) / 30.0 * 100.0,
    0.0, 100.0
  );
  if (porcentaje < 50)
    digitalWrite(VERDE, HIGH);
  else if (porcentaje < 80)
    digitalWrite(AZUL, HIGH);
  else
    digitalWrite(ROJO, HIGH);
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.print(" cm | Llenado: ");
  Serial.print(porcentaje);
  Serial.println("%");
}
void inicio() {
  String pagina =
    "<html><head>"
    "<meta name='viewport' content='width=device-width,initial-scale=1'>"
    "<meta http-equiv='refresh' content='2'>"
    "</head><body style='font-family:Arial;text-align:center'>"
    "<h1>BASURERO ALPHA</h1>";
  if (lecturaOK) {
    pagina += "<h1>" + String(porcentaje,1) + "%</h1>";
    pagina += "<p>Distancia: " + String(distancia,1) + " cm</p>";
    pagina += "<h2>";
    if (porcentaje < 50) pagina += "VERDE - Disponible";
    else if (porcentaje < 80) pagina += "AZUL - Medio lleno";
    else pagina += "ROJO - Lleno";
    pagina += "</h2>";
  } else {
    pagina += "<h2>Sin lectura valida</h2>";
  }
  pagina += "</body></html>";
  web.send(200, "text/html", pagina);
}
void setup() {
  Serial.begin(115200);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(ROJO, OUTPUT);
// PRUEBA DEL LED AZUL
digitalWrite(AZUL, HIGH);
delay(5000);
digitalWrite(AZUL, LOW);
  digitalWrite(TRIG, LOW);
  WiFi.mode(WIFI_AP);
  WiFi.softAP("Basurero-Alpha", "basurero123");
  web.on("/", inicio);
  web.begin();
  Serial.println("WiFi: Basurero-Alpha");
  Serial.println("IP: 192.168.4.1");
}
void loop() {
  web.handleClient();
  static unsigned long anterior = 0;
  if (millis() - anterior >= 1000) {
    anterior = millis();
    medir();
  }
}
