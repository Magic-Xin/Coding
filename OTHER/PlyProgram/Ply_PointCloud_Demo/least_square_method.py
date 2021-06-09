import numpy as np
from mayavi import mlab
import matplotlib.pyplot as plt


def show_matplotlib(x, y, z, res):
    plt.figure()
    ax = plt.subplot(111, projection='3d')
    ax.scatter(x, y, z, color='b')

    x_lim = ax.get_xlim()
    y_lim = ax.get_ylim()
    X, Y = np.meshgrid(np.arange(x_lim[0], x_lim[1]),
                       np.arange(y_lim[0], y_lim[1]))
    Z = np.zeros(X.shape)
    for r in range(X.shape[0]):
        for c in range(X.shape[1]):
            Z[r, c] = res[0] * X[r, c] + res[1] * Y[r, c] + res[2]
    ax.plot_wireframe(X, Y, Z, color='k')

    ax.set_xlabel('x')
    ax.set_ylabel('y')
    ax.set_zlabel('z')
    plt.show()


def show_mayavi(x, y, z, res):
    fig = mlab.figure(bgcolor=(1, 1, 1), size=(640, 480))
    mlab.outline(color=(0, 0, 0))

    res = np.asarray(res)
    xx, yy = np.mgrid[min(z):max(z):50j, min(z):max(z):50j]
    zz = res[0] * xx + res[1] * yy + res[2]

    mlab.surf(xx, yy, zz, color=(0, 0, 1), warp_scale=.25, representation='wireframe', line_width=0.5)
    mlab.points3d(x, y, z, color=(1, 0, 0), mode='point', figure=fig)

    axes = mlab.axes(color=(0, 0, 0), nb_labels=5)
    axes.title_text_property.color = (0.0, 0.0, 0.0)
    axes.title_text_property.font_family = 'times'
    axes.label_text_property.color = (0.0, 0.0, 0.0)
    axes.label_text_property.font_family = 'times'
    mlab.gcf().scene.parallel_projection = True
    mlab.orientation_axes()
    mlab.show()


def random_point(a, b, c):
    x = np.random.uniform(-10, 10, size=50)
    y = np.random.uniform(-10, 10, size=50)
    z = (a * x + b * y + c) + np.random.normal(-1, 1, size=50)
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
    _x, _y, _z = random_point(2, 3, 5)
    _lsm = LSM(_x, _y, _z)

    show_matplotlib(_x, _y, _z, _lsm)
    show_mayavi(_x, _y, _z, _lsm)

