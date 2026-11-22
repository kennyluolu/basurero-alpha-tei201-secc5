# Gemelo 3D — avance de entrega final

En esta carpeta se ha incluido una **copia íntegra del modelo de Fusion 360 de la etapa Alpha**: [Basurero Compactador.f3d](Basurero%20Compactador.f3d). **Se comprobó su presencia en GitHub, no que abra ni que coincida con las dimensiones finales.** El original sigue en `diseno_3d/`.

## Medidas disponibles de madera original

Se registraron **cinco piezas antes de cortarlas**; ver [medidas originales](../hardware/MEDIDAS_MADERA_ANTES_DE_CORTE.md). Aún no se conocen espesores, cortes definitivos ni qué pieza corresponde a cada cara; estas cifras no son las dimensiones finales del modelo.

## Concepto de diseño de la entrega final
[Ver memoria mecánica del doble piñón-cremallera](MECANISMO_PINON_CREMALLERA.md). Se han comunicado **base nominal 25 × 25 cm**, **paredes de 25 × 33 cm**, **tapa 25 × 25 cm** y **placa compactadora MDF**, con **2 motores 28BYJ-48**, **2 drivers ULN2003**, **2 piñones impresos 3D** y **2 cremalleras verticales**. Control previsto: **NodeMCU ESP8266**. **Ninguno de esos elementos ni dimensiones se ha verificado todavía dentro del archivo .f3d.**

## Acciones pendientes para el Avance #3
- Medir las piezas de madera y comparar con el ensamble de Fusion 360.
- Representar físicamente el contenedor, placa, guías, ESP8266 NodeMCU, HC-SR04, LEDs, fuente/cables y fijaciones desmontables.
- Garantizar acceso para reparar sensor y microcontrolador sin destruir el encapsulado.
- Usar sólidos referenciales cuando no haya modelos exactos de los componentes, **con dimensiones y ubicación reales**.
- Revisar intersecciones, holguras y topes.
- Exportar vistas ortogonales acotadas, tolerancias y escala en PDF.
- Preparar render exterior y render interior/explosionado con materiales.
- Reemplazar la **copia Alpha** por el modelo definitivo únicamente después de verificar las dimensiones y que abra sin errores.

**No describir el .f3d actual como gemelo definitivo mientras no se hagan estas comprobaciones.**
