# Diseño mecánico propuesto: doble piñón y cremallera

**Proyecto:** EcoCompacta · Avance #3 TEI201.  
**Estado:** concepto definido por el equipo el 22-11-2026; **motores, drivers, piñones y cremalleras NO adquiridos; construcción, dimensiones finales, torque y funcionamiento pendientes de verificación**. No se presenta como mecanismo ya instalado.

## 1. Geometría de referencia proporcionada por el equipo

| Elemento | Dimensiones nominales de la propuesta | Observaciones |
|---|---|---|
| Base de planta cuadrada | **25 × 25 cm** | Se debe precisar si son cotas exteriores o interiores |
| Paredes laterales | **25 × 33 cm** | 33 cm corresponde a altura de pared propuesta |
| Tapa superior | **25 × 25 cm** | Con abertura central para ingreso de residuos y paso del mecanismo |
| Placa móvil compactadora | **MDF; ancho, fondo y espesor pendientes** | Dimensionar para que se deslice sin atascarse |
| Cremalleras verticales | **2; largo y módulo pendientes** | Se fijarían a los extremos opuestos de la placa |
| Piñones | **2, impresos en 3D; geometría pendiente** | Deben engranar con las cremalleras seleccionadas |

Las medidas de las **cinco piezas de madera antes de cortarlas** están documentadas en [hardware/MEDIDAS_MADERA_ANTES_DE_CORTE.md](../hardware/MEDIDAS_MADERA_ANTES_DE_CORTE.md). No deben confundirse con las dimensiones nominales de **25 × 25 × 33 cm** de esta propuesta ni con medidas verificadas después del corte. Falta espesor y mapeo de cada pieza a la estructura.

## 2. Principio de funcionamiento

Se propone una **transmisión piñón–cremallera doble** para convertir el giro de **dos motores paso a paso 28BYJ-48** en desplazamiento vertical de una placa de MDF. Cada motor se ubicaría en una zona superior opuesta de la estructura y se acoplaría a un piñón impreso en 3D que engrane con una cremallera **vertical** unida a un borde opuesto de la placa.

Al girar ambos motores de forma coordinada, los dos puntos de tracción deberían impulsar el descenso. Al invertir el giro, la placa debería regresar a una posición superior. **La coordinación por pasos no garantiza que no haya pérdida de pasos, inclinación o atasco**: se requieren guías mecánicas, finales de carrera y una prueba con carga.

### Vista conceptual (sin escala)

```text
            TAPA SUPERIOR 25 × 25 cm
      ┌─────────────────────────────────┐
      │ M1 [piñón]         [piñón] M2 │  ← motores en lados opuestos
      │      ║               ║         │
      │      ║ cremallera    ║         │
      │  ┌───╨───────────────╨───┐     │
      │  │  PLACA MÓVIL MDF      │     │  ↓ descenso guiado
      │  └───────────────────────┘     │
      │      PAPEL SECO                 │
      │                                 │
      └────────── BASE ────────────────┘
```

**El dibujo es esquemático** y no fija orientación constructiva, soportes ni dimensiones de piñones; revisar en Fusion 360 y con las piezas físicas.

## 3. Subsistemas previstos

- **Estructura:** cinco piezas originales de madera, cortadas para conformar el cuerpo; definir base, paredes, tapa y refuerzos sin asumir asignaciones no demostradas.
- **Actuación:** **2 × 28BYJ-48** y **2 × ULN2003**, **NO disponibles según el equipo el 22/11**; por adquirir solo si se valida fuerza y compatibilidad; **2 piñones** y **2 cremalleras** compatibles entre sí.
- **Placa:** MDF móvil; adicionar al menos dos guías independientes para resistir torsión y evitar que el motor soporte las cargas laterales.
- **Control:** **NodeMCU ESP8266**, **no ESP32**. HC-SR04 para medir nivel; indicador LED/web y persistencia LittleFS según el firmware de monitoreo.
- **Protección:** cubierta de transmisión, acceso de mantenimiento desmontable, control de tapa cerrada, limitación superior e inferior y parada/desconexión accesible.

## 4. Verificaciones de ingeniería ANTES de fabricar/acoplar

