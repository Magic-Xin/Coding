import os
import open3d as o3d
import numpy as np
import matplotlib.pyplot as plt


def load_ply(path):
    for root, dirs, files in os.walk(path):
        for file in files:
            if file.endswith(".ply"):
                ply_path = os.path.join(root, file)
                pcd = o3d.io.read_point_cloud(ply_path)
                points = np.asarray(pcd.points)
                colors = np.asarray(pcd.colors)

                for i in colors:
                    for j in range(3):
                        if i[j] > 0.15:
                            i[j] -= 0.15
                print(root.split('\\')[-1])
                filename = root.split('\\')[-1] + '_' + file
                matplotlib_render(points, colors, filename)


def matplotlib_render(points, colors, filename):
    fig = plt.figure()
    fig.canvas.manager.set_window_title(filename)
    ax = fig.add_subplot(1, 1, 1, projection='3d')
    ax.scatter(points[:, 0], points[:, 1], points[:, 2], c=colors)

    temp_min = np.min(points, axis=0)
    temp_max = np.max(points, axis=0)
    axis_min = np.min(temp_min)
    axis_max = np.max(temp_max)

    ax.set_xlim(axis_min, axis_max)
    ax.set_ylim(axis_min, axis_max)
    ax.set_zlim(axis_min, axis_max)
    plt.axis('off')
    ax.view_init(0, 0)
    if 'bag' in filename:
        ax.view_init(0, 45)
    elif 'cap' in filename:
        ax.view_init(130, -90)
    elif 'earphone' in filename:
        ax.view_init(140, -10)
    elif 'rocket' in filename:
        ax.view_init(90, -90)
    plt.tight_layout()
    # plt.show()
    plt.savefig(r'C:\\Users\\xyu20\\Desktop\\comparision\\pdf\\' + filename.replace('.ply', '.pdf'), dpi=800)
    # input("Press Enter to continue...")


def main():
    model_name = 'pistol'
    open_filepath = r'./outputs/partseg_eval/visualization/' + model_name + '/'
    # load_ply(open_filepath)
    load_ply(r'C:\\Users\\xyu20\\Desktop\\comparision\\')


if __name__ == '__main__':
    main()
