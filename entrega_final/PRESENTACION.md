# Guion de presentación de EcoCompacta — borrador supervisable

**Duración objetivo:** 9:10 min más preguntas, sujeto a confirmar con la pauta oficial de la sección.  
**Estado:** texto de apoyo; completar resultados con ensayos reales y asignar integrantes antes de exponer. No afirmar que un subsistema está construido o validado si no se demuestra.

## Secuencia y tiempos

| Tiempo | Contenido | Quién expone |
|---|---|---|
| 0:00–0:40 | Problema, usuario y objetivo | [Asignar] |
| 0:40–1:35 | Evolución desde Alpha y aprendizaje | [Asignar] |
| 1:35–2:40 | Ciclo IoT: sensor, ESP8266, almacenamiento y dashboard | [Asignar] |
| 2:40–3:35 | Hardware, pinout y seguridad eléctrica | [Asignar] |
| 3:35–4:35 | Estructura y mecanismo físico realmente construido | [Asignar] |
| 4:35–7:35 | Demostración en vivo | [Asignar] |
| 7:35–8:40 | Resultados medidos y falla/iteración | [Asignar] |
| 8:40–9:10 | Limitaciones, conclusión y repositorio | [Asignar] |

## Texto base para exponer

### 1. Problema y objetivo — 40 s

“En oficinas y salas de estudio, el papel limpio y seco ocupa espacio dentro del basurero. EcoCompacta busca ayudar a decidir cuándo vaciarlo y explorar cómo recuperar capacidad mediante una placa compactadora. Para eso separamos dos funciones: monitorear el nivel con electrónica y evaluar la compactación con el mecanismo físico.”

### 2. Evolución del prototipo — 55 s

“En Alpha implementamos el monitoreo con una placa ESP8266, un sensor ultrasónico HC-SR04 y una página local. Encontramos lecturas intermitentes y un LED azul que no quedó validado. El servo SG90 se conectó durante el montaje, pero no se accionó como compactador. Por eso presentamos con claridad qué funcionó en Alpha y qué requiere una nueva prueba.”

**Completar solo si el equipo confirma:** motivo preciso del reemplazo ESP32 → ESP8266: [________________].

### 3. Ciclo IoT — 65 s

“El HC-SR04 mide la distancia hasta el papel. El ESP8266 transforma esa distancia en un porcentaje estimado según dos referencias: recipiente vacío y nivel considerado lleno. Los datos se muestran en una red Wi-Fi local. El firmware preparado incorpora un histórico CSV en LittleFS; su persistencia debe considerarse demostrada solo después de reiniciar la placa y recuperar los registros.”

**Antes de exponer, completar:** distancia vacío [___] cm; referencia lleno [___] cm; intervalo de registro [___] s; prueba de persistencia [pendiente / resultado real].

### 4. Hardware y seguridad eléctrica — 55 s

“Usamos una NodeMCU ESP8266 y un HC-SR04. Como el ECHO del sensor puede entregar 5 V y los GPIO del ESP8266 trabajan a 3,3 V, la conexión debe incluir adaptación de nivel. Los motores no se conectan directamente a la placa. El diagrama que mostramos corresponde al cableado real y señala qué componentes siguen como propuesta.”

**Mostrar:** fotografía nítida del montaje actual y esquemático que coincida con ese montaje.

### 5. Diseño mecánico — 60 s

“Las dimensiones nominales comunicadas para la estructura son 25 × 25 cm de base y 33 cm de alto. Aún debemos distinguir esas cotas propuestas de las medidas reales después del corte. El mecanismo [manual / motorizado] que mostramos consiste en [describir solo lo construido]. La placa tiene [guías/topes reales] y el acceso de mantenimiento se realiza por [describir].”

**Si el doble piñón-cremallera no está instalado y probado:** decir “Es una propuesta de diseño, no un mecanismo demostrado”. No atribuir torque ni reducción de altura sin medición.

### 6. Demostración en vivo — 3 min

1. Mostrar el estado inicial y la conexión al punto de acceso local.
2. Colocar papel seco en el recipiente sin mover el sensor.
3. Comparar la distancia del sensor con una regla y mostrar el porcentaje del dashboard.
4. Mostrar el histórico/CSV solo si ya se guardaron datos reales.
5. Reiniciar la placa y recuperar los registros solo si la prueba de persistencia fue ejecutada.
6. **Compactación:** operar únicamente el mecanismo físico que esté protegido y validado. Si es manual, identificarlo como manual. Si no hay mecanismo seguro listo, mostrar el diseño y explicar que la compresión aún está pendiente.

**Respaldo:** video del Alpha disponible como evidencia anterior; no reemplaza la demostración del montaje actual.

### 7. Resultados, falla e iteración — 65 s

“En la prueba de distancia usamos una referencia de [___] cm y obtuvimos [___] cm en el sensor; el error absoluto fue [___] cm. En [número real] lecturas, [número real] fueron válidas. La prueba de compactación [se realizó/no se realizó]; si se realizó, la altura pasó de [___] cm a [___] cm, equivalente a [___] % de reducción. Una limitación/falla observada fue [___] y la respuesta aplicada fue [___].”

**No completar con estimaciones.** Si una medición no se hizo, decir “pendiente de medir”.

### 8. Cierre — 30 s

“EcoCompacta integra el monitoreo local del nivel y una propuesta física para recuperar espacio con papel seco. Nuestro resultado principal es [resultado real más importante]. Hoy funciona [lista breve verificada]; queda pendiente [limitación principal]. Dejamos el firmware, las conexiones, el modelo y el protocolo disponibles en GitHub.”

## Preparación previa

- Asignar una sección a cada integrante: Kenny Luo, Lucas Soto, Vicente Lechuga, Agustín Ly y Benjamín Brito.
- Confirmar duración exigida y fecha/hora con el profesor.
- Ensayar tres veces con cronómetro y montaje real.
- Llevar cable USB, fuente apropiada, regla, papel seco y copia offline de la presentación.
- Tener abierto el dashboard antes de iniciar; probar conexión Wi-Fi y recargar el teléfono/laptop.
- Completar los espacios de resultados desde [datos_pruebas.csv](datos_pruebas.csv).
- Mostrar el enlace de [GitHub](https://github.com/kennyluolu/basurero-alpha-tei201-secc5/tree/entrega-final-2026) y explicar el uso de IA conforme a [FUENTES.md](../FUENTES.md).

## Preguntas que conviene preparar

- ¿Cómo calcularon y calibraron el porcentaje de llenado?
- ¿Qué significa el porcentaje: altura, volumen o masa?
- ¿Qué prueba demuestra que el histórico permanece tras reiniciar?
- ¿Qué mecanismo se construyó realmente y cómo se evita una lesión?
- ¿Cuánta fuerza ejerce la placa y cómo se midió?
- ¿Qué cambió después de una falla real?
- ¿Qué código o documentación recibió asistencia de IA y cómo lo revisó el equipo?

## Respaldo para el día de presentación

- Capturas del panel actual y CSV original de pruebas.
- Video offline de una demostración real, si existe.
- Planos PDF, renders y fotografías del montaje actual.
- Repositorio GitHub y copia local del código.

