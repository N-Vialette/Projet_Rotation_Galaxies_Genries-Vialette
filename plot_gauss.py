import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("Approx_gauss.csv")

r = data[:, 0]
v_exp = data[:, 1]
v_gauss = data[:, 2]
v_kt = data[:, 3]
v_toomre = data[:, 4]

plt.figure()

plt.plot(r, v_exp, label="Exponentiel",)
plt.plot(r, v_gauss, label="Gaussien",)
plt.plot(r, v_kt, label="Kuzmin-Toomre (n=1)")
plt.plot(r, v_toomre, label="Toomre (n=2)")

plt.xlabel("Rayon $r$ (kpc)")
plt.ylabel("Vitesse $V_c$ (km/s)")
plt.title("Courbes de rotation")
plt.grid()
plt.legend()
plt.xlim(0, 24)

plt.savefig("courbes_gauss.png")
plt.show()