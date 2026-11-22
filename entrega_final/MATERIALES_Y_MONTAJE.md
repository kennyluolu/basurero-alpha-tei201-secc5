# Materiales y montaje (por confirmar con planos)

> No es una cotización ni una instrucción de motorizar sin pruebas. Los valores de compra se verificarán con los proveedores y el inventario real.

## Inventario conocido
| Material | Estado actual | Uso |
|---|---|---|
| Cinco piezas de madera antes de cortar | Medidas originales registradas; espesor, cortes y función por confirmar | Cuerpo, refuerzos y posible placa |
| NodeMCU ESP8266 | Usado en Alpha | Sensado e interfaz |
| HC-SR04 | Usado en Alpha | Nivel de llenado |
| LEDs + resistencias | Usados parcialmente en Alpha | Estado del llenado |
| Cables/protoboard/USB | Usados en Alpha | Prototipado y carga de firmware |
| Servo SG90 | Prestado en Alpha, sin ensayo de compactación | **No asumir** que sirve para comprimir |
| Modelo de Fusion 360 | Existe, validar dimensiones | Plano de referencia |
| Motores 28BYJ-48 y módulos ULN2003 | **2 + 2 propuestos; disponibilidad no confirmada** | Tracción de cremalleras con piñones |
| Piñones y cremalleras | **2 + 2 propuestos** | Transmisión lateral vertical |
| Placa MDF | Propuesta; medidas por medir | Compresión del papel |

Las cinco piezas originales y sus dimensiones informadas están en [MEDIDAS_MADERA_ANTES_DE_CORTE.md](../hardware/MEDIDAS_MADERA_ANTES_DE_CORTE.md). **No equivalen a medidas del papelero ya construido.**

## Geometría nominal de la propuesta de estructura
- Planta de base cuadrada **25 × 25 cm**, paredes laterales **25 × 33 cm**, tapa superior **25 × 25 cm** con abertura central.
- **No** se ha aclarado si las dimensiones de 25 cm son interiores o exteriores. El espesor y las dimensiones definitivas de cada tabla cortada siguen pendientes.
- Sistema lateral de **dos piñones y dos cremalleras verticales** unido a una placa de **MDF**; **dos motores paso a paso 28BYJ-48 y dos módulos ULN2003**, controlados en una futura integración desde el **ESP8266** (no ESP32).
- Se documentó el diseño en [MECANISMO_PINON_CREMALLERA.md](../diseno-3d/MECANISMO_PINON_CREMALLERA.md) y las restricciones eléctricas en [INTEGRACION_28BYJ48_ESP8266.md](../hardware/INTEGRACION_28BYJ48_ESP8266.md).

**El mecanismo no está validado:** hay que medir capacidad de compresión real, obtener piñones/cremalleras compatibles, incluir guías, límites de carrera, enclavamiento de tapa y alimentación protegida. El firmware actual no contiene control de motores.

## Materiales mecánicos sugeridos
- Tornillos, tuercas, escuadras y adhesivo apto para madera.
- Placa compactadora rígida, ligeramente menor al interior, con bordes sin aristas.
- Dos guías laterales o correderas, evitando que la placa gire o se incline.
- Para accionamiento manual: tornillo de avance/varilla roscada con tuerca fijada o palanca controlada; verificar anclajes, estabilidad, bloqueo y que las manos queden fuera del área de apriete.
- Tapa firme con pestillo; elementos antideslizantes para la base y protección de bordes.
- Bolsas o contenedor interno extraíble, **si** no interfiere con la placa.

## Alternativa motorizada (solo si hay tiempo y seguridad)
**La opción priorizada por el equipo es la doble cremallera con dos 28BYJ-48**. Debe comprobarse antes que disponen de torque suficiente (un motor paso a paso pequeño puede perder pasos ante la carga), que la mecánica no se atasca y que hay GPIO disponibles para los dos ULN2003 (8 entradas). Podría requerir un expansor de E/S o alternativa electrónica y **rediseño completo del pinout**. Si falla esta opción, estudiar motorreductor/actuador lineal **dimensionado por fuerza y carrera** o mecanismo manual claramente declarado. Fuente de motores externa, driver, fusible, parada, finales de carrera y enclavamiento de tapa son necesarios para motorizar. No usar SG90 para compactación sin pruebas.

## Seguridad eléctrica
- El ESP8266 funciona con GPIO de 3,3 V.
- ECHO del HC-SR04 alimentado a 5 V requiere conversión segura a 3,3 V.
- LED con resistencias limitadoras; comprobar GND común cuando corresponda.
- No dejar conexiones de protoboard expuestas a partes móviles ni materiales húmedos.
- Desconectar energía antes de ajustes mecánicos y eléctricos.
- Documentar alimentación y prueba de protección antes de cualquier motor.

## Medidas a completar del plano físico
| Parámetro | Dato |
|---|---|
| Ancho interior útil | Pendiente |
| Fondo interior útil | Pendiente |
| Altura interior útil | Pendiente |
| Espesor de madera | Pendiente |
| Dimensiones de placa | Pendiente |
| Recorrido máximo | Pendiente |
| Ubicación de sensor y obstáculos | Pendiente |
| Distancia sensor → fondo vacío | Pendiente |
| Altura de salida del compactador | Pendiente |

## Lista de compra
Se completará **solo** cuando estén las medidas y el mecanismo decidido. Separar piezas reutilizadas, prestadas y compradas y guardar comprobantes.
