# Protocolo de validación | EcoCompacta

**Estado:** plan de pruebas; **no contiene resultados medidos**. Registrar todos los valores, incluidos fallos.

## A. Seguridad y funcionamiento
1. Inspeccionar estructura, fijaciones, bordes, recorrido y posibles puntos de atrapamiento.
2. Sin papel, verificar que la placa se desplaza sin atascarse y que los topes actúan.
3. Si hay motor, confirmar tapa cerrada, parada y finales de carrera *antes* de habilitar su alimentación.
4. Probar sensor con 3 alturas de papel, repitiendo al menos 3 veces cada altura.
5. Registrar si LEDs y panel web coinciden con la medición.

## B. Medición de compactación
Usar el **mismo tipo y la misma cantidad de papel** por ensayo. Dejar constancia de masa (si hay balanza), número de hojas, tipo, posición y fuerza/método de compactación.

| Ensayo | Papel (hojas o g) | Altura inicial (cm) | Altura final (cm) | Reducción (%) | Tiempo (s) | Observaciones |
|---|---:|---:|---:|---:|---:|---|
| 1 | Pendiente | Pendiente | Pendiente | Pendiente | Pendiente | No ejecutado |
| 2 | Pendiente | Pendiente | Pendiente | Pendiente | Pendiente | No ejecutado |
| 3 | Pendiente | Pendiente | Pendiente | Pendiente | Pendiente | No ejecutado |

Para sección transversal aproximadamente constante y altura del papel bien definida:
`reducción (%) = 100 × (altura_inicial − altura_final) / altura_inicial`.
Si la pila no es uniforme, documentar la limitación; no confundir la reducción de altura de la muestra con reducción del volumen total del recipiente.

## C. Calidad de medición
- Registrar profundidad efectiva del contenedor y posición del HC-SR04.
- Comparar distancia manual vs. lectura del sensor; identificar ecos falsos, inclinación del papel y obstrucciones.
- Registrar error absoluto (cm) = |distancia sensor − distancia de referencia|.
- Probar en recipiente vacío, parcialmente lleno y cercano al umbral de alerta.
- El sensor puede fallar cuando la placa móvil bloquea su campo de visión: observar qué mide realmente.

## D. Evidencia sugerida
- Video único mostrando inicio, lectura de nivel, compactación y lectura posterior.
- Fotos antes/después con regla visible.
- Capturas de pantalla del panel.
- Archivo CSV con mediciones, fecha y nombre del ensayo.
- Nota explícita si compactación fue **manual**, no automatizada.

## Criterios de cierre
Marcar como `Probado`, `Parcial` o `No probado`. No registrar resultados de ejemplo como si fueran reales.
