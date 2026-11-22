# Software — firmware histórico y final

## Firmware de referencia

- **Alpha original:** [BasureroAlpha_ESP8266.ino](BasureroAlpha_ESP8266/BasureroAlpha_ESP8266.ino). Usa el AP `Basurero-Alpha` y la página local `192.168.4.1`. Se conserva como registro de la iteración anterior; no sobrescribirlo.

## Archivo canónico para la entrega

- **Firmware de monitoreo actual:** [EcoCompacta.ino](../firmware/EcoCompacta/EcoCompacta.ino).
- **Instrucciones y validaciones pendientes:** [README del firmware](../firmware/README.md).

La carpeta `EcoCompacta_Final_ESP8266/` conserva una versión previa de preparación. No contiene el histórico LittleFS que se añadió después; se mantiene para trazabilidad y no debe confundirse con el firmware canónico.

**Estado:** el firmware canónico aún requiere compilación y validación en la placa física. Ninguna de estas versiones controla la compactación mecánica.