# Protocolo específico — mecanismo doble piñón-cremallera

**Fecha de diseño:** 22-11-2026. **Estado:** pruebas propuestas, **ninguna se declara ejecutada**. Se realiza sobre papel seco con protecciones y sin manos cerca de la placa.

## Objetivos
Determinar si dos 28BYJ-48 con dos ULN2003 realmente pueden mover una placa MDF por medio de piñones/cremalleras y compactar papel sin pérdida excesiva de pasos, sobrecarga ni atascamientos. Los motores pueden resultar insuficientes: ese resultado también debe documentarse.

## Condición previa: seguridad
- Documentar fijaciones, placa guiada, protecciones de transmisión, enclavamiento de tapa, parada accesible y finales de carrera funcionales.
- Verificar fuente externa adecuada, fusible, continuidad y compatibilidad lógica con ESP8266.
- Comprobar que los dos módulos están conectados a un control diseñado para los GPIO realmente disponibles: **no utilizar el firmware de monitoreo como si accionara motores**.
- Sin las protecciones verificadas, **no energizar la compactación**; hacer prueba manual segura o evaluar accionamiento alternativo.

## Ensayos por etapa
| Ensayo | Procedimiento | Qué registrar | Criterio de éxito propuesto |
|---|---|---|---|
| A. Movimiento independiente | Mover un motor por vez SIN placa/carga, observar piñón y cremallera | Pasos programados, desplazamiento real, fallos, temperatura y tiempo | Movimiento repetible, sin bloqueos |
| B. Coordinación | Operar ambos lados sin papel con placa guiada y tapa protegida | Diferencia de alturas entre lados al inicio/fin, cantidad de ciclos | Sin inclinación que genere atasco |
| C. Límites y parada | Comprobar límites superior/inferior y parada protegida antes de prueba con carga | Tiempo de detención, condición disparada, estado tras reinicio | Actuación se detiene sin impactar topes rígidos |
| D. Carga gradual | Agregar papel seco en cantidades progresivas y operar solo cuando el montaje sea seguro | Hojas, masa, altura inicial/final, recorrido, tiempo, atascos y temperatura | Reducción medible sin atascos ni sobrecalentamiento |
| E. Repetibilidad | Repetir al menos 3 ciclos equivalentes en condiciones controladas | Diferencia entre ensayos, errores, fallas | Documentar variación y limitaciones |
| F. Compatibilidad sensor | Comprobar que el HC-SR04 no mide la placa en lugar del papel | Distancia sensor/real y estado de lectura con placa arriba/abajo | Datos interpretables; si no, cambiar posición o declarar limitación |

El **criterio de éxito cuantitativo exacto** debe ajustarse una vez que se midan fuerzas, recorridos y tolerancias reales. No inventar límites de carga ni especificaciones del motor.

## Cálculos a realizar con datos reales
- `reduccion_altura_pct = 100 × (h_antes − h_despues) / h_antes` (medir después de retirar fuerza para observar recuperación elástica).
- `desalineacion_mm = |altura_lado_1 − altura_lado_2|`.
- `velocidad_lineal = carrera_real / tiempo_de_desplazamiento`.
- Estimación inicial: `F_total_ideal ≈ 2·T_salida / radio_primitivo`. **No asumir** torque nominal de un motor diferente; considerar fricción, juego, pérdida de pasos y diferencia entre motores.

## Evidencia para la rúbrica
Fotos desde 3 ángulos, video de **pruebas de apoyo**, gráfico de datos reales, tabla de ensayos, una falla y corrección documentadas, CAD y planos. En presentación, la guía exige **demostración en vivo**, no basta con video.

Referencias internas: [diseño mecánico](../diseno-3d/MECANISMO_PINON_CREMALLERA.md), [integración eléctrica](../hardware/INTEGRACION_28BYJ48_ESP8266.md), [protocolo IoT](../entrega_final/PROTOCOLO_PRUEBAS.md).
