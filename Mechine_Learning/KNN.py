from numpy import *
from operator import itemgetter
import matplotlib.pyplot as plt

def file2matrix(filename):
    file = open(filename)
    arraylines = file.readlines()
    numberoflines = len(arraylines) - 1
    returnMat = zeros((numberoflines, 2))
    classLabel = []
    index = 0
    for line in arraylines[1:]:
        line = line.strip()
        lis = line.split(' ')
        returnMat[index, :] = lis[0:2]
        classLabel.append(int(lis[-1])+1)
        index += 1
    return returnMat, classLabel

def classify0(inX, dataSet, labels, k):
    dataSetSize = dataSet.shape[0]
    diffMat = tile(inX, (dataSetSize, 1)) - dataSet
    sqdiffMat = diffMat ** 2
    sqDistance = sqdiffMat.sum(axis=1)
    dis = sqDistance ** 0.5
    sortedDisIndex = dis.argsort()
    classCount = {}
    for i in range(k):
        voteLabel = labels[sortedDisIndex[i]]
        classCount[voteLabel] = classCount.get(voteLabel, 0)+1
    sortedclassCount = sorted(
        classCount.items(), key=itemgetter(1), reverse=True)
    return sortedclassCount[0][0]


def ClassTest():
    testratio = 0.15
    DataMat, Labels = file2matrix('/Users/xinyu/Desktop/Coding/MechineLearning/watermelon.txt')
    m = DataMat.shape[0]
    numTest = int(m*testratio)
    errorCount = 0.0
    for i in range(numTest):
        classifierRes = classify0(
            DataMat[i, :], DataMat[numTest:m, :], Labels[numTest:m], 3)
        print("predict: %d, real: %d" %
              (classifierRes-1, Labels[i]-1))
        if classifierRes != Labels[i]:
            errorCount += 1.0
    print("wrong rate: %.5f" % (errorCount/float(numTest)))

ClassTest()
group, labels = file2matrix('/Users/xinyu/Desktop/Coding/MechineLearning/watermelon.txt')
plt.scatter(group[:, 0], group[:, 1], 35.0*array(labels), 35.0*array(labels))
plt.show()
