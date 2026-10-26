# Plan preliminar de compactación y presupuesto

**Estado: propuesta, no montaje construido ni cotización de tiendas.** Objetivo: compactar **papel seco** en un contenedor pequeño, priorizando seguridad y costo, con una meta de gasto incremental idealmente inferior a **$100.000 CLP** (no garantizada).

## Mantener del prototipo
- NodeMCU **ESP8266**, HC-SR04, LED y panel web local. El LED azul debe repararse o declararse fuera de servicio.
- No reutilizar el pinout ni librerías del ESP32 mostrados en el PPT.
- El ESP8266 solo controla señales: **no alimentar motores directamente desde sus pines**.

## Alternativa mecánica a evaluar
1. Medir el contenedor y la carrera de la placa compactadora; comprobar cuánto se comprime una muestra de papel seco con una fuerza medida.
2. Evaluar **motorreductor de 12 V + tornillo de avance + placa guiada**, con acople mecánico, soporte rígido y un driver reversible dimensionado según la corriente de bloqueo del motor. Es una alternativa de estudio, no un diseño validado.
3. Considerar una opción **manual con tornillo** si la motorización segura excede el presupuesto; permite demostrar la compactación sin automatización.
4. Instalar **dos finales de carrera**, tapa enclavada, botón de parada, protección contra sobrecorriente y acceso a desconexión. Probar sin manos cerca del mecanismo.
5. Alimentar motor desde fuente independiente y conectar tierras en común con control adecuado. Verificar protección de ECHO 5 V → 3,3 V para ESP8266.

## Materiales por confirmar
| Ítem | Estado |
|---|---|
| ESP8266, HC-SR04, protoboard, cables, LED | Parte del prototipo electrónico |
| Recipiente, placa compactadora, guías, tornillo y soportes | Diseño y fabricación pendientes |
| Motorreductor 12 V y acople | **Por seleccionar tras medir fuerza** |
| Driver reversible, fuente, fusible | Dimensionamiento pendiente |
| Finales de carrera, enclavamiento de tapa, parada | Seguridad indispensable antes de motorizar |

## Presupuesto
La meta preliminar es gastar menos de $100.000 CLP adicionales reutilizando piezas existentes; **no hay cotización comprobada** ni selección definitiva de motor. Solicitar precios locales y revisar el costo total antes de comprar. Si la opción motorizada excede el límite, preferir la compactación manual demostrable.

## Criterios de validación futura
Registrar dimensiones, carga de papel, fuerza requerida, carrera, tiempo, fallas, consumo y activación de protecciones. No declarar compactación automática hasta demostrarla físicamente y con seguridad.
