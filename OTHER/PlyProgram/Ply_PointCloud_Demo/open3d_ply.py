import numpy as np
import open3d as o3d


def load_ply(filepath):
    pcd = o3d.io.read_point_cloud(filepath)
    pcd_new = o3d.geometry.PointCloud.remove_non_finite_points(pcd, remove_nan=True, remove_infinite=True)
    pcd_new = o3d.geometry.PointCloud.remove_radius_outlier(pcd_new, 3, 1)
    plane_model, inliers = pcd.segment_plane(distance_threshold=1, ransac_n=3, num_iterations=20)
    pcd_in = pcd.select_by_index(inliers)
    point_cloud = np.asarray(pcd.points)
    print(pcd_in)


if __name__ == '__main__':
    load_ply('./1.ply')
