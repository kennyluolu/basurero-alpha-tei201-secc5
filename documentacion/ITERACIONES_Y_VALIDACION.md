# Iteraciones, demostración y limitaciones — Basurero Alpha

## Alcance
Papelero pequeño para **papel seco en oficinas**. La etapa actual es un prototipo electrónico; **no se ha validado compactación automática**. La presentación «EcoCompacta — Avance #2» describe una propuesta anterior, no debe confundirse con los resultados finales.

## Registro de iteraciones
| Etapa | Problema o decisión | Resultado conocido |
|---|---|---|
| Concepto inicial | Se propuso ESP32 y servomotor SG90 para compactación. | El montaje no logró la operación esperada; se cambió a ESP8266. |
| Conexión y programación | Cable USB-C comprado no compatible con la placa utilizada. | Se usó un cable del tipo empleado en Samsung antiguos, **probablemente Micro-USB tipo B**; confirmar físicamente. |
| Montaje | Cableado numeroso y materiales obtenidos con retraso. | Uso de protoboard y cables Dupont macho-macho y macho-hembra. |
| Medición | Sensor HC-SR04 produjo lecturas válidas y también lecturas inválidas/intermitentes. | Validación parcial; falta repetir ensayos y calibrar altura real. |
| Señalización | Se implementaron indicadores verde, azul y rojo en firmware. | LED azul no validado; no presentarlo como funcional. |
| Conectividad | Monitoreo local con ESP8266. | Se probó acceso por punto de acceso Wi-Fi y página web local. |
| Compactación | El SG90 prestado por el DEC se conectó al protoboard durante el montaje. | **No se alimentó ni accionó**: faltaba una fuente externa adecuada y el equipo evitó arriesgar el ESP8266. No se realizaron pruebas de compactación; queda pendiente definir un mecanismo apropiado. |

## Evidencias y pruebas
- El equipo presentó y explicó el prototipo ante profesores: **demostración académica**, no estudio formal de usabilidad ni prueba cuantitativa con usuarios.
- Fotografías y video del montaje sirven como evidencia visual; cada archivo debe etiquetarse según lo que efectivamente muestra, sin simular LED azul encendido ni compactación.
- Para el próximo ensayo registrar fecha, configuración, distancia real, distancia medida, porcentaje mostrado, LED observado, conectividad, fallas y responsable.

## Materiales y costo
- **Gasto total real comunicado por el equipo: $40.000 CLP**; no se conoce desglose unitario.
- Sensor HC-SR04 y servomotor SG90: **prestados por el DEC**, no comprados.
- Cables Dupont macho-macho, macho-hembra, USB-C y cable USB compatible con ESP8266: comprados por el equipo.
- Ver `documentacion/COSTOS_REALES_ALPHA.md`. El costo del mecanismo de compactación futuro es adicional y todavía no está cotizado.

## Próximos pasos
1. Verificar físicamente tipo de conector USB y documentar fotografías claras del circuito.
2. Repetir lecturas del HC-SR04 a distancias conocidas, proteger la entrada ECHO de 5 V y revisar el LED azul.
3. Medir dimensiones del contenedor y fuerza requerida para comprimir papel seco; diseñar placa guiada y mecanismo.
4. Antes de motorizar, definir enclavamiento de tapa, finales de carrera, parada y protección de corriente. No probar con manos en la zona de compresión.
5. Cotizar piezas reales y comparar contra el presupuesto disponible antes de comprar.

**Limitación central:** el funcionamiento de la interfaz electrónica no demuestra compactación mecánica. Las mejoras descritas son propuestas, no resultados obtenidos.
