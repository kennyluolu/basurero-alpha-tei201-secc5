# Basurero Alpha | Papelero inteligente para oficinas
**TEI201 — Taller de Diseño en Ingeniería | Universidad Adolfo Ibáñez | Sección 5 | Prototipo Basurero Alpha**

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
- **Servomotor SG90:** prestado por el DEC y conectado al protoboard durante el armado, pero **no se puso en funcionamiento** porque no se contaba con una fuente externa adecuada para alimentarlo sin arriesgar la placa ESP8266. Se había previsto para accionar la compactación, que **no se realizó ni validó**.
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

**Código:** se conserva el archivo `.ino` aportado por el equipo. Su presencia en el repositorio no equivale a una verificación de compilación o funcionamiento integral; comprobar conexiones y lecturas en el montaje final.

## Evidencias y trazabilidad
- [Registro de la demostración y evidencias confirmadas](documentacion/EVIDENCIAS_DEMOSTRACION.md): video mostrado al profesor y fotografía del montaje, **pendientes de publicar como archivos originales**.
- [Iteraciones y validación](documentacion/ITERACIONES_Y_VALIDACION.md): problemas reales y pruebas pendientes.
- [Costos reales](documentacion/COSTOS_REALES_ALPHA.md): **$40.000 CLP** gastados; HC-SR04 y SG90 prestados por el DEC.
- [Plan de compactación](documentacion/PLAN_COMPACTACION_Y_PRESUPUESTO.md): propuesta futura, **no implementada**.

## Diseño Fusion 360
El archivo original editable `diseno_3d/Basurero Compactador.f3d` está incluido en este repositorio. La presentación del Avance #2 también documenta dimensiones propuestas de 21 × 17 × 31 cm; confirmar medidas del modelo antes de fabricar.

## Equipo y roles

| Integrante | Rol en el proyecto |
|---|---|
| **Kenny Luo** | Desarrollo de software con asistencia de IA, configuración del ESP8266, integración y armado electrónico, diseño 3D en Fusion 360 y gestión del repositorio GitHub. |
| **Lucas Soto** | Presentación del proyecto y apoyo en el montaje del protoboard. |
| **Vicente Lechuga** | Coordinación de materiales y presupuesto. |
| **Agustín Ly** | Evaluación del prototipo y planificación de pruebas. |
| **Benjamín Brito** | Documentación técnica y revisión del diseño. |

Los roles describen la distribución de responsabilidades del equipo, no certifican la ejecución individual de cada tarea.

## Contexto del avance y ODS
El equipo presentó **EcoCompacta — Avance #2** como propuesta de compactador doméstico. La documentación de esa etapa describe ESP32 y servo SG90, mientras que el prototipo electrónico posterior usa **ESP8266** y no ha demostrado compactación. Son etapas distintas, no resultados intercambiables. Se vincula conceptualmente con **ODS 11** (Ciudades y comunidades sostenibles) y **ODS 12** (Producción y consumo responsables), sin afirmar reducciones cuantificadas de residuos o transporte.

Los docentes vieron una demostración y recibieron la explicación del proyecto; **no se registraron aquí resultados formales de pruebas con usuarios**. El plan de compactación y presupuesto se detalla en `documentacion/PLAN_COMPACTACION_Y_PRESUPUESTO.md`.

## Licencia

El repositorio se distribuye bajo la [licencia MIT](LICENSE). Permite usar, modificar y redistribuir el contenido cubierto por esta licencia, conservando el aviso de derechos de autor y el texto de la licencia. Los componentes de terceros mantienen sus propias licencias.

## Contexto académico

Este proyecto es desarrollado como parte del curso **TEI201 — Taller de Diseño en Ingeniería**, de la **Facultad de Ingeniería y Ciencias de la Universidad Adolfo Ibáñez**.

Esta declaración identifica el contexto académico y no constituye una licencia de reutilización de software.
