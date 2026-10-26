# Costos reales y materiales del prototipo Alpha

## Gasto confirmado
**Total desembolsado por el equipo: $40.000 CLP.** El desglose por artículo no está disponible; no se asignan precios individuales inventados. Este total corresponde al avance electrónico realizado, no al futuro sistema de compactación.

## Materiales y procedencia
| Material | Procedencia | Observación |
|---|---|---|
| Sensor ultrasónico HC-SR04 | Préstamo del DEC | No contabilizado como compra |
| Servomotor SG90 | Préstamo del DEC | No se ha validado para compactar papel; probablemente insuficiente para la fuerza requerida |
| ESP8266 | Comprado por el equipo | Sustituyó al ESP32 en la versión funcional |
| Cables Dupont macho-macho | Comprados por el equipo | Conexiones en protoboard |
| Cables Dupont macho-hembra | Comprados por el equipo | Conexiones entre módulos |
| Cable USB-C | Comprado por el equipo | No sirvió para conectar la placa ESP8266 utilizada |
| Cable USB compatible con ESP8266 | Comprado por el equipo | Cable finalmente utilizado; **tipo de conector por confirmar** |
| Otros materiales electrónicos utilizados (protoboard, LED, resistencias, etc.) | Comprados según relato del equipo | Cantidades y costos individuales por confirmar |

**Importante:** $40.000 es un gasto real total comunicado por el equipo, no una cotización ni la suma de valores unitarios estimados. El sensor y el servo son préstamos, no propiedad comprada. Si se devuelven al DEC, deberá considerarse su reemplazo o un nuevo préstamo.

## Iteración de conectividad física
Se compró inicialmente un cable USB-C, que no resultó compatible con la placa ESP8266 empleada. Se adquirió/utilizó después un cable USB de conector distinto que permitió trabajar con esa placa. Confirmar si era Micro-USB antes de publicar una especificación exacta.

## Presupuesto siguiente etapa
El mecanismo de compactación, motor, transmisión, guías, fuente y protecciones **no están incluidos en los $40.000** y siguen pendientes de diseño y cotización. La selección de motor debe basarse en la fuerza necesaria, no en el precio solamente.
