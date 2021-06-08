import numpy as np
from mayavi import mlab
from plyfile import PlyData


def show_mayavi(x, y, z, _x):
    mlab.figure(bgcolor=(1, 1, 1))
    mlab.outline(color=(0, 0, 0))

    def f(a, b):
        return _x[0, 0] * a + _x[1, 0] * b + _x[2, 0]

    xx, yy = np.mgrid[-10:10:50j, -10:10:50j]

    mlab.surf(xx, yy, f, color=(0, 0, 1), warp_scale=.5, representation='wireframe', line_width=0.5)
    mlab.points3d(x, y, z, color=(1, 0, 0), scale_factor=.05)

    axes = mlab.axes(color=(0, 0, 0), nb_labels=5, ranges=[10, 10, -10, 10, -20, 20])
    axes.title_text_property.color = (0.0, 0.0, 0.0)
    axes.title_text_property.font_family = 'times'
    axes.label_text_property.color = (0.0, 0.0, 0.0)
    axes.label_text_property.font_family = 'times'
    mlab.gcf().scene.parallel_projection = True
    mlab.orientation_axes()

    mlab.show()


def random_point(a, b, c):
    x = np.random.uniform(-10, 10, size=100)
    y = np.random.uniform(-10, 10, size=100)
    z = (a * x + b * y + c) + np.random.normal(-1, 1, size=100)
    return x, y, z


def read_ply(filepath):
    _data = PlyData.read(filepath)
    _pc = _data['vertex'].data
    _array = np.array([_pc['x'], _pc['y'], _pc['z']])
    x = _array[0]
    y = _array[1]
    z = _array[2]
    return x, y, z


def LSM(x, y, z):
    a = 0
    _a = np.ones((100, 3))
    for i in range(0, 100):
        _a[i, 0] = x[a]
        _a[i, 1] = y[a]
        a = a + 1

    b = np.zeros((100, 1))
    a = 0
    for i in range(0, 100):
        b[i, 0] = z[a]
        a = a + 1

    _aT = _a.T
    _x = np.dot(np.dot(np.linalg.inv(np.dot(_a.T, _a)), _a.T), b)
    print('平面拟合结果为：z = %.3f * x + %.3f * y + %.3f' % (_x[0, 0], _x[1, 0], _x[2, 0]))

    r = 0
    for i in range(0, 100):
        r += (_x[0, 0] * x[i] + _x[1, 0] * y[i] + _x[2, 0] - z[i]) ** 2
    print('方差为：%.*f' % (3, r))

    return _x


if __name__ == '__main__':
    # _x, _y, _z = random_point(1, 1, 0)
    _x, _y, _z = read_ply('./1.ply')
    _lsm = LSM(_x, _y, _z)
    show_mayavi(_x, _y, _z, _lsm)
