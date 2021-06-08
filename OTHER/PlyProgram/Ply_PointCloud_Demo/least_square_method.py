import numpy as np
from mayavi import mlab


def show_mayavi(x, y, z, _x):
    mlab.figure(bgcolor=(1, 1, 1))
    mlab.outline(color=(0, 0, 0))

    xx = np.linspace(-10, 10, 100)
    yy = np.linspace(-10, 10, 100)
    xx, yy = np.meshgrid(xx, yy)
    zz = _x[0, 0] * xx + _x[1, 0] * yy + _x[2, 0]

    mlab.surf(xx, yy, zz, color=(0, 0, 1), warp_scale=0.3, representation='wireframe', line_width=0.5)
    mlab.points3d(x, y, z, color=(1, 0, 0), scale_factor=.25)

    axes = mlab.axes(color=(0, 0, 0), nb_labels=5)
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


def gen_data():
    x, y, z = random_point(1, 1, 1)
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
        r = r + (_x[0, 0] * x[i] + _x[1, 0] * y[i] + _x[2, 0] - z[i]) ** 2
    print('方差为：%.*f' % (3, r))

    show_mayavi(x, y, z, _x)


if __name__ == '__main__':
    gen_data()
