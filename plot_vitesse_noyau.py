import numpy as np
import matplotlib.pyplot as plt
from scipy.special import i0, i1, k0, k1 

rc=1
sigma=1e10
G = 4.3e-6
Mtot=2*np.pi*sigma*rc*rc


data_kt = np.loadtxt("vitesse_kt.csv")
data_exp = np.loadtxt("vitesse_exp.csv")

r_kt = data_kt[:, 0]
v_kt = data_kt[:, 1]
v_exact_kt = data_kt[:, 2]

r_exp = data_exp[:, 0]
v_exp = data_exp[:, 1]

y=r_exp/2*rc

v_exact_exp=np.sqrt((G*Mtot/rc)*2*(y**2)*(i0(y)*k0(y)-i1(y)*k1(y)))

plt.figure()

plt.plot(r_kt, v_kt, label="Numérique",)
plt.plot(r_kt,v_exact_kt, label="Analytique")
plt.xlabel("Rayon $r$ (kpc)")
plt.ylabel("Vitesse $V_c$ (km/s)")
plt.title("Courbes de vitesse")
plt.grid()
plt.legend()

plt.savefig("courbes_vitesse_kt.png")
plt.show()

plt.figure()

plt.plot(r_exp, v_exp, label="Numérique",)
plt.plot(r_exp,v_exact_exp, label="Analytique")
plt.xlabel("Rayon $r$ (kpc)")
plt.ylabel("Vitesse $V_c$ (km/s)")
plt.title("Courbes de vitesse")
plt.grid()
plt.legend()

plt.savefig("courbes_vitesse_exp.png")
plt.show()