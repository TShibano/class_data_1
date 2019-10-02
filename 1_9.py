import numpy as np
import pandas as pd
from sklearn.linear_model import LinearRegression
from IPython.display import display
import matplotlib.pyplot as plt
# データの読み込み
data = pd.read_csv("1_7.txt")
# display(data)
# print(data.head())
# print(data.shape)
 
# 変数の獲得
# もう少し上手な仕方があると良いが
x = np.array(data.iloc[:, 1]).reshape(-1, 1)
y = np.array(data.iloc[:, 2]).reshape(-1, 1)
# print(x.shape)
plt.plot(x, y, 'o')
# Linear Regression
lr = LinearRegression().fit(x, y)
print("lr.coef_: {}".format(lr.coef_))
print("lr.intercept_: {}".format(lr.intercept_))
