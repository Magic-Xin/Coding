import taichi as ti
import tina

ti.init(ti.gpu)

scene = tina.Scene(fxaa=True)

material = tina.PBR(metallic=0.6, roughness=0.2)
model = tina.MeshModel('./monkey.obj')

scene.add_object(model, material)

gui = ti.GUI('test')

scene.lighting.clear_lights()
scene.lighting.add_light(dir=[0, 0, 1], color=[1, 1, 1])
scene.lighting.add_light(pos=[1, 1.5, 0.3], color=[1, 0, 0])
scene.lighting.set_ambient_light([0, 0.06, 0])

abs_thresh = gui.slider('abs_thresh', 0, 0.1, 0.002)
rel_thresh = gui.slider('rel_thresh', 0, 0.5, 0.01)
factor = gui.slider('factor', 0, 1, 0.01)
abs_thresh.value = 0.0625
rel_thresh.value = 0.063
factor.value = 1

while gui.running:
    scene.fxaa.rel_thresh[None] = rel_thresh.value
    scene.fxaa.abs_thresh[None] = abs_thresh.value
    scene.fxaa.factor[None] = factor.value
    scene.input(gui)
    scene.render()
    gui.set_image(scene.img)
    gui.show()