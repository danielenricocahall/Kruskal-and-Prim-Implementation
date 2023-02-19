import os
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import numpy as np


def log(n, k, m):
    return k * np.log(n) + m


def linearithmic(n, k, m):
    return k * n * np.log(n) + m


def squared_linearithmic(n, k, m):
    return k * np.square(n) * np.log(n) + m


def square(n, k, m):
    return k * np.square(n) + m


def linear(n, k, m):
    return k * n


def cube(n, k, m):
    return k * np.power(n, 3) + m


### Read .csv file and append to list
df = pd.read_csv("Results_0.3.csv", index_col=0, usecols=[0, 1, 2, 3])

w, x, y, z = zip(*[tuple(x) for x in df.to_records()])
x = np.array(w)
y = np.array(y)
z = np.array(z)

print(y)

plt.plot(w, y, label="Prim");
plt.plot(w, z, label="Kruskal");
prim_popt, prim_pcov = curve_fit(cube, w, y)
plt.plot(w, cube(w, *prim_popt), \
         '*', label="Prim Fit: " + \
                    str(round(prim_popt[0], 9)) + "|V|^3 + " + \
                    str(round(prim_popt[1], 9)))

kruskal_popt, kruskal_pcov = curve_fit(cube, w, z)
plt.plot(w, cube(w, *kruskal_popt), \
         '*', label="Kruskal Fit: " + \
                    str(round(kruskal_popt[0], 9)) + "|V|^3  +  " + \
                    str(round(kruskal_popt[1], 9)))
plt.xlabel('V')
plt.ylabel('Time (s)')
plt.title('Profiling Results (p = 0.3)')
plt.legend(loc='upper left')
plt.show()
