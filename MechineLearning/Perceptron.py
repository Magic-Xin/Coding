# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.lines import Line2D

def perceptron(dataSet,loop_max=100):
    eta=1
    features=dataSet.shape[1]-1
    w=np.array([x*0 for x in range(0,features)])
    b=0
    for times in range(loop_max):
        for d in dataSet:
            x=d[:-1]
            y=d[-1]
            if y*(np.dot(w,x)+b)<=0:
                w=w+eta*y*x
                b=b+eta*y
    return w,b

# 可视化结果
def plotResult2(dataSet, weight, bias):
    fig = plt.figure()
    axes = fig.add_subplot(111)

    type1_x1=dataSet[dataSet[:,-1]==-1][:,:-1][:,0].tolist() 
    type1_x2=dataSet[dataSet[:,-1]==-1][:,:-1][:,1].tolist()
    type2_x1=dataSet[dataSet[:,-1]==1][:,:-1][:,0].tolist()
    type2_x2=dataSet[dataSet[:,-1]==1][:,:-1][:,1].tolist()

    axes.scatter(type1_x1, type1_x2, marker='x', s=20, c='red')
    axes.scatter(type2_x1, type2_x2, marker='o', s=20, c='blue')

    y = (0.1 * -weight[0] / weight[1] + -bias / weight[1], 4.0 * -weight[0] / weight[1] + -bias / weight[1])
    axes.add_line(Line2D((0.1, 4.0), y, linewidth=1, color='blue'))

    plt.xlabel('X')
    plt.ylabel('Y')
    plt.show()

if __name__ == '__main__':
    dataSet=np.array([[-1,0,1],[0,1,1],[1,0,-1],[0,-1,-1]])

    w,b=perceptron(dataSet)
    print('w:',w,'b:',b)
    print()

    plotResult2(dataSet, w.reshape((-1,1)), b)