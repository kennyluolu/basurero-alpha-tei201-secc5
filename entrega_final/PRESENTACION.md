# Guion de presentación de EcoCompacta (borrador)

> Ajustar duración y apartados a la pauta oficial. No afirmar automatización o reducciones medidas antes de verificarlas.

## Secuencia propuesta
1. **Problema:** papel seco ocupa espacio y obliga a vaciar con frecuencia el papelero.
2. **Usuario y objetivo:** contextos de oficina/estudio; controlar llenado y compactar papel.
3. **Evolución:** Alpha usaba ESP8266, HC-SR04 y panel web; compactación estaba pendiente. Explicar por qué se reemplazó el ESP32.
4. **Diseño final:** presentar plano acotado y maqueta; justificar madera reutilizada, mecanismo elegido y seguridad.
5. **Electrónica:** diagrama real ESP8266 → sensor → LEDs/panel, limitaciones y calibración.
6. **Demostración:** lectura de nivel con papel seco y, solo si el montaje es seguro, proceso de compactación.
7. **Resultados:** tabla y reducción calculada a partir de pruebas reales; repetir al menos 3 ensayos.
8. **Iteraciones y aprendizajes:** problemas, cambios de solución, costos y próximos pasos.
9. **Cierre:** qué funciona, qué queda pendiente y por qué el prototipo aporta valor.

## Respaldo para el día de presentación
- Capturas del panel web en funcionamiento.
- Video offline de la demostración, sin sustituir la prueba real si es posible.
- Batería/fuente, cable USB, resistencias y repuestos.
- Planos PDF o imágenes legibles.
- Repositorio GitHub y copia local del código.

## Preguntas previsibles
- ¿Por qué se cambió ESP32 por ESP8266?
- ¿Cómo calculan el porcentaje de llenado? ¿Está calibrado?
- ¿Cuál es la fuerza de compactación? ¿Cómo la midieron?
- ¿Cuánto se redujo realmente la altura o el volumen del papel?
- ¿Qué protege al usuario del mecanismo?
- ¿Qué se construyó realmente y qué solo se propuso?
- ¿Qué componente fue el más costoso o limitante?
