# Matriz de cumplimiento — Avance #3, Prototipo IoT Completo (TEI201)

**Fuente:** guía oficial *Avance #3 — Prototipo IoT Completo*, DEC–UAI, documento suministrado por el equipo. **Actualización:** 22-11-2026.

El equipo confirma la **entrega del repositorio GitHub para el 23-11-2026**. La presentación oral fue comunicada para el viernes **27-11-2026**; confirmar hora y fecha oral con el docente.

**Estado:** este tablero distingue archivos creados de funciones **probadas en hardware**. Un archivo de código no demuestra funcionamiento. Objetivo interno: cubrir los criterios de nivel 7,0 sin inventar evidencias.

## Ponderación y plan para máximo puntaje

| Área | Peso | Requisito clave para 7,0 | Estado verificable al 22/11 | Acción pendiente |
|---|---:|---|---|---|
| **Software** | **30%** | Captura confiable y justificada, persistencia, dashboard con histórico, indicadores, código claro | Firmware ESP8266 con LittleFS **escrito pero no probado** | Compilar, calibrar, probar históricos tras reinicio, registrar errores |
| **Hardware** | **30%** | Componentes justificados, esquemático completo, BOM con costos, montaje ordenado, reparable | Pinout preliminar y BOM CSV editables | Verificar físicamente, costos reales, 3 fotos, puertas y tornillos para mantenimiento |
| **Diseño 3D** | **20%** | Gemelo 3D con todos los componentes, Fusion paramétrico, accesos, plano PDF y renders | Fusion Alpha guardado, final **pendiente** | Enviar medidas; completar ensamble; exportar planos y renders |
| **Testing** | **10%** | Protocolo medible, error/latencia, causas de falla y validación contra Avance 1 | Protocolo escrito, CSV **sin resultados** | Ensayos reales, logs, gráficas, evidencia antes/después |
| **GitHub** | **5%** | Clonable y completo: firmware, hardware, 3D, testing, docs, FUENTES, README | Estructura y README mejorados, FUENTES presente | Subir esquemático PDF, planos PDF, fotos, reporte y versiones finales |
| **Presentación** | **5%** | 8–10 min, demo en vivo, equipo responde técnicamente | Guion en preparación | Ensayar 3 veces, roles claros y dispositivo listo, explicar métricas |

## Software — puntos críticos
- [ ] Sensor captura **datos reales** sin interrupciones importantes, frecuencia justificada.
- [ ] CSV histórico persiste tras reiniciar ESP8266; revisar LittleFS y capacidad de flash.
- [ ] Dashboard muestra datos **actuales** e **históricos**, con unidades y tendencias.
- [ ] Alertas de llenado orientan decisión de compactar/vaciar.
- [ ] Código comprensible: muestreo, filtrado, cálculo, persistencia, web.
- [x] **FUENTES.md creado en raíz** con dependencias y uso de IA (revisión humana pendiente).
- [ ] Versiones exactas de librerías, adaptaciones y código de terceros verificadas.

**Condición habilitante:** según la guía, si `FUENTES.md` falta o está vacío, la nota de **Software es 1,0**, incluso si el sistema funciona.

## Nueva propuesta de mecanismo (22/11)
- [x] Documentado conceptualmente [doble piñón-cremallera](../diseno-3d/MECANISMO_PINON_CREMALLERA.md): base/tapa nominal 25 × 25 cm, paredes 25 × 33 cm, placa MDF, 2 motores 28BYJ-48 y 2 ULN2003.
- [ ] Confirmar si motores, drivers, piñones y cremalleras están disponibles y montados.
- [ ] Medir espesores y dimensiones finales tras cortar madera; verificar que coincide con Fusion 360.
- [ ] Resolver **8 señales ULN2003** más GPIO de sensor, luces y finales de carrera en ESP8266; rediseñar pinout, fuente y protecciones.
- [ ] Probar fuerza real de compactación, sincronización, guía, límites y enclavamiento.
- [ ] Desarrollar y **validar** firmware de motores solo después de contar con el hardware y seguridad; el actual es solo monitor.

## Hardware — demostración y documentos
- [ ] Justificar ESP8266 vs ESP32 (reemplazo por avería; capacidad Wi-Fi local y GPIO).
- [ ] Justificar HC-SR04: magnitud y rango útil; sensibilidad a superficie irregular.
- [ ] Pinout coincide con montaje; ECHO 5→3,3 V; resistencias LED.
- [ ] Esquemático PDF legible generado a partir del **cableado real**.
- [ ] BOM con cantidad, costo unitario, costo total y reutilizados/prestados.
- [ ] Fotos de 3 ángulos.
- [ ] Acceso sin destrucción a placa, sensor, cableado y alimentación.
- [ ] Si se motoriza, protecciones físicas y eléctricas verificadas; no alimentarlo improvisadamente.

## Diseño 3D
- [ ] Modelo `.f3d` funcional con madera, placa, guías, ESP8266, sensor, LEDs y accesos.
- [ ] Componentes internos representados con volúmenes referenciales reales.
- [ ] Ensamble sin interferencias, tolerancias, fijaciones desmontables.
- [ ] Planos PDF con vistas ortogonales, cotas, escala y tolerancias.
- [ ] Mínimo renders exterior e interior/explosionado con materiales.

## Testing
- [ ] Tres ensayos reales del sensor con distancia medida, error absoluto y porcentaje.
- [ ] Prueba de persistencia: anotar datos, apagar/encender, verificar mismos registros.
- [ ] Prueba de la visualización con cambio de carga de papel.
- [ ] Ensayo mecánico controlado con altura antes/después de la compactación.
- [ ] Análisis documentado de al menos una falla y su solución.
- [ ] Explicar cómo el resultado permite ahorrar vaciados o monitorear llenado.

## GitHub
- [x] Rama de entrega final creada sin alterar `main`.
- [x] README con instrucciones y estructura navegable.
- [x] Código ESP8266 y FUENTES.md.
- [x] BOM editable y guía de conexiones preliminar.
- [ ] Esquemático final exportado en PDF.
- [ ] Diseño Fusion final con planos y renders.
- [ ] Evidencias reales y resultados.
- [ ] Presentación y/o reporte final.
- [ ] Probar clonación y compilación desde carpeta descargada.

## Presentación
- [ ] Preparar demostración **en vivo**. Un video solo es respaldo, no reemplazo.
- [ ] 8–10 min incluyendo 3–4 min de demo, más 3 min preguntas.
- [ ] Roles de todos los integrantes.
- [ ] Ensayar presentación y pruebas del dispositivo al menos 3 veces día anterior.
- [ ] Link del GitHub visible en diapositiva.
- [ ] Todos explican su parte y el uso de IA.

**Importante:** No declarar ningún ítem pendiente como cumplido hasta que haya captura, documento final o prueba física.
