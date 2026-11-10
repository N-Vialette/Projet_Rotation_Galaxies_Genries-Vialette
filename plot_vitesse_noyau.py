import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("vitesse.csv")

r = data[:, 0]
v = data[:, 1]
v_exact = data[:, 2]

plt.figure()

plt.plot(r, v, label="Numérique",)
plt.plot(r,v_exact, label="Analytique")
plt.xlabel("Rayon $r$ (kpc)")
plt.ylabel("Vitesse $V_c$ (km/s)")
plt.title("Courbes de vitesse")
plt.grid()
plt.legend()

plt.savefig("courbes_vitesse.png")
plt.show()