# EcoCompacta | Basurero compactador inteligente
**TEI201 — Taller de Diseño en Ingeniería · Universidad Adolfo Ibáñez · Sección 5**

**Estado:** entrega final en preparación. El prototipo Alpha ya cuenta con ESP8266, sensor y servidor web local. Las mejoras de software y el mecanismo final requieren pruebas en el montaje físico. No se atribuyen resultados que aún no se midieron.

## Problema y solución
El papel limpio y seco ocupa mucho espacio en papeleros de oficinas y salas de estudio. EcoCompacta propone un recipiente de compactación y un sistema IoT que mide su llenado, registra un histórico, muestra información en tiempo real y recomienda cuándo compactar o vaciar. **El firmware no mueve la placa; la compactación física se validará por separado.**

**Ciclo IoT evaluado:** HC-SR04 → ESP8266 → LittleFS (CSV en memoria flash, si funciona) → Dashboard local → alerta según porcentaje estimado.

## Diseño mecánico de la entrega final (propuesto, no validado)
Según el planteamiento del equipo, el papelero tendrá **base cuadrada nominal de 25 × 25 cm, paredes de 25 × 33 cm y tapa de 25 × 25 cm**, con una **placa móvil de MDF**. El accionamiento que se quiere construir consiste en **dos piñones y dos cremalleras verticales** a los lados, impulsados por **2 motores 28BYJ-48 con 2 módulos ULN2003**. El controlador previsto es **ESP8266** (no el ESP32 anterior). **Estas son medidas de diseño comunicadas por el equipo, no medidas finales verificadas después de cortar madera.**

- [Descripción del mecanismo piñón–cremallera](diseno-3d/MECANISMO_PINON_CREMALLERA.md).
- [Compatibilidad eléctrica y GPIO de motores con ESP8266](hardware/INTEGRACION_28BYJ48_ESP8266.md).
- [Pruebas del mecanismo y medición de compactación](testing/PROTOCOLO_MECANISMO.md).
- [Medidas originales de cinco maderas antes del corte](hardware/MEDIDAS_MADERA_ANTES_DE_CORTE.md).

**Inventario confirmado para el mecanismo (22/11): el equipo indicó que todavía NO tiene motores 28BYJ-48, ULN2003 ni piñones/cremalleras.** Son componentes solo propuestos; no están montados ni comprados. [Ver plan de compras y alternativas](hardware/PLAN_COMPRAS_Y_PRIORIDADES.md). Los componentes electrónicos del prototipo Alpha fueron utilizados previamente, pero su disponibilidad física actual se debe confirmar.

**Advertencia de implementación:** el firmware existente únicamente monitorea el nivel; **no acciona los motores**. Dos módulos ULN2003 necesitan ocho señales de control y el pinout previo del ESP8266 no tiene suficientes pines libres adecuados: hay que definir nueva electrónica de expansión/reasignación, alimentación y seguridad. No afirmar compactación motorizada demostrada.

## Entrega final y documentación
| Área de la pauta | Enlace | Estado |
|---|---|---|
| Matriz de rúbrica y pendientes | [Matriz](entrega_final/MATRIZ_RUBRICA.md) | Lista, falta evidencia física |
| Software | [Firmware con persistencia](firmware/EcoCompacta/EcoCompacta.ino) · [Guía de uso](firmware/README.md) | Escrito, **sin compilación/validación real** |
| Hardware | [Conexiones previstas](hardware/ESQUEMA_PRELIMINAR_FINAL.md) · [BOM editable](hardware/BOM_FINAL.csv) | Requiere cotejo con montaje y precios |
| Diseño 3D | [Fusion 360 Alpha](diseno_3d/Basurero%20Compactador.f3d) | Revisar dimensiones, integrar todos los componentes y exportar planos/renders |
| Testing | [Protocolo](entrega_final/PROTOCOLO_PRUEBAS.md) · [Datos](entrega_final/datos_pruebas.csv) | Ensayos pendientes |
| Fuentes / IA | [FUENTES.md](FUENTES.md) | Creado; verificar versiones y detalles con equipo |
| Presentación | [Guion](entrega_final/PRESENTACION.md) · [Cronograma](entrega_final/CRONOGRAMA.md) | Ajustar al tiempo docente |

