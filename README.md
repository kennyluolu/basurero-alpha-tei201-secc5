# Basurero Alpha | Papelero inteligente para oficinas
**TEI201 — Universidad Adolfo Ibáñez | Sección 8 | Prototipo Alpha IoT**

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

**Código:** se conserva el archivo `.ino` aportado por el equipo. Su presencia en el repositorio no equivale a una verificación de compilación o funcionamiento integral; comprobar conexiones y lecturas en el montaje final.

## Diseño Fusion 360
El archivo original editable `diseno_3d/Basurero Compactador.f3d` está incluido en este repositorio. La presentación del Avance #2 también documenta dimensiones propuestas de 21 × 17 × 31 cm; confirmar medidas del modelo antes de fabricar.

## Equipo y contribuciones

**Contribuciones al prototipo documentadas por el equipo:**

| Integrante | Contribución realizada |
|---|---|
| **Kenny Luo** | Desarrollo e integración del código con asistencia de IA; configuración de NodeMCU ESP8266; armado y pruebas del prototipo electrónico y protoboard; diseño del modelo en Fusion 360; organización y documentación del repositorio GitHub con asistencia de IA. |
| **Lucas Soto** | Apoyo en la preparación del PowerPoint y colaboración en el armado del protoboard. |

**Otros integrantes:** Vicente Lechuga, Agustín Ly y Benjamín Brito. No se han definido ni verificado contribuciones individuales para este registro. Como **propuesta de responsabilidades para la siguiente etapa**, pueden distribuirse así, sujeto a aceptación y ejecución: Vicente — materiales y presupuesto; Agustín — pruebas y registro de resultados; Benjamín — documentación y revisión de seguridad. Estas tareas **no se presentan como trabajo ya realizado**.

No existieron roles formales asignados durante el avance documentado.

## Contexto del avance y ODS
El equipo presentó **EcoCompacta — Avance #2** como propuesta de compactador doméstico. La documentación de esa etapa describe ESP32 y servo SG90, mientras que el prototipo electrónico posterior usa **ESP8266** y no ha demostrado compactación. Son etapas distintas, no resultados intercambiables. Se vincula conceptualmente con **ODS 11** (Ciudades y comunidades sostenibles) y **ODS 12** (Producción y consumo responsables), sin afirmar reducciones cuantificadas de residuos o transporte.

Los docentes vieron una demostración y recibieron la explicación del proyecto; **no se registraron aquí resultados formales de pruebas con usuarios**. El plan de compactación y presupuesto se detalla en `documentacion/PLAN_COMPACTACION_Y_PRESUPUESTO.md`.

## Contexto académico

Este proyecto es desarrollado como parte del curso **TEI201 — Taller de Diseño en Ingeniería**, de la **Facultad de Ingeniería y Ciencias de la Universidad Adolfo Ibáñez**.

Esta declaración identifica el contexto académico y no constituye una licencia de reutilización de software.
