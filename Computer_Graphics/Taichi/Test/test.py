import taichi as ti
import tina

ti.init(ti.gpu)

scene = tina.Scene()

material = tina.PBR(metallic=0.6, roughness=0.2)
model = tina.MeshModel('./monkey.obj')

scene.add_object(model, material)

gui = ti.GUI('test')

scene.lighting.clear_lights()
scene.lighting.add_light(dir=[0, 0, 1], color=[1, 1, 1])
scene.lighting.add_light(pos=[1, 1.5, 0.3], color=[1, 0, 0])
scene.lighting.set_ambient_light([0, 0.06, 0])

while gui.running:
    scene.input(gui)
    scene.render()
    gui.set_image(scene.img)
    gui.show()