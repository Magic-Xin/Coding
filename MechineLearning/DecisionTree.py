import numpy as np


def fittree(x, y, feature_count, epsilon):
    (j, s, minval, c1, c2) = divide(x, y, feature_count)
    tree = {"feature": j, "value": x[s, j], "left": None, "right": None}
    if minval < epsilon or len(y[np.where(x[:, j] <= x[s, j])]) <= 1:
        tree["left"] = c1
    else:
        tree["left"] = fittree(x[np.where(x[:, j] <= x[s, j])], y[np.where(
            x[:, j] <= x[s, j])], feature_count, epsilon)
    if minval < epsilon or len(y[np.where(x[:, j] > s)]) <= 1:
        tree["right"] = c2
    else:
        tree["right"] = fittree(x[np.where(x[:, j] > x[s, j])], y[np.where(
            x[:, j] > x[s, j])], feature_count, epsilon)
    return tree


def divide(x, y, feature_count):
    cost = np.zeros((feature_count, len(x)))
    for i in range(feature_count):
        for k in range(len(x)):
            value = x[k, i]
            y1 = y[np.where(x[:, i] <= value)]
            c1 = np.mean(y1)
            y2 = y[np.where(x[:, i] > value)]
            c2 = np.mean(y2)
            y1[:] = y1[:]-c1
            y2[:] = y2[:]-c2
            cost[i, k] = np.sum(y1*y1) + np.sum(y2*y2)
    cost_index = np.where(cost == np.min(cost))
    j = cost_index[0][0]
    s = cost_index[1][0]
    c1 = np.mean(y[np.where(x[:, j] <= x[s, j])])
    c2 = np.mean(y[np.where(x[:, j] > x[s, j])])
    return j, s, cost[cost_index], c1, c2


if __name__ == '__main__':
    x = np.array([[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]]).T
    y = np.array([4.50, 4.75, 4.91, 5.34, 5.80, 7.05, 7.90, 8.23, 8.70, 9.00])
    print(fittree(x, y, 1, 0.2))
