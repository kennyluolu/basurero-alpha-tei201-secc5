# Protocolo de pruebas — Avance #3 TEI201 (EcoCompacta)

**Versión:** 22-11-2026. **Estado:** protocolo, **sin resultados ejecutados**. Se requiere hardware ESP8266 y papel seco real. Guardar fotos, logs y archivos de datos sin alterar.

## Prueba 1 — Precisión del sensor y fiabilidad
**Objetivo:** verificar que el HC-SR04 mide distancias reales y el dashboard refleja esas medidas.

**Condiciones:** recipiente armado, sensor fijo, papel seco, una regla, ESP8266 y navegador conectados a `EcoCompacta-Final`. Calibrar los parámetros de distancia del firmware con medidas reales antes de comenzar.

**Procedimiento:**
1. Medir distancia real sensor-superficie con regla, en al menos **3 posiciones** (vacío, medio y cercano al lleno).
2. Mantener papel en esa posición y registrar **10 lecturas consecutivas** visibles en Serial/API (30 mediciones en total).
3. Anotar distancia de referencia, lectura ESP8266, si hubo lectura inválida y estado LED/web. Guardar al menos una foto con regla por posición.
4. Repetir variando inclinación de superficie o con papel irregular y anotar fallos.

**Indicadores:** `error_absoluto_cm = |lectura_sensor_cm − distancia_referencia_cm|`; `tasa_lectura_valida = lecturas_validas / lecturas_totales × 100%`. Calcular error medio y máximo solo cuando existan valores medidos.

**Criterio de aceptación propuesto (ajustar a necesidades reales):** por lo menos 90% lecturas válidas; error absoluto medio <2 cm en las 3 posiciones; estados de alerta coherentes con umbrales. Si no cumple, registrar motivo y calibrar o reubicar sensor.

## Prueba 2 — Persistencia real y dashboard
**Objetivo:** demostrar ciclo IoT completo captura → almacenamiento → dashboard → decisión.

**Procedimiento:**
1. Abrir Serial a 115200 y comprobar mensaje `LittleFS lista`; guardar captura del arranque.
2. Cargar un nivel de papel y observar actualizaciones a intervalos cercanos a 1 segundo.
3. Tras al menos **90 segundos**, descargar `/api/historico` y registrar número de filas y valores (el firmware propone guardar cada 30 segundos).
4. **Apagar y reiniciar** ESP8266. Volver a conectar Wi-Fi local y descargar histórico; confirmar que las filas anteriores siguen presentes y existe un nuevo ID de sesión.
5. Verificar que el gráfico muestra tendencia real de llenado y que el mensaje cambia al pasar umbrales.
6. Guardar captura de dashboard y CSV original.

**Criterio propuesto:** al menos 3 muestras guardadas en 90 segundos con sensor válido, 100% de filas anteriores recuperadas tras reinicio, gráfico legible y alerta coherente. Revisar el estado del FS si no se cumple.

**Nota:** `tiempo_s` se reinicia en cada arranque; `sesion` distingue los reinicios. Sin reloj en tiempo real no se deben inventar horas/fechas de medida.

## Prueba 3 — Compactación física (separada del software)
**Objetivo:** evaluar si la placa realmente reduce altura aparente de papel seco sin poner en riesgo a usuarios.

**Condiciones:** estructura estable, manos fuera del área de apriete, topes mecánicos, tapa protegida; si se elige motor, no energizar sin final de carrera, enclavamiento, parada y alimentación adecuada.

**Procedimiento:**
1. Introducir la misma cantidad y tipo de papel por ensayo; contar hojas y, si hay balanza, medir masa.
2. Medir altura inicial, operar mecanismo seguro, retirar fuerza, medir altura final después de soltar el papel.
3. Registrar tiempo del proceso, atascos y método manual/motorizado real.
4. Repetir al menos 3 veces en condiciones equivalentes.

**Indicador:** `reduccion_altura_pct = 100×(altura_inicial−altura_final)/altura_inicial`. La recuperación elástica del papel puede causar rebote. No equiparar reducción de altura con compactación automática o disminución de residuos generados.

**Criterio propuesto:** reducción medible mayor que cero en muestras equivalentes sin daños, vuelcos ni atrapamientos. Reportar valores reales o fallas.

## Prueba 4 — Reparabilidad
**Objetivo:** acceder a MCU, sensor y conexiones sin destruir carcasa.

**Procedimiento:** desconectar energía, abrir la tapa de mantenimiento, fotografiar puntos de fijación, retirar y volver a instalar sensor/MCU de manera reversible, cerrar y repetir lectura.

**Criterio:** abrir/cerrar con herramientas corrientes, sin romper piezas, y retorno a operación normal.

## Análisis de fallas / vínculo con problema original
Registrar una falla **real** con síntoma, causa probable, diagnóstico y solución ensayada (p. ej. ecos intermitentes de Alpha, LED azul defectuoso, obstrucción del sensor). Evitar declarar causa definitiva sin diagnóstico.

Conectar resultados a Avance 1: cuando sube el nivel de papel seco, la alerta permite decidir entre compactación o vaciado; si la compactación reduce altura aparente, registrar cuánta capacidad se recupera en el ensayo concreto.

## Registro
Completar [datos_pruebas.csv](datos_pruebas.csv), guardar exportaciones de `/api/historico`, pantallazos del panel, fotografías y protocolo con fecha/autor. **No completar tablas con números estimados como si fueran medidos.**
