# EcoCompacta — Basurero Compactador Inteligente
**TEI201 · Taller de Diseño en Ingeniería · UAI · Sección 5**

## Entrega final · viernes 27 de noviembre de 2026
**Estado:** proyecto en construcción y documentación en revisión. **No presentar como concluido ni como compactación automatizada hasta probarlo.**

### Acceso rápido
- **[Documento central de entrega final](entrega_final/README.md)**
- [Cronograma de la semana](entrega_final/CRONOGRAMA.md)
- [Materiales y montaje](entrega_final/MATERIALES_Y_MONTAJE.md)
- [Protocolo y registro de pruebas](entrega_final/PROTOCOLO_PRUEBAS.md)
- [Matriz de rúbrica](entrega_final/MATRIZ_RUBRICA.md)
- [Guion de exposición](entrega_final/PRESENTACION.md)
- [Firmware ESP8266 de preparación final](software/EcoCompacta_Final_ESP8266/EcoCompacta_Final_ESP8266.ino)

### Evolución del prototipo
1. **Alpha:** sensado ultrasónico HC-SR04, LEDs y portal web local desde un NodeMCU ESP8266. Se utilizó ESP8266 tras fallar la placa ESP32.
2. **Versión final en proceso:** aprovechar madera para estructura y placa de compactación, revisar diseño mecánico, registrar reducción de altura/volumen en papel seco y validar el monitoreo.
3. **Precisión:** el SG90 antiguo no ha demostrado compactación; no declarar accionamiento automático si la prueba se hace manualmente.

### Estado de las funciones
| Función | Estado conocido |
|---|---|
| Punto de acceso Wi-Fi y panel web | Probado en Alpha; volver a validar montaje final |
| Sensor de nivel | Parcial en Alpha; recalibrar y medir error |
| Indicadores LED | Verde/rojo implementados; azul pendiente de revisión |
| Compactación física | Pendiente de prueba con la estructura final |
| Automatización de compactación | No demostrada |
| Resultados cuantitativos | Pendientes de ensayo |

> **Importante:** los planos acotados, la rúbrica y el diseño físico definitivo todavía están pendientes de incorporar. Ninguna tabla incluida aquí contiene resultados inventados.

### Referencias al prototipo anterior
- [Código Alpha original](software/BasureroAlpha_ESP8266/BasureroAlpha_ESP8266.ino)
- [Diseño Fusion 360 previo](diseno_3d/Basurero%20Compactador.f3d)
- [Documentación de Alpha](documentacion/ALCANCE_Y_PENDIENTES.md)

**Integrantes registrados en la etapa Alpha:** Kenny Luo, Lucas Soto, Vicente Lechuga, Agustín Ly, Benjamín Brito. Validar roles y participantes finales.

*Archivo actualizado para revisión del equipo. El historial de la versión Alpha se conserva en la rama `main`.*
