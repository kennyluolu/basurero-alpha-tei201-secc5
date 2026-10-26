# Iteraciones y decisiones

## Etapa 1 — Diseño descrito en el Avance #2
El PPT **EcoCompacta — Avance #2** propone ESP32, sensor HC-SR04, tres LED, Wi-Fi y un servomotor SG90 para compactación. Incluye como dimensiones conceptuales 21 × 17 × 31 cm y diseño Fusion 360. El PPT no se alcanzó a actualizar antes de la exposición.

## Etapa 2 — Cambio de microcontrolador
El equipo **sustituyó el ESP32 por un NodeMCU ESP8266** y explicó este cambio verbalmente a los profesores durante la presentación. El firmware guardado en `software/BasureroAlpha_ESP8266/` corresponde a la etapa ESP8266. No se deben copiar las librerías ni los pines del ESP32 del PPT como si fueran los actuales.

## Etapa 3 — Pruebas y limitaciones
Se desarrolló medición ultrasónica y monitoreo mediante red local `Basurero-Alpha` y panel en `192.168.4.1`. Se incorporaron LED verde, azul y rojo, pero **el azul no funcionó físicamente**. Se cuenta con evidencia fotográfica y video; las lecturas del sensor requieren verificación adicional.

## Etapa 4 — Compactación pendiente
El servomotor SG90 mencionado en el PPT no es una solución mecánica validada. El equipo busca una alternativa asequible para un contenedor pequeño, con control de fuerza, límites de carrera y protección contra atrapamientos. Ver `documentacion/PLAN_COMPACTACION_Y_PRESUPUESTO.md`.
