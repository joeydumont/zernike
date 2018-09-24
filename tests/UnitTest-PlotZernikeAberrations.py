# ------------------------------- Information ------------------------------- #
# Author:       Joey Dumont                    <joey.dumont@gmail.com>        #
# Created:      Sep. 24th, 2018                                               #
# Description:  Plot the Zernike aberrations computed in                      #
#                UnitTest-ZernikePolynomials.cpp.                             #
# --------------------------------------------------------------------------- #

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.axes_grid1 import make_axes_locatable

# -- Coordinates
r     = np.loadtxt("rho.dat")
theta = np.loadtxt("theta.dat")
R, Th = np.meshgrid(r,theta)
X     = R*np.cos(Th)
Y     = R*np.sin(Th)

# -- Plots.

for i in range(1,31):
    data_polynomials = np.loadtxt("zernike-{}.dat".format(i))
    data_aberrations = np.loadtxt("zernike-aberrations-{}.dat".format(i))
    plt.figure(figsize=(6,2))
    plt.subplot2grid((1,2),(0,0))
    plt.pcolormesh(X,Y,np.transpose(data_polynomials),cmap="viridis")
    plt.gca().set_aspect('equal')
    ax = plt.subplot2grid((1,2),(0,1))
    im = plt.pcolormesh(X,Y,np.transpose(data_aberrations),cmap="viridis")
    plt.gca().set_aspect('equal')

    divider = make_axes_locatable(ax)
    cax     = divider.append_axes("right", size="5%", pad=0.1)
    cbar    = plt.colorbar(im, cax=cax)
    cbar.formatter.set_powerlimits((0,0))
    cbar.update_ticks()

plt.show()
