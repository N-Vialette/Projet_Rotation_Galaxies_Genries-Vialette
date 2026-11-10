import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("noyau.csv")

x = data[:, 0]
k = data[:, 1]


plt.figure()

plt.plot(x, k)

plt.xlabel("x")
plt.ylabel("Noyau")
plt.title("Noyau")
plt.grid()
plt.xlim(0, 3)
plt.ylim(-5,10)

plt.savefig("courbe_noyau.png")
plt.show()