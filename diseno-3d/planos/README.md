# Planos y CAD preliminares

- Plano vectorial: Plano_Preliminar_EcoCompacta.svg
- Plano PDF: Plano_Preliminar_EcoCompacta.pdf
- Subconjunto OpenSCAD: ../parametrico/Pinon_Cremallera_EcoCompacta.scad

Las cotas del recipiente (250 × 250 × 330 mm) son nominales. Espesor de madera, dimensiones de placa MDF, abertura de tapa, guías, ubicación de sensores y tolerancias están pendientes de medir. Este plano es esquemático y no es apto para fabricación.

## Piñón-cremallera

El croquis indica piñón Ø30 exterior, Ø27 primitivo, espesor 10, eje doble D Ø5,25 con 3,25 entre caras; cremallera paso 4,71, ángulo 20°, 64 dientes, largo total 310 mm. La relación da módulo aproximado 1,50 y 18 dientes. Se interpretan provisionalmente las cotas 10,6 mm y 3,375 mm como ancho/cara del cuerpo y profundidad total del diente. La pestaña indica espesor 4 mm y dos agujeros Ø3,5 mm; ubicación no especificada. El CAD deja esos puntos como parámetros editables y usa margen provisional de 15 mm.

64 centros implican 63 intervalos: 63 × 4,71 = 296,73 mm, centrados en 310 mm. Confirmar si el croquis quiso decir 64 dientes o 64 pasos.

Para exportar STL: abrir el SCAD en OpenSCAD, cambiar vista a pinon o cremallera, Render (F6) y Exportar como STL. No hay pruebas mecánicas o dimensionales reportadas.
