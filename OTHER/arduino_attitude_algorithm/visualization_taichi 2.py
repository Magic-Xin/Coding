import taichi as ti
import tina

rotate = []


def transform(s_format_trans):
    global rotate
    rotate = s_format_trans


def main():
    ti.init()
    scene = tina.Scene(TAA=True)

    model = tina.MeshModel('./model/QBZ-95.obj')
    t_model = tina.MeshTransform(model)
    scene.add_object(t_model)

    gui = ti.GUI("TEST")
    while gui.running:
        scene.input(gui)

        t_matrix = tina.quaternion(rotate)
        t_model.set_transform(t_matrix)

        scene.render()
        gui.set_image(scene.img)
        gui.show()
