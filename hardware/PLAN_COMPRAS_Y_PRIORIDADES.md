# Plan de compras y decisión de mecanismo — 22 de noviembre de 2026

**Estado comunicado por el equipo:** todavía **NO dispone** de los componentes del accionamiento que describió: **2 motores 28BYJ-48, 2 módulos ULN2003, 2 piñones y 2 cremalleras**. No se han comprado ni instalado. El inventario usado en **Alpha** (ESP8266, HC-SR04, LEDs, protoboard y cables) corresponde a una etapa anterior; **reconfirmar que está físicamente disponible ahora**. La madera original sí fue utilizada para formar el papelero, según el equipo.

**Plazo comunicado:** presentación prevista para viernes 27/11/2026; la guía Avance #3 indica 23/11/2026. Confirmar fecha docente.

## Prioridad y riesgo

1. **Primero:** comprobar disponibilidad de ESP8266 y HC-SR04; medir caja real, verificar firmware, persistencia de histórico en LittleFS y dashboard en vivo.
2. **Segundo:** construir/proteger placa guiada y tapa desmontable; medir la fuerza necesaria para comprimir una muestra de papel seco.
3. **Tercero:** recién entonces definir motorización. Un 28BYJ-48 puede mover mecanismos livianos pero **no se ha demostrado que pueda ejercer fuerza suficiente para compactación**. No comprar dos kits suponiendo que harán la fuerza necesaria.
4. **Plan de respaldo técnico:** si la automatización no se alcanza a integrar con seguridad, presentar **compactación manual real y sensado inteligente automático**, distinguiendo limitación de la meta inicial. No declarar compactación automática.

## Cotizaciones de referencia verificadas en web (NO compras realizadas)

| Alternativa | Referencia de precio público | Evaluación |
|---|---|---|
| Kit 28BYJ-48 5V + ULN2003 | Arduino Chile, **$2.990 CLP por kit** — https://arduino.cl/products/motor-paso-a-paso-28byj-48-5v-driver-uln2003 | Económico para ensayo de movimiento, **no garantía de fuerza de compactación**. Hacen falta **dos**, además de piñones/cremalleras, fuente, expansión de GPIO y protecciones |
| Actuador lineal 12 V, carrera 100 mm | VEVOR en Líder, **$70.990 CLP** (oferta publicada) — https://www.lider.cl/ip/herramientas/actuador-lineal-vevor-12v-100mm-con-carga-1500n-y-velocidad-de-150-mm-s/00019798881812 | Más apropiado para fuerza lineal **si** se confirma fuerza real, carrera, longitud retraída, disponibilidad, fuente y montaje seguro. 100 mm de carrera **no equivale** a los 330 mm de altura del recipiente |
| Alternativa sin motorización | Madera ya reutilizada + guías/topes + placa y mecanismo manual con manos fuera del volumen de aplastamiento | Viable como demostración del **mecanismo físico** si se construye y prueba; no cumple un objetivo de automatización del movimiento |

**Nota:** precios son referencias visibles al consultar sitios, no cotizaciones oficiales, no incluyen envíos ni accesorios; verificar stock y retiro a tiempo. No comprar componentes de potencia sin dimensionar fuerza y fuente.

## Compra imprescindible según alternativa finalmente elegida

### Para probar doble piñón-cremallera con dos motores de bajo torque
- [ ] 2 × kit 28BYJ-48 con ULN2003 **de la misma tensión**.
- [ ] 2 × piñones compatibles con ejes, 2 × cremalleras de igual módulo/paso y carrera útil.
- [ ] Soportes de ejes/piñones y dos guías para que el motor no absorba las fuerzas laterales.
- [ ] Fuente regulada para ambos motores, dimensionada conforme a las especificaciones **reales**.
- [ ] Solución de **8 señales** para drivers compatible con ESP8266 y su sensor (expansión GPIO o rediseño de control).
- [ ] Finales de carrera, tapa enclavada, parada, protección de dedos y fusible.
- [ ] Acceso a impresora 3D o servicio de fabricación de piezas.

### Si se elige un actuador lineal más potente
- [ ] Actuador con carrera suficiente **para el recorrido real**, fuerza suficiente medida y dimensiones que quepan en el gabinete.
- [ ] Fuente de 12 V, driver/puente H adecuado a la corriente, fusible y apagado seguro.
- [ ] Guías, topes, interruptores y cubierta enclavada; considerar fuerzas de aplastamiento elevadas.

### En todos los casos (hardware IoT)
- [ ] NodeMCU ESP8266 disponible y funcional (confirmar).
- [ ] HC-SR04 disponible y funcional (confirmar).
- [ ] Resistencias/level shifter para ECHO a 3,3 V, LEDs y conductores.
- [ ] Cable USB/energía, soporte desmontable para electrónica y esquema eléctrico.
- [ ] Fotos del montaje, registro de compras reales y archivo Fusion 360 actualizado.

## Qué decidir antes de pagar
- Presupuesto máximo real (CLP).
- Tiempo para obtener los componentes antes del viernes.
- Medidas **interiores** del recipiente tras cortar madera y espesor, para saber carrera máxima.
- Fuerza de compresión aproximada y volumen de papel de la demo.
- Confirmación del inventario electrónico del prototipo Alpha.

**La BOM en `hardware/BOM_FINAL.csv` distingue lo usado en Alpha, lo disponible ahora por confirmar y lo no adquirido. No consignar como gasto real una cotización.**
