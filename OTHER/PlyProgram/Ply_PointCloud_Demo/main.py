import numpy as np
import mayavi.mlab as mlab
from plyfile import PlyData


def read_ply(filepath):
    _data = PlyData.read(filepath)
    _pc = _data['vertex'].data
    _array = np.array([_pc['x'], _pc['y'], _pc['z']])
    return _array


def draw_ply():
    mlab.figure(bgcolor=(0.2, 0.3, 0.3), fgcolor=(1.0, 0.5, 0.3))
    ply_array = read_ply('./1.ply')
    x = ply_array[0]
    y = ply_array[1]
    z = ply_array[2]

    mlab.points3d(x, y, z, colormap='spectral', scale_factor=.03)
    mlab.show()


def draw_line():
    mlab.figure(bgcolor=(0.2, 0.3, 0.3), fgcolor=(1.0, 0.5, 0.3))
    mlab.plot3d([0, 1000], [0, 0], [0, 0], tube_radius=10.)
    mlab.plot3d([0, 0], [0, 1500], [0, 0], tube_radius=10.)
    mlab.plot3d([0, 0], [0, 0], [0, 1500], tube_radius=10.)
    mlab.show()


if __name__ == '__main__':
    draw_ply()
    # draw_line()
