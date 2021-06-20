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
    tmodel = tina.MeshTransform(model)
    scene.add_object(tmodel)

    gui = ti.GUI("TEST")
    while gui.running:
        scene.input(gui)

        matrix = tina.eularXYZ(rotate)
        tmodel.set_transform(matrix)

        scene.render()
        gui.set_image(scene.img)
        gui.show()