1. **Fuerza de compactación real:** ensayar con una carga de papel representativa y medir fuerza aproximada con balanza/medidor adecuado. El 28BYJ-48 es un motor pequeño: no asumir que comprime papel solo por contar con reductora.
2. **Geometría:** definir módulo/paso de dientes, número de dientes del piñón y cremallera compatible. La carrera por revolución depende de la circunferencia primitiva del piñón; no inventar medidas.
3. **Par y fuerza:** como primera aproximación ideal para dos motores simétricos, `F_total ≈ 2·T_salida/r_pinion` (T en N·m y radio primitivo en m). En la práctica hay pérdidas, rozamiento y posible desincronización. Se necesitan datos de torque **de los motores realmente disponibles** y una prueba con carga.
4. **Eje y soporte:** evitar aplicar cargas radiales o de flexión excesivas al eje del motor; incorporar soportes y acoples mecánicos apropiados, guías y refuerzo para las fijaciones.
5. **Recorrido y topes:** medir altura útil real del contenedor y separar posiciones de reposo y final; no utilizar pasos de motor como único límite.
6. **Sincronización:** verificar que ambos lados se mueven igual bajo carga. Motores sin realimentación pueden perder pasos; realizar referencia inicial a un límite y observar desalineación.
7. **Eléctrica:** los dos ULN2003 requieren 8 señales de control (4 cada uno); el ESP8266 Alpha ya utiliza GPIO para HC-SR04 y LEDs. **No hay suficientes pines libres seguros con el pinout anterior**. Diseñar asignación nueva y/o expansión de GPIO **antes** de conectar. Confirmar tensión de control de los módulos (ESP8266 es de 3,3 V), fuente dedicada para motores, GND común según diseño y fusible/protecciones.
8. **Seguridad:** la tapa debe impedir acceso a la zona de apriete cuando se energiza, con parada accesible, dos finales de carrera y protección contra atascos/sobrecorriente; validar sin manos dentro. Si no se logra seguridad y fuerza suficiente, **hacer demostración de compactación manual** y mostrar la motorización como propuesta no implementada.

## 5. Integración con firmware vigente

El archivo [firmware/EcoCompacta/EcoCompacta.ino](../firmware/EcoCompacta/EcoCompacta.ino) **solo mide el llenado, guarda CSV y sirve el dashboard**. No acciona motores y no implementa enclavamientos, sincronización ni finales de carrera. **No declarar compresión automática a partir de este código.**

Antes de implementar automatización se debe diseñar y probar un controlador con estados explícitos `REPOSO`, `BAJANDO`, `SUBIENDO`, `ERROR`; bloquear marcha con tapa abierta; detener ante fin de carrera/falla y disponer de parada física. Probar motores sin carga y después con cargas graduadas.

## Estado de compras
El equipo informó que **no tiene aún motores, controladores, piñones ni cremalleras**. Consultar [plan de compras y alternativas](../hardware/PLAN_COMPRAS_Y_PRIORIDADES.md). Prioridad: comprobar fuerza requerida y elegir una transmisión segura; el concepto no es compromiso de compra.

## 6. Documentos/evidencias pendientes

- [ ] Fotos y medidas reales tras corte, espesor de madera y placa de MDF.
- [ ] Modelo paramétrico Fusion 360 con mecanismo, motores y sensores en ubicaciones reales.
- [ ] Planos con vistas, cotas, tolerancias y escala PDF; renders exteriores e interior/explosionado.
- [ ] Esquemático electrónico final con pinout ESP8266, drivers, alimentación, enclavamientos.
- [ ] BOM con costos comprobados, detalle de componentes comprados y prestados.
- [ ] Pruebas con fuerza/recorrido, tiempo, fallas, calentamiento y % de reducción de altura.
- [ ] Evidencias de montaje seguro y demostración **en vivo**.

**Nota de trazabilidad:** el mecanismo y dimensiones nominales fueron proporcionados por el equipo; advertencias, tabla y texto técnico fueron preparados con asistencia de ChatGPT y requieren revisión del equipo. [FUENTES.md](../FUENTES.md).
