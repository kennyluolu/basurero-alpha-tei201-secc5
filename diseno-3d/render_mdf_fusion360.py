# -*- coding: utf-8 -*-
"""
Script oficial para Autodesk Fusion 360:
Aplica material real de madera MDF al archivo abierto ("Basurero Compactador.f3d")
y genera renders reales en alta resolución (1920 x 1080 px) desde el motor de Fusion 360
guardándolos automáticamente en tu Escritorio (carpeta Renders_EcoCompacta_MDF).

CÓMO USARLO (30 segundos):
1. Abre "Basurero Compactador.f3d" en Autodesk Fusion 360.
2. Presiona Shift + S (Scripts and Add-Ins) > My Scripts > "+ Create" (Python) > ponle "RenderMDF".
3. Haz clic derecho > Edit, pega este código, guarda (Ctrl + S) y presiona "Run".
"""

import adsk.core
import adsk.fusion
import traceback
import os
import math


def get_or_copy_appearance(app, design, search_names, fallback_rgb, custom_name):
    """Busca una apariencia real en la librería de Fusion 360 o crea una con el color indicado."""
    existing = design.appearances.itemByName(custom_name)
    if existing:
        return existing

    lib = app.materialLibraries.itemByName('Fusion 360 Appearance Library')
    if lib:
        for name in search_names:
            found = lib.appearances.itemByName(name)
            if found:
                return design.appearances.addByCopy(found, custom_name)
        # Búsqueda parcial (por si Fusion está en español o varía el nombre exacto)
        for i in range(lib.appearances.count):
            ap = lib.appearances.item(i)
            low = ap.name.lower()
            for key in ['mdf', 'oak', 'pine', 'birch', 'maple', 'wood', 'madera']:
                if key in low and custom_name == 'EcoCompacta_MDF_Real':
                    return design.appearances.addByCopy(ap, custom_name)

        # Fallback por color RGB exacto de MDF natural
        base = lib.appearances.itemByName('Paint - Enamel Glossy (White)')
        if not base and lib.appearances.count > 0:
            base = lib.appearances.item(0)
        if base:
            ap_copy = design.appearances.addByCopy(base, custom_name)
            prop = adsk.core.ColorProperty.cast(ap_copy.appearanceProperties.itemByName('Color'))
            if prop:
                prop.value = adsk.core.Color.create(fallback_rgb[0], fallback_rgb[1], fallback_rgb[2], 255)
            return ap_copy
    return None


def apply_mdf_to_housing(root, mdf_app):
    """Aplica la apariencia MDF solo a las piezas estructurales (sin tocar ESP32, HC-SR04, SG90 ni LEDs)."""
    if not mdf_app:
        return 0
    keep_keywords = ['esp32', 'hcsr04', 'sg90', 'protoboard', 'led', 'dupont', 'resistencia', 'usb', 'alimentacion', 'modulo']
    changed = 0

    def walk_comp(comp):
        nonlocal changed
        comp_low = comp.name.lower()
        is_elec = any(k in comp_low for k in keep_keywords)
        if not is_elec:
            for b in comp.bRepBodies:
                b_low = b.name.lower()
                if not any(k in b_low for k in keep_keywords):
                    try:
                        b.appearance = mdf_app
                        changed += 1
                    except Exception:
                        pass
        for occ in comp.occurrences:
            walk_comp(occ.component)

    walk_comp(root)
    return changed


def run(context):
    ui = None
    try:
        app = adsk.core.Application.get()
        ui = app.userInterface
        design = adsk.fusion.Design.cast(app.activeProduct)

        if not design:
            ui.messageBox('Abre primero tu archivo "Basurero Compactador.f3d" en Fusion 360 y vuelve a ejecutar el script.')
            return

        root = design.rootComponent

        # 1. Aplicar apariencia real de madera MDF a la estructura
        mdf_app = get_or_copy_appearance(
            app, design,
            ['Wood - MDF', 'MDF', 'Wood (Unfinished) - Pine', 'Wood (Finished) - Oak'],
            (196, 158, 114),
            'EcoCompacta_MDF_Real'
        )
        n_bodies = apply_mdf_to_housing(root, mdf_app)

        # 2. Configurar escena limpia de estudio en el RenderManager de Fusion 360
        render_mgr = design.renderManager
        scene = render_mgr.sceneSettings
        scene.backgroundType = adsk.fusion.RenderSceneBackgroundTypes.SolidColorRenderSceneBackgroundType
        scene.backgroundSolidColor = adsk.core.Color.create(255, 255, 255, 255)
        scene.isGroundPlane = True
        scene.isGroundReflections = False

        # Carpeta de salida en el Escritorio
        out_dir = os.path.join(os.path.expanduser('~'), 'Desktop', 'Renders_EcoCompacta_MDF')
        os.makedirs(out_dir, exist_ok=True)

        # 3. Lanzar render local real con ray-tracing en Fusion 360 (1920 x 1080 px)
        rendering = render_mgr.rendering
        rendering.resolutionWidth = 1920
        rendering.resolutionHeight = 1080
        rendering.renderQuality = 75  # 75 = Calidad Alta (Excelente balance velocidad/calidad)
        rendering.isBackgroundTransparent = False

        viewport = app.activeViewport
        viewport.fit()
        adsk.doEvents()

        # Guardar captura rápida de alta resolución (1920x1080) del viewport actual
        quick_path = os.path.join(out_dir, '01_Render_Viewport_Isometrico_MDF.png')
        viewport.saveAsImageFile(quick_path, 1920, 1080)

        # Iniciar el render ray-traced local real (se guarda automáticamente al terminar)
        raytrace_path = os.path.join(out_dir, '02_Render_Real_RayTraced_MDF.png')
        future = rendering.startLocalRender(raytrace_path)

        # Esperar a que termine el render real sin congelar Fusion 360
        while future.renderState == adsk.fusion.LocalRenderStates.QueuedLocalRenderState or \
              future.renderState == adsk.fusion.LocalRenderStates.ProcessingLocalRenderState:
            adsk.doEvents()

        ui.messageBox(
            f'¡Render real completado en Fusion 360!\n\n'
            f'• Piezas actualizadas a material MDF: {n_bodies}\n'
            f'• Carpeta de salida:\n{out_dir}\n\n'
            f'Archivos guardados:\n'
            f'1. 01_Render_Viewport_Isometrico_MDF.png\n'
            f'2. 02_Render_Real_RayTraced_MDF.png',
            'EcoCompacta · Render Real Fusion 360'
        )

    except Exception:
        if ui:
            ui.messageBox('Error al renderizar:\n{}'.format(traceback.format_exc()))