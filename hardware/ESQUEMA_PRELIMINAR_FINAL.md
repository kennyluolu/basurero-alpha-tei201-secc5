# Esquemático preliminar / pinout para adaptar en Fritzing, KiCad o EasyEDA

> **NO es todavía el esquemático final verificado.** Esta tabla proviene del código Alpha y del firmware propuesto. Contrastar con montaje real, fotografiar y exportar **esquemático eléctrico final PDF** antes de presentar.

| Equipo | Señal | NodeMCU ESP8266 | Observaciones |
|---|---|---|---|
| HC-SR04 | TRIG | D1 / GPIO5 | Salida de disparo |
| HC-SR04 | ECHO | D2 / GPIO4 | **Requiere adaptación de 5 V a 3,3 V** |
| HC-SR04 | VCC | 5 V regulados conforme al módulo | No conectar VCC del sensor al GPIO |
| HC-SR04 | GND | GND común | Cableado de masa |
| LED verde | Ánodo a través de resistencia | D5 / GPIO14 | Cátodo a GND |
| LED azul | Ánodo a través de resistencia | D6 / GPIO12 | Cátodo a GND; **verificar fallo Alpha** |
| LED rojo | Ánodo a través de resistencia | D7 / GPIO13 | Cátodo a GND |
| NodeMCU | Alimentación | Puerto USB | Fuente de 5 V regulada, según placa |

## Divisor de tensión ilustrativo en ECHO (verificar valores reales)
```
ECHO HC-SR04 (~5 V) -- R1=1 kΩ --+--> D2 ESP8266 (~3,33 V)
                                 |
                               R2=2 kΩ
                                 |
                                GND
```
Aplicando `Vout = 5V × R2/(R1+R2)`, con esos valores se obtiene aproximadamente 3,33 V **nominales**; usar resistencias reales medidas y verificar con multímetro, tolerancia y referencia de masa. Los 1k/2k son valores de referencia del proyecto, **no una constatación del montaje actual**.

## Seguridad de la compactación
No hay motor conectado al firmware entregado. No dibujar un driver ni un pin para servo como “implementado” mientras no exista un circuito real. Si se añade motor, usar fuente apropiada, driver, limitadores de recorrido, enclavamiento de tapa, parada y protección de la zona de apriete, revisados por el equipo/docente.

## Entregables pendientes
- [ ] Captura o PDF del esquemático generado en software electrónico, con valores y polaridades definitivos.
- [ ] Fotos del interior: cables etiquetados, alimentación y acceso a reparación.
- [ ] Medidas verificadas de voltajes y valores de resistencias.
- [ ] Si hay otro sensor o actuador, actualizar firmware, tabla, BOM y gemelo 3D.
