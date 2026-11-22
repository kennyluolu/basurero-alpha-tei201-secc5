# EcoCompacta — Carpeta central de entrega final

**Proyecto:** basurero para papel seco con sensor de llenado y placa compactadora.  
**Curso:** TEI201, UAI, sección 5.  
**Fecha de preparación:** 22 de noviembre de 2026. **Fecha comunicada por el equipo:** viernes 27 de noviembre. **La guía encontrada indica:** 23 de noviembre. Confirmar fecha aplicable.

## Objetivo y ciclo IoT
Medir el nivel de llenado del papelero con HC-SR04, procesar lecturas en ESP8266, **almacenar un histórico de forma persistente**, mostrar datos actuales e históricos en un dashboard Wi-Fi local y generar alertas para decidir cuándo compactar o vaciar el papel seco.

**La compactación es un subsistema mecánico independiente del firmware actual.** La estructura prevista usa madera reutilizada; su método de accionamiento definitivo se elegirá según fuerza y medidas. No presentar como automática una compactación manual.

## Requisitos de la rúbrica oficial
| Dimensión | Peso |
|---|---:|
| Software: captura, persistencia, dashboard, información, calidad | 30 % |
| Hardware: componentes, esquemático, BOM, montaje, reparación | 30 % |
| Diseño 3D: gemelo, Fusion, encapsulado, planos y renders | 20 % |
| Testing: protocolo, datos, fallas y validación del problema | 10 % |
| GitHub: estructura, trazabilidad, fuentes y archivos | 5 % |
| Presentación en vivo | 5 % |

Ver [matriz detallada contra pauta](MATRIZ_RUBRICA.md).

## Entregables y estado a 22/11
- **Software:** [código de propuesta ESP8266 + LittleFS](../firmware/EcoCompacta/EcoCompacta.ino), [guía de uso](../firmware/README.md). **NO compilado ni validado en placa final.**
- **Hardware:** [pinout preliminar](../hardware/ESQUEMA_PRELIMINAR_FINAL.md), [BOM por completar](../hardware/BOM_FINAL.csv). Se necesitan diagrama real, costos y 3 fotos.
- **Diseño:** [Fusion 360 de Alpha](../diseno_3d/Basurero%20Compactador.f3d). Actualizar con dimensiones reales, componentes, accesos, PDF de planos y renders.
- **Testing:** [protocolo](PROTOCOLO_PRUEBAS.md), [CSV de resultados por completar](datos_pruebas.csv).
- **Documentación de fuentes/IA:** [FUENTES.md](../FUENTES.md) creado, verificar versiones y datos.
- **Presentación:** [guion](PRESENTACION.md) y [cronograma](CRONOGRAMA.md).

## Foco de validación
1. Sensor mide distancia real y establece alerta con umbral.
2. Las lecturas persisten en LittleFS **después de reiniciar**.
3. Dashboard muestra histórico y actualización actual, con información para decidir.
4. Estructura se abre para acceder a los componentes sin destruirse.
5. Se documenta al menos una falla real con explicación y corrección.
6. Se demuestra el sistema **en vivo**; video es evidencia de apoyo, no sustituto.

## Faltantes requeridos antes de entregar
Planos del equipo con cotas, modelo final, fotografías reales, circuito final, pruebas cuantitativas, informe, diapositivas y confirmación de fecha de evaluación.

**Principio:** no afirmar que una función o métrica está demostrada hasta que se ensaye.
