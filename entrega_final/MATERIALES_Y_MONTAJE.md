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

Las cinco piezas originales y sus dimensiones informadas están en [MEDIDAS_MADERA_ANTES_DE_CORTE.md](../hardware/MEDIDAS_MADERA_ANTES_DE_CORTE.md). **No equivalen a medidas del papelero ya construido.**

## Materiales mecánicos sugeridos
- Tornillos, tuercas, escuadras y adhesivo apto para madera.
- Placa compactadora rígida, ligeramente menor al interior, con bordes sin aristas.
- Dos guías laterales o correderas, evitando que la placa gire o se incline.
- Para accionamiento manual: tornillo de avance/varilla roscada con tuerca fijada o palanca controlada; verificar anclajes, estabilidad, bloqueo y que las manos queden fuera del área de apriete.
- Tapa firme con pestillo; elementos antideslizantes para la base y protección de bordes.
- Bolsas o contenedor interno extraíble, **si** no interfiere con la placa.

## Alternativa motorizada (solo si hay tiempo y seguridad)
Motorreductor o actuador lineal **dimensionado tras medir fuerza y carrera**, driver acorde con corriente de bloqueo, alimentación externa, fusible, interruptor de parada, finales de carrera y enclavamiento de tapa. Un GPIO del ESP8266 no puede alimentar un motor. No usar el servo SG90 como elemento de fuerza sin comprobación.

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
