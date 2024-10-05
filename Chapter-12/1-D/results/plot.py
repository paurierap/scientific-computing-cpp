# Plot solutions from ODE solver

import numpy as np
import matplotlib.pyplot as plt
from fig_config import *

file1 = "../solution_problem1.dat"
file2 = "../solution_problem2.dat"

x1, sol1 = [], []
x2, sol2 = [], []

def exact_sol1(x):
    return 0.5*x*(1-x)

def exact_sol2(x):
    return (4*np.exp(x)+np.exp(-4*x)) / (4*np.exp(np.pi)+np.exp(-4*np.pi)) - 5*np.sin(x) - 3*np.cos(x)

with open(file1, "r") as input:
    for line in input:
        data = line.split(", ")
        x1.append(float(data[0]))
        sol1.append(float(data[1]))

with open(file2, "r") as input:
    for line in input:
        data = line.split(", ")
        x2.append(float(data[0]))
        sol2.append(float(data[1]))

x1, sol1 = np.array(x1), np.array(sol1)
x2, sol2 = np.array(x2), np.array(sol2)

#figure_features()
fig = plt.figure(figsize=(10,6))
ax = plt.axes()
ax.set(xlabel="$x$", ylabel="$u(x)$")
#add_grid(ax)

ax.plot(x1, sol1)
ax.plot(x1, exact_sol1(x1), '--')
plt.show()