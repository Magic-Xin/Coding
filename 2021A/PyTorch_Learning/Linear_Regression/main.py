import torch
import numpy as np
import matplotlib.pyplot as plt


def generate_dataset(display_plt=False):
    num_input = 1
    num_examples = 1000
    true_w = 5.3
    true_b = 0.8
    features = torch.randn(num_examples, num_input, dtype=torch.float32)
    labels = true_w * features + true_b
    labels += torch.tensor(np.random.normal(0, 2, size=labels.size()), dtype=torch.float32)

    if display_plt:
        plt.scatter(features.numpy(), labels.numpy(), c=features[:, 0].numpy())
        plt.show()

    data = {"x": features, "y": labels}
    return data


class LinearRegressionNN(torch.nn.Module):
    def __init__(self):
        super().__init__()
        self.linear = torch.nn.Linear(1, 1)

    def forward(self, x):
        out = self.linear(x)
        return out


class Model:
    def __init__(self):
        self.learning_rate = 0.005
        self.epochs = 500
        self.loss_func = torch.nn.MSELoss()
        self.model = LinearRegressionNN()
        self.optimizer = torch.optim.SGD(self.model.parameters(), lr=self.learning_rate)

    def compare_train(self, _data):
        x = _data["x"]
        y = _data["y"]
        for epoch in range(self.epochs):
            prediction = self.model(x)
            loss = self.loss_func(prediction, y)

            self.optimizer.zero_grad()
            loss.backward()
            self.optimizer.step()

            if (epoch + 1) % 5 == 0:
                print("epoch: {}, loss: {:.4f}".format(epoch+1, loss.item()))

        return self.model(x).detach().numpy()


model = Model()
_data = generate_dataset()
predicted = model.compare_train(_data)

plt.plot(_data["x"], _data["y"], 'ro', label='original data')
plt.plot(_data["x"], predicted, label="predicted line")
plt.legend()
plt.show()
