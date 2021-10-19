import numpy as np
import mayavi.mlab as mlab
import open3d as o3d
from plyfile import PlyData


def read_ply(filepath):
    pcd = o3d.io.read_point_cloud(filepath)
    print(pcd)
    return pcd


def draw_ply(array_in, array_out):
    mlab.figure(bgcolor=(1, 1, 1), size=(640, 480))
    mlab.outline(color=(0, 0, 0))

    mlab.points3d(array_in[:, 0], array_in[:, 1], array_in[:, 2], color=(1, 0, 0), mode='point')
    mlab.points3d(array_out[:, 0], array_out[:, 1], array_out[:, 2], color=(0, 0, 1), mode='point')

    axes = mlab.axes(color=(0, 0, 0), nb_labels=5)
    axes.title_text_property.color = (0.0, 0.0, 0.0)
    axes.title_text_property.font_family = 'times'
    axes.label_text_property.color = (0.0, 0.0, 0.0)
    axes.label_text_property.font_family = 'times'
    mlab.gcf().scene.parallel_projection = True
    mlab.orientation_axes()
    mlab.show()


def pcFunc(pcd):
    pcd_new = o3d.geometry.PointCloud.remove_non_finite_points(pcd, remove_nan=True, remove_infinite=True)
    pcd_new = o3d.geometry.PointCloud.remove_radius_outlier(pcd_new, 2, 0.1)
    print("After radius: ")
    print(pcd_new[0])
    # pcd_new = o3d.geometry.PointCloud.remove_statistical_outlier(pcd_new[0], 3, 0.2)
    # print("After statistical: ")
    # print(pcd_new[0])
    return pcd_new[0]


def ransacFunc(pcd):
    plane_model, inliers = pcd.segment_plane(distance_threshold=.1, ransac_n=10, num_iterations=20)
    pcd_in = pcd.select_by_index(inliers)
    pcd_out = pcd.select_by_index(inliers, invert=True)
    return np.asarray(pcd_in.points), np.asarray(pcd_out.points)


if __name__ == '__main__':
    _pcd = read_ply('1.ply')
    _pcd = pcFunc(_pcd)
    _array_in, _array_out = ransacFunc(_pcd)
    draw_ply(_array_in, _array_out)
