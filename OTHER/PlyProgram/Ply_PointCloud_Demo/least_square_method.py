import numpy as np
from mayavi import mlab


def show_mayavi(x, y, z, res):
    fig = mlab.figure(bgcolor=(1, 1, 1), size=(640, 480))
    mlab.outline(color=(0, 0, 0))

    res = np.asarray(res)
    xx, yy = np.mgrid[-10:10:0.5, -10:10:0.5]
    zz = res[0] * xx + res[1] * yy + res[2]

    z /= 4

    mlab.surf(xx, yy, zz, color=(0, 0, 1), warp_scale=.25, representation='wireframe', line_width=0.5)
    mlab.points3d(x, y, z, color=(1, 0, 0), scale_factor=.3, figure=fig)

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


def LSM(x, y, z):
    tmp_a = []
    tmp_b = []
    for i in range(len(x)):
        tmp_a.append([x[i], y[i], 1])
        tmp_b.append(z[i])
    bt = np.matrix(tmp_b).T
    a = np.matrix(tmp_a)
    res = (a.T * a).I * a.T * bt
    print('平面拟合结果为：z = %.3f * x + %.3f * y + %.3f' % (res[0], res[1], res[2]))
    return res


if __name__ == '__main__':
    _x, _y, _z = random_point(2, 5, 6)
    _lsm = LSM(_x, _y, _z)

    show_mayavi(_x, _y, _z, _lsm)

