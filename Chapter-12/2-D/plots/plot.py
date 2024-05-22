# Plot solutions from ODE solver

import numpy as np
import matplotlib.pyplot as plt
from fig_config import *

sol_file = "../solution_poisson.dat"
xgrid_file = "../x_grid.dat"
ygrid_file = "../y_grid.dat"

sol = []
xgrid = []
ygrid = []

def exact_sol(x, y):
    return np.exp(-(x*x + y*y))

# Load approximate solution
with open(sol_file, "r") as input:
    for line in input:
        data = line.split(" ")
        sol.append(np.array([float(x) for x in data[:-1]]))

# Load x grid
with open(xgrid_file, "r") as input:
    for line in input:
        data = line.split(" ")
        xgrid.append(np.array([float(x) for x in data[:-1]]))

# Load y grid
with open(ygrid_file, "r") as input:
    for line in input:
        data = line.split(" ")
        ygrid.append(np.array([float(x) for x in data[:-1]]))

sol, xgrid, ygrid = np.array(sol), np.array(xgrid), np.array(ygrid)

print("Max error between approx and exact solution is: ", abs(sol - exact_sol(xgrid, ygrid)).max())

#figure_features()
fig = plt.figure(figsize=(10,6))
ax = plt.axes()
ax = fig.add_subplot(111, projection='3d')

ax.plot_surface(xgrid, ygrid, sol)

ax.set_xlabel('$x$')
ax.set_ylabel('$y$')
ax.set_zlabel('$u(x,y)$')

plt.show()