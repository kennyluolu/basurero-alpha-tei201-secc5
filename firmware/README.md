# Firmware de EcoCompacta — ESP8266 con histórico persistente

**Estado 22-11-2026:** código preparado para el equipo, **pendiente de compilar y probar en el prototipo real**.

## Archivo de Arduino IDE
Abrir `EcoCompacta/EcoCompacta.ino`. La carpeta y el archivo comparten nombre, como requiere Arduino IDE.

## Dependencias y montaje
- Placa **NodeMCU ESP8266**, no ESP32.
- Librerías incluidas en el core Arduino ESP8266: `ESP8266WiFi.h`, `ESP8266WebServer.h`, `LittleFS.h`, `Arduino.h`.
- Sensor HC-SR04 alimentado conforme a su especificación. **ECHO de 5 V requiere divisor/level shifter 5→3,3 V antes del pin D2 del ESP8266**. Usar resistencias limitadoras en cada LED.
- Arduino IDE: instalar el core ESP8266, seleccionar placa correcta y un esquema `Flash Size` que **incluya sistema de archivos (FS/LittleFS)**. El tamaño depende de la placa física.
- Antes de cargar: confirmar que el LED azul funciona; en Alpha falló. Si falla, no etiquetar el indicador medio como probado.

## Configuración de calibración
Modificar al inicio del archivo:
- `DISTANCIA_VACIO_CM = 30.0` (**ejemplo**).
- `DISTANCIA_LLENO_CM = 3.0` (**ejemplo**).
Deben medirse **desde la cara del sensor** hasta el nivel de papel, teniendo en cuenta placa compactadora, borde del recipiente y zona ciega del HC-SR04.

`llenado_pct = 100×(DISTANCIA_VACIO_CM − distancia)/(DISTANCIA_VACIO_CM − DISTANCIA_LLENO_CM)`, limitado a [0, 100]. **Es una estimación geométrica de altura**, no una medición de volumen o de masa.

## Captura y almacenamiento
- Cada 1 segundo se intentan **tres** lecturas separadas 65 ms; se aceptan al menos 2 válidas y se muestra su mediana/promedio.
- Si no hay lectura válida, la alerta se apaga y la API entrega `lectura_valida: false`; no convertir una lectura inválida en 0%.
- Cada 30 segundos se escribe una muestra válida a **LittleFS** en `/historico.csv`; además se escribe una al inicio si el sensor está listo.
- Formato CSV: `sesion,tiempo_s,distancia_cm,llenado_pct`; `tiempo_s` es el tiempo transcurrido desde el encendido, **no hora real**.
- Registros persisten entre reinicios **si LittleFS está montado y no se borra/formatea la partición**. Se conserva archivo anterior tras alcanzar 160 kB (rotación); comprobar en ensayos.
- El dispositivo debe indicar **LittleFS lista** por monitor serie. Si aparece error, el dashboard puede seguir funcionando en vivo, **pero no cumple persistencia**.
- No usar una herramienta de carga masiva de archivos LittleFS sin respaldar primero el histórico: podría reemplazar el contenido almacenado.

## Dashboard y endpoints
1. Enviar firmware por USB; abrir monitor serie a **115200**.
2. Conectarse a Wi-Fi **EcoCompacta-Final** con clave de prueba **basurero123**.
3. Abrir **http://192.168.4.1/** para ver distancia, estimación de llenado, recomendación e histórico (últimos 100 puntos).
4. `http://192.168.4.1/api/estado`: JSON instantáneo.
5. `http://192.168.4.1/api/historico`: CSV descargable.
6. `http://192.168.4.1/api/historico-anterior`: CSV anterior si se rotó el archivo.

## Validación indispensable
- [ ] Compila correctamente en la instalación de Arduino IDE del equipo.
- [ ] Se carga sin errores en NodeMCU ESP8266 y crea el AP.
- [ ] El sensor responde a tres distancias reales medidas con regla.
- [ ] Porcentaje, alerta y LED corresponden a distancia física.
- [ ] Gráfico histórico se actualiza y archivo CSV contiene datos reales.
- [ ] **Reiniciar dispositivo** y verificar que permanece el CSV anterior.
- [ ] Confirmar las versiones del core/librerías y completar `FUENTES.md`.
- [ ] Probar el sistema encendido con el montaje final (incluida la placa móvil).

**Seguridad:** firmware solo monitorea. No acciona servos/motores y no protege mecánicamente un sistema de compactación. Todo motor requiere diseño independiente con enclavamiento y parada de emergencia.

[Fuente: documentación oficial LittleFS del core ESP8266](https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html).
