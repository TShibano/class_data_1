import math
A = 50
T = 4
L = 10

time = [float(input()) for i in range(11)]

y = [0] * 11

for i in range(11):
    x = 2 * i
    y[i] = A * math.sin(2 * math.pi * (time[i] / T - x / L))

print(y)