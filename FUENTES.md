# FUENTES.md — Declaración de fuentes, dependencias y uso de IA

**Proyecto:** EcoCompacta / Basurero compactador inteligente (TEI201, UAI, sección 5).  
**Actualizado:** 22 de noviembre de 2026.  
**Estado:** declaración de trabajo a completar y comprobar por el equipo antes de presentar. No reemplaza pruebas ni la comprensión del firmware.

## 1. Librerías y dependencias

| Componente / librería | Versión | Función | Fuente |
|---|---|---|---|
| Arduino Core for ESP8266 | **Por confirmar en Arduino IDE** | Compilación, GPIO, temporización, soporte de archivos | https://github.com/esp8266/Arduino |
| `ESP8266WiFi.h` | Incluida con la versión del core ESP8266 que instale el equipo | Crear punto de acceso local | https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html |
| `ESP8266WebServer.h` | Incluida con el core ESP8266; versión por confirmar | Servir página HTML y endpoints JSON/CSV | https://github.com/esp8266/Arduino |
| `LittleFS.h` | Incluida con versiones compatibles del core ESP8266; versión por confirmar | Almacenar archivo CSV histórico en flash del ESP8266 | https://arduino-esp8266.readthedocs.io/en/latest/filesystem.html |
| `Arduino.h` | Incluida con el core de placas | GPIO, `pulseIn`, `millis`, salida serie | https://github.com/esp8266/Arduino |
| HTML, CSS y JavaScript sin librerías externas | No aplica | Dashboard servido desde ESP8266 | Código en `firmware/EcoCompacta/EcoCompacta.ino` |

**Nota:** indicar número exacto de versión, placa NodeMCU y menú de memoria flash **después** de comprobarlo en el equipo real. No se declara una versión adivinada.

## 2. Documentación y referencias consultadas

- Repositorio de referencia para **organización**, no acreditado como origen de firmware copiado: https://github.com/jgarcia-dec/sensor-calidad-suelo-TEI201
- Repositorio anterior del equipo señalado en el proyecto Alpha: https://github.com/agustinlydegroote9/tei-201-sec7-grupo5-
- Core oficial y funcionamiento Wi-Fi del ESP8266: https://arduino-esp8266.readthedocs.io/
- Repositorio original del prototipo Alpha y evolución: https://github.com/kennyluolu/basurero-alpha-tei201-secc5
- Guía docente: *Avance #3 — Prototipo IoT Completo*, TEI201, DEC–UAI (documento entregado para revisión).

**Código externo de tutoriales/foros:** aún no se han identificado fragmentos literales copiados de terceros en el nuevo firmware. Si el equipo incorpora código externo, agregar URL, nombre del archivo, líneas adaptadas y descripción de cambios concretos. No presentar esta afirmación como auditoría exhaustiva del código antiguo.

## 3. Uso de inteligencia artificial (declaración explícita)

### 3.1. Prototipo Alpha — asistencia de IA anterior
- **Herramienta:** ChatGPT, utilizada en etapas previas del equipo (versión y fechas exactas por verificar).
- **Uso conocido:** apoyo al desarrollo del firmware ESP8266, elaboración de documentación, estructura y gestión de GitHub, según el README de Alpha.
- **Adaptaciones declaradas:** evolución desde la propuesta con ESP32 hasta el hardware ESP8266; configuración de pines y monitoreo del sensor con la placa actual. **La ejecución y autoría detallada debe ser confirmada por el equipo.**
- **Comprensión:** el equipo debe poder explicar el pulso TRIG, respuesta ECHO, conversión tiempo→distancia, estimación de llenado, LEDs y funcionamiento del modo AP.

### 3.2. Preparación de entrega final — ChatGPT (GPT-6, 22-11-2026)
- **Herramienta:** ChatGPT / GPT-6.
- **Solicitud del equipo (resumida fielmente, no presentada como cita literal):** preparar el GitHub y la entrega final del basurero compactador inteligente usando ESP8266, buscando mejorar la nota anterior, con montaje y presentación en la semana del 27 de noviembre; adaptar el trabajo a la guía de Avance #3.
- **Archivos asistidos/generados:** documentos de `entrega_final/`, portada `README.md` de la rama de entrega final, código en `software/EcoCompacta_Final_ESP8266/` y `firmware/EcoCompacta/`, tablas y este archivo `FUENTES.md`.
- **Aportes técnicos propuestos por IA:** rechazo de ecos inválidos, filtrado de lecturas, calibración ajustable, indicadores de nivel, servidor web local, dashboard de tendencias y persistencia de lecturas con LittleFS en archivo CSV, estructura de pruebas y justificación de componentes.
- **Adaptación al problema:** los datos se expresan como distancia (cm), porcentaje aproximado de llenado y alerta para decidir cuándo compactar o vaciar el recipiente de papel seco. La solución no activa un mecanismo de compactación motorizado.
- **Validación real:** **pendiente** de que el equipo compile en Arduino IDE, verifique cada función en el montaje y anote la versión instalada; no declarar que un código generado ha sido probado si aún no lo ha sido.

### 3.3. Otros usos de IA
Si se utilizan posteriormente Claude, Copilot, software de generación de imágenes, prompts para planos o asistentes de programación, registrar aquí la herramienta, fecha, propósito, parte generada, adaptación y prueba realizada. La guía permite IA **si se declara y se comprende**.

## 4. Responsabilidad y revisión
El equipo debe verificar conexiones, probar el firmware sobre ESP8266 y corregir los errores observados, completar fichas y versiones, medir el montaje y documentar resultados **reales**. La IA no sustituye estas pruebas. Ningún dato de ejemplo debe presentarse como resultado experimental.

**Checklist final de atribución:** dependencias identificadas y versionadas; enlaces revisados; fragmentos externos declarados; IA declarada con uso, adaptación y comprensión; código real revisado por integrantes.
