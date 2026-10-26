# Conexiones del prototipo electrónico actual (ESP8266)

Fuente: archivo original `software/BasureroAlpha_ESP8266/BasureroAlpha_ESP8266.ino`. **No usar el esquema de pines del ESP32 del PPT antiguo**, que quedó desactualizado tras el cambio de placa.

| Dispositivo | Señal | NodeMCU ESP8266 |
|---|---|---|
| HC-SR04 | TRIG | D1 (GPIO5) |
| HC-SR04 | ECHO | D2 (GPIO4), **mediante divisor de tensión de 5 V a 3,3 V** |
| LED verde | Control | D5 (GPIO14) |
| LED azul | Control | D6 (GPIO12) |
| LED rojo | Control | D7 (GPIO13) |
| HC-SR04 | Alimentación | 5 V según especificación del módulo; tierra común |
| NodeMCU | Alimentación/programación | Cable USB compatible |

**Seguridad eléctrica:** no conectar ECHO de 5 V directamente al ESP8266 (GPIO de 3,3 V). Confirmar divisor y cableado reales antes de encender. Cada LED debe llevar resistencia limitadora adecuada. El servo SG90 **no figura conectado en el código original**: no asignarle un pin inventado. No alimentar motores desde GPIO.

## Funcionamiento programado
- Distancia válida: 2 a 30 cm; si no hay eco, el programa muestra «Sin lectura válida».
- Cálculo: `porcentaje = limitar((30 - distancia)/30 * 100, 0, 100)`.
- Verde: menos de 50%; azul: desde 50% y menos de 80%; rojo: 80% o más.
- Punto de acceso: `Basurero-Alpha`; panel en `192.168.4.1`; actualización HTML cada 2 s.
- El LED azul presentó una falla física; su presencia en el programa no significa que haya funcionado correctamente.

## Diagrama físico pendiente
Agregar fotografía nítida o esquema verificado del circuito real, con polaridad, resistencias, alimentación y conexión del divisor. Este documento es una **tabla de conexiones derivada del código**, no certifica por sí solo el cableado físico.
