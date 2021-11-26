import os
import module
import torch
import torchvision
import numpy as np
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
from matplotlib.ticker import MaxNLocator

batchSize = 5
numPrint = 2000
modelPath = './model/model.pth'
Epoch = 20


def run():
    alexNet = module.AlexNet()
    alexNet.cuda()

    if os.path.exists(modelPath):
        print('load model')
        alexNet = torch.load(modelPath)
        print('load model success')
    else:
        print('model not found')

    train_losses, test_accuracy = train(alexNet)

    x = np.arange(1, len(train_losses)+1) * numPrint / 10000
    fig, ax = plt.subplots()
    ax2 = ax.twinx()
    ax.plot(x, train_losses, '-', label='train loss')
    ax2.plot(x, test_accuracy, '-r', label='test accuracy')
    fig.legend(frameon=False)
    ax.set_xlabel('epoch')
    plt.gca().xaxis.set_major_locator(MaxNLocator(integer=True))
    fig.show()


def train(alexNet):
    transform = transforms.Compose(
        [transforms.ToTensor(),
         transforms.Normalize((0.5, 0.5, 0.5), (0.5, 0.5, 0.5))])

    trainset = torchvision.datasets.CIFAR10(root='./data', train=True, download=True, transform=transform)
    trainloader = torch.utils.data.DataLoader(trainset, batch_size=batchSize, shuffle=True, num_workers=2)

    testset = torchvision.datasets.CIFAR10(root='./data', train=False, download=True, transform=transform)
    testloader = torch.utils.data.DataLoader(testset, batch_size=batchSize, shuffle=False, num_workers=2)

    criterion = torch.nn.CrossEntropyLoss()
    optimizer = torch.optim.SGD(alexNet.parameters(), lr=0.001, momentum=0.9)

    train_losses = []
    test_accuracy = []

    for e in range(Epoch):
        running_loss = 0
        for i, data in enumerate(trainloader, 0):
            inputs, labels = data
            inputs, labels = inputs.cuda(), labels.cuda()
            optimizer.zero_grad()
            outputs = alexNet(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            running_loss += loss.item()
            if i % numPrint == numPrint - 1:
                print('epoch: %d\t batch: %d\t loss: %.3f' % (e + 1, i + 1, running_loss / (batchSize * numPrint)))
                train_losses.append(running_loss / (batchSize * numPrint))
                running_loss = 0
                test_accuracy.append(test(alexNet, testloader))
    torch.save(alexNet, modelPath)
    return train_losses, test_accuracy


def test(alexNet, testloader):
    correct = 0
    total = 0
    with torch.no_grad():
        for data in testloader:
            images, labels = data
            images, labels = images.cuda(), labels.cuda()
            outputs = alexNet(images)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
    print('Accuracy of the network on the 10000 test images: %d %%' % (100.0 * correct / total))
    return 100.0 * correct / total


if __name__ == '__main__':
    run()
