# EcoCompacta | Entrega final TEI201

> **Estado del documento:** borrador de trabajo (22-11-2026). **Entrega y presentación previstas:** viernes 27-11-2026. Faltan rúbrica, instrucciones finales, planos medidos y pruebas del montaje. No presentar este documento como evidencia de funciones aún no demostradas.

## 1. Problema y propuesta
El papel de oficina limpio y seco ocupa volumen con baja densidad aparente. EcoCompacta busca medir el nivel de llenado de un recipiente y facilitar su compactación, maximizando el uso del volumen disponible. El alcance se restringe a **papel seco**: no usar vidrio, metal, líquidos, baterías ni residuos sanitarios.

## 2. Hardware y estado real
- **Controlador vigente:** NodeMCU ESP8266 (el ESP32 original se averió y fue sustituido).
- **Sensor:** ultrasónico HC-SR04, con adaptación segura de ECHO de 5 V a 3,3 V.
- **Indicadores:** LEDs verde y rojo, con estado azul pendiente de comprobación.
- **Interfaz:** panel web local vía punto de acceso Wi-Fi, IP `192.168.4.1`.
- **Estructura:** madera disponible para cuerpo y placa de compactación (faltan dimensiones definitivas y fotografías).
- **Compactación:** mecanismo final pendiente de diseño, armado y mediciones. El SG90 usado en la etapa previa **no ha demostrado capacidad para comprimir papel**.

## 3. Definición operativa para el viernes
**Mínimo verificable:** estructura estable + papel seco + nivel de llenado medido + LEDs/panel local + placa compactadora guiada que comprima una muestra de papel de forma segura.
**Mejora opcional:** accionamiento motorizado **solo** si se dimensiona, protege y prueba con enclavamiento, finales de carrera y parada. No energizar un accionamiento improvisado delante de personas.

**Importante:** si el movimiento queda manual, describir el resultado como “compactación mecánica manual asistida por monitoreo electrónico”, **no** como compactación automática.

## 4. Evidencias que se deben subir
1. Plano dimensionado definitivo y fotos reales de la construcción.
2. Diagrama eléctrico que coincida con el cableado final.
3. Inventario con material reutilizado, prestado y comprado.
4. Video de detección de niveles y de la compactación (si funciona).
5. Registro de al menos tres ensayos con misma cantidad de papel: altura/volumen inicial y final, reducción calculada y observaciones.
6. Capturas de la interfaz y código exacto ejecutado en el prototipo.
7. Rúbrica final con una matriz requisito → evidencia.

## 5. Documentación de entrega
- [Plan de trabajo](CRONOGRAMA.md)
- [Materiales y decisiones de construcción](MATERIALES_Y_MONTAJE.md)
- [Ensayos y evidencias](PROTOCOLO_PRUEBAS.md)
- [Presentación oral](PRESENTACION.md)
- [Control de rúbrica](MATRIZ_RUBRICA.md)

## 6. Referencias a la etapa anterior
El código original se encuentra en `software/BasureroAlpha_ESP8266/BasureroAlpha_ESP8266.ino`. El diseño Fusion 360 previo está en `diseno_3d/Basurero Compactador.f3d`. El README del prototipo Alpha describe sus limitaciones. No mezclar datos de distintas etapas ni atribuir resultados de compactación al prototipo anterior.

**Equipo:** Kenny Luo, Lucas Soto, Vicente Lechuga, Agustín Ly, Benjamín Brito. Los roles finales deben ser confirmados por los integrantes.
