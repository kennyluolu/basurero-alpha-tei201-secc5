# Integración eléctrica propuesta: dos motores 28BYJ-48 + ULN2003 con ESP8266

**Estado 22-11-2026:** análisis de compatibilidad **PRELIMINAR**. No es un esquema de circuito validado ni un pinout definitivo.

## Arquitectura propuesta

- Microcontrolador principal **NodeMCU ESP8266** (reemplazó al ESP32 dañado).
- Dos motores paso a paso **28BYJ-48**, **un módulo ULN2003 por motor**.
- Placa compactadora de MDF accionada por dos piñones y dos cremalleras verticales.
- Sensor HC-SR04, dashboard de llenado con almacenamiento LittleFS.
- Sensores de fin de carrera superior e inferior, enclavamiento de tapa, parada independiente del software y protección eléctrica.

## Restricción crítica de GPIO

El **pinout del prototipo Alpha** ya usa D1 (TRIG), D2 (ECHO), D5 (LED verde), D6 (LED azul) y D7 (LED rojo). Cada ULN2003 requiere **4 entradas** para controlar un 28BYJ-48 unipolar; **dos módulos suman ocho entradas**, más sensor y protecciones. **No conectar ambos drivers a pines sin un rediseño de asignación**: el ESP8266 tiene pines de arranque y pines compartidos con otros periféricos que no pueden usarse indistintamente.

### Opciones técnicas a estudiar (no compradas)

1. **Expansor GPIO I²C, por ejemplo MCP23017:** permite controlar múltiples señales con dos líneas I²C, pero obliga a rediseñar pines existentes y verificar temporización, niveles lógicos, corriente de salida (señales, no motores) y librería empleada.
2. **Registro(s) de desplazamiento 74HC595 con electrónica adecuada:** reduce GPIO necesarios para manejar líneas IN1–IN4 de dos ULN2003. Diseñar el circuito de lógica, temporización, habilitación segura y compatibilidad a 3,3 V antes de seleccionarlo.
3. **Reducir funciones secundarias** (LED azul, etc.) no elimina por sí solo la necesidad de analizar GPIO, arranque y señales de seguridad.

**Ninguna opción queda seleccionada hasta conocer los componentes disponibles y medir el circuito físico.** Si se elige un expansor, declarar la dependencia de software correspondiente en `FUENTES.md` y actualizar el firmware y el esquemático.

## Energía y señales

- Cada motor debe alimentarse desde una **fuente regulada adecuada a su versión exacta**, separada de los GPIO del ESP8266. Dimensionar corriente de ambos motores simultáneos y márgenes. **No alimentar motores desde Dn ni desde el regulador de 3,3 V del NodeMCU**.
- Verificar que las **entradas del módulo ULN2003** reconozcan de manera confiable los 3,3 V del controlador. Los módulos comerciales pueden variar; hacer prueba eléctrica real.
- Compartir referencia de masa entre control y módulo **según el diseño de alimentación**; incluir fusible, desconexión y manejo ordenado de cables.
- Mantener divisor o desplazador de nivel en `ECHO` del HC-SR04: no enviar 5 V directo al ESP8266.

## Protección y prueba incremental (obligatoria antes de uso)

1. Preparar un **esquemático real** y una lista de conexiones consistente con el firmware instalado.
2. Comprobar con multímetro las tensiones sin motor y luego un controlador con **motor desconectado de la placa compactadora**.
3. Probar **cada motor por separado** y registrar giro, ruido, temperatura, consumo y pérdidas de pasos.
4. Probar ambos motores al mismo tiempo sin carga, observar desalineación y corregirla.
5. Verificar topes físicos, **finales de carrera**, tapa enclavada y parada **antes** de poner la placa en movimiento.
6. Ensayar con cargas de papel **pequeñas y crecientes**, sin manos dentro del volumen de cierre. Si existe sobreesfuerzo o bloqueo, cortar energía y revisar; no dejar un motor paso a paso energizado contra tope.
7. Documentar resultados reales (incluidos ensayos fallidos), fotografías de montaje y esquema final. No afirmar fuerza ni compactación lograda sin mediciones.

## Estado de firmware

- `firmware/EcoCompacta/EcoCompacta.ino` mide nivel y registra histórico. **No contiene control de motores**.
- Se propondrá un archivo o módulo de control solo cuando el pinout, actuadores, seguridad y mecánica estén definidos; no reutilizar conexiones de ESP32.

## Enlaces del proyecto

- [Mecanismo y dimensiones nominales](../diseno-3d/MECANISMO_PINON_CREMALLERA.md)
- [Pinout actual de monitoreo](ESQUEMA_PRELIMINAR_FINAL.md)
- [Lista de materiales](BOM_FINAL.csv)
