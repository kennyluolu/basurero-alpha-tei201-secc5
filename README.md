# Basurero Alpha | Papelero inteligente para oficinas
**TEI201 — Universidad Adolfo Ibáñez | Prototipo Alpha IoT**

> **Estado:** prototipo electrónico parcialmente funcional; compactación mecánica pendiente de integración y validación.

## Objetivo
Desarrollar un **papelero de oficina para residuos de papel** que informe su nivel de llenado y permita estudiar una futura compactación del papel. Se restringe el alcance a **papel seco** para simplificar el mecanismo y evitar residuos húmedos o peligrosos.

## Problema
Los papeleros de oficina se llenan con papel de gran volumen y baja densidad. El proyecto busca facilitar la supervisión del llenado y explorar cómo aprovechar mejor el volumen disponible.

## Arquitectura Alpha
`HC-SR04 → NodeMCU ESP8266 → LED verde/rojo + servidor web local (Wi-Fi AP)`

- **Microcontrolador actual:** NodeMCU **ESP8266** (se probó ESP32 anteriormente, pero no se consiguió la operación esperada).
- **Sensor:** HC-SR04 ultrasónico, montado para medir la distancia al contenido.
- **Visualización:** página local en `http://192.168.4.1` al conectarse al punto de acceso `Basurero-Alpha`.
- **LED verde:** nivel inferior al umbral; **LED rojo:** alerta a partir del 80 %.
- **LED azul:** considerado en el prototipo, pero su funcionamiento no quedó validado.
- **Compactación:** SG90 mencionado como concepto/maqueta; **no integrado**. No se afirma que pueda compactar papel real.
- **Profundidad de referencia en firmware:** 30 cm, **ajustable** tras medir el contenedor físico.

## Estado de validación
| Función | Estado |
|---|---|
| Punto de acceso Wi-Fi y web local | Probado |
| Lectura de nivel ultrasónico | Parcial: lecturas válidas e intermitencias |
| Indicadores verde y rojo | Implementados; verificar en montaje final |
| LED azul | No validado |
| Compactación mecánica | Pendiente |
| Pruebas cuantitativas con usuarios | Pendientes |

## Estructura
- `hardware/`: componentes, conexiones y advertencias eléctricas.
- `software/`: firmware para ESP8266 e instrucciones.
- `diseno_3d/`: descripción del modelo Fusion 360 y enlace pendiente de confirmar.
- `iteraciones/`: decisiones y cambios del prototipo.
- `testing/`: plan de pruebas y registro de resultados.
- `documentacion/`: alcance, pendientes y fuentes.

## Uso rápido
1. Instalar soporte **ESP8266** en Arduino IDE.
2. Abrir `software/BasureroAlpha_ESP8266/BasureroAlpha_ESP8266.ino`.
3. Verificar conexiones y divisor de tensión en ECHO del HC-SR04.
4. Cargar el programa en la NodeMCU.
5. Conectarse al Wi-Fi `Basurero-Alpha` (clave de demostración: `basurero123`).
6. Abrir `http://192.168.4.1`.

**Aviso:** este firmware es una reconstrucción documentada de la última configuración conocida, **no una copia byte a byte verificada del último sketch original**. Verificar pines, lecturas y funcionamiento en hardware antes de presentar como resultado definitivo.

## Diseño Fusion 360
Ver `diseno_3d/README.md`. Se identificó el archivo de referencia `Basurero_FINAL_Interior_Detallado_Componentes_Separados.step`, pero **no se dispone aquí del enlace compartido ni del archivo STEP**. Deben añadirse sin inventarlos.

## Equipo
Completar integrantes y roles reales antes de entrega. Repositorio preparado para colaboración.

## Referencia de organización
Estructura inspirada en el repositorio académico `jgarcia-dec/sensor-calidad-suelo-TEI201`, sin copiar su implementación.