La guía de Avance #3 del DEC indica **23/11/2026**; el equipo indicó su intención de presentar el **viernes 27/11/2026**. **Confirmar fecha oficial de la sección.**

## Integrantes
Kenny Luo · Lucas Soto · Vicente Lechuga · Agustín Ly · Benjamín Brito (distribución de funciones por confirmar con el equipo).

## Componentes actuales y materiales principales
- **NodeMCU ESP8266**, elegido tras dañarse el ESP32 inicialmente utilizado.
- **HC-SR04** y LEDs verde, azul y rojo con sus resistencias y cableado (el LED azul falló en Alpha; verificar antes de presentar).
- Protoboard y conexión USB utilizados durante Alpha (disponibilidad física actual por confirmar); la fuente adecuada para motores no está adquirida.
- Madera original disponible y previamente cortada para la estructura; las **medidas nominales de diseño** son 25 × 25 × 33 cm, pero faltan medidas **finales reales** y espesor. Placa compactadora de MDF prevista.
- **Advertencia:** el servo SG90 de Alpha no ha demostrado fuerza suficiente y no debe tratarse como compactador automatizado.

## Cómo ejecutar el software
1. Instalar Arduino IDE y el core **ESP8266** compatible. En Tools/Board, elegir el modelo NodeMCU ESP8266 real. Seleccionar un esquema de flash **con espacio asignado a LittleFS**.
2. Abrir `firmware/EcoCompacta/EcoCompacta.ino`.
3. **Medir y corregir** `DISTANCIA_VACIO_CM` y `DISTANCIA_LLENO_CM` según el recipiente físico; 30/3 cm son valores provisionales.
4. Cablear sensor y LEDs según [esquema provisional](hardware/ESQUEMA_PRELIMINAR_FINAL.md), validándolo contra el prototipo. El pin **ECHO de 5 V no se conecta directamente** a los 3,3 V del ESP8266.
5. Compilar y cargar el firmware en la placa; abrir monitor serie a **115200 baudios**. Revisar que se informe `LittleFS lista` y que las lecturas sean estables.
6. Conectar el PC/teléfono al Wi-Fi **`EcoCompacta-Final`** (clave de demostración `basurero123`), abrir **http://192.168.4.1/**.
7. Ver datos **en vivo**, gráfico histórico y descarga CSV desde `/api/historico`. Verificar que los registros permanecen tras reiniciar (y que la partición de archivos no se formatea).
8. Documentar las pruebas con distancias conocidas y completar [datos reales](entrega_final/datos_pruebas.csv). No usar valores inventados.

**Frecuencia:** lectura aproximada cada 1 s con 3 pulsos y filtro de mediana; persistencia cada 30 s para reducir escrituras flash. Los datos históricos registran **número de sesión** y **segundos de funcionamiento**, no fecha/hora real (sin RTC ni internet). La persistencia depende de LittleFS y debe confirmarse en la placa.

## Acceso rápido y evidencias
- Dashboard: **http://192.168.4.1/**, accesible **solo después** de conectarse al AP del ESP8266 energizado.
- Endpoint instantáneo: `/api/estado`.
- Histórico CSV actual: `/api/historico`; histórico anterior (si hubo rotación): `/api/historico-anterior`.
- Prototipo Alpha: [código original](software/BasureroAlpha_ESP8266/BasureroAlpha_ESP8266.ino), [documentación de limitaciones](documentacion/ALCANCE_Y_PENDIENTES.md).
- Adjuntar antes de presentar fotografías de tres ángulos, esquemático final, archivo Fusion 360 final, planos PDF, renders, resultados reales y video **solo de apoyo** (la guía exige demostración en vivo).

## Seguridad, reparación y honestidad experimental
Mantener motor sin alimentación si no hay evaluación de fuerza, protección contra atrapamientos, finales de carrera, tapa enclavada y parada segura. Un compactador de accionamiento manual debe presentarse como tal. Permitir abrir la cubierta con tornillos/desmontables para acceder al ESP8266 y sensor sin destruir el equipo. **No afirmar que la versión final está terminada mientras falten ensayos.**

## Integridad
Consultar [FUENTES.md](FUENTES.md): librerías, asistencia de IA, adaptaciones, verificación pendiente. Los integrantes deben comprender y defender todo el código y las decisiones del proyecto.
