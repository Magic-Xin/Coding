import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_excel('作业1数据.xlsx')
# print(df)
train_time = df.iloc[:,0]
train_x1 = df.iloc[:,1]
train_x2 = df.iloc[:,2]

x1 = np.array(train_x1)
x2 = np.array(train_x2)
t1 = np.array(train_time)
# print('x is :\n',x)

#x1 x2
guess_1 = np.polyfit(x1,x2,1)
print('guess_1 is : \n' , guess_1)

guess_1_final = np.poly1d(guess_1)
print('guess_1_final is : \n' , guess_1_final)

#拟合 Y
yvals = guess_1_final(x1)
print('yvals is : \n' , yvals)

#画图
plot1 = plt.plot(x1, x2, 's',label='original values')
plot2 = plt.plot(x1, yvals, 'r',label='polyfit values')
plt.xlabel('x')
plt.ylabel('y')
plt.legend(loc=4) #指定legend的位置右下角
# plt.title('polyfitting')
plt.show()