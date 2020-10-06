import numpy as np

x_data = (1, 4, 7)
y_data = (5, 9, 18)

def weights(xArr, yArr):
    xMat = np.mat(xArr)
    yMat = np.mat(yArr)

    xTx = xMat.T * xMat

    if np.linalg.det(xTx) == 0:
        return

    ws = xTx.I * xMat.T * yMat
    return ws

ws = weights(x_data, y_data)
print(ws)
