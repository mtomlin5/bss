# -*- coding: utf-8 -*-
"""
An iterative ICA algorithm based on

    C. Jutten and J. Herault, "Blind separatin of sources, Part I: 
    An adaptive algorithm based on neuromimetic architecture", 
    Signal Processing 24 (1991).
"""

import numpy as np
import matplotlib.pyplot as plt

# Generate cos wave and Gaussian noise sources
N  = 16000
t  = np.linspace(0,1,N)
f  = 1000.
s1 = np.cos(2*np.pi*f*t)
s2 = np.random.normal(1,1,N) # mean = 1, std = 1

fig, ax = plt.subplots(1,2)
ax[0].hist(s1)
ax[1].hist(s2)
ax[0].set_title("Cos")
ax[1].set_title("Gaussian Noise")
fig.suptitle("Input Signal Histograms")
plt.tight_layout()

s = np.concatenate(( s1.reshape((1,N)),
                     s2.reshape((1,N))       ))

# Mix sources
A = np.array([
    [0.5, 0.1],
    [0.2, 0.3]
    ])

E = A@s
E1 = E[0,:]
E2 = E[1,:]

# Demix with HJ algorithm
c12, c21 = 0.1, 0.                          # demixing coefficients
sp1, sp2 = np.zeros((N,)), np.zeros((N,))   # predicted/separated signals
f        = lambda x: x**3                   # nonlinear function 1
g        = lambda x: np.arctan(x)           # nonlinear function 2
lr       = 1e-2                             # learning rate
cm1, cm2 = 0., 0.                           # Cumulative moving average (CMA)
eta      = 1e-3                             # CMA rate (1e-3 ~ 1000 samples)
for i in range(N):
    # Calculate moving average
    cm1 = cm1*(1-eta) + eta*E1[i]
    cm2 = cm2*(1-eta) + eta*E2[i]
    
    # Subtract mean from the signals
    e1 = E1[i] - cm1
    e2 = E2[i] - cm2
    
    # Separate signals based on demixing matrix C
    sp1[i] = (e1 - c12*e2)/(1 - c12*c21)
    sp2[i] = (e2 - c21*e1)/(1 - c12*c21)
    
    # Update demixing matrix C
    c12 = c12 + lr*f(sp1[i])*g(sp2[i])
    c21 = c21 + lr*f(sp2[i])*g(sp1[i])
    
    if (c12*c21>1):
        print("Error: c12*c21 must be smaller than 1  for stable recovery")


# Observe: signals are recovered up to a constant factor
fig, ax = plt.subplots(1,2)
ax[0].plot(s1[N-100:N])
ax[1].plot(sp1[N-100:N])
ax[0].set_title("Original")
ax[1].set_title("Recovered")
fig.suptitle("Signal Recovery")
plt.tight_layout()


fig, ax = plt.subplots(2,2)
ax[0,0].hist(s1)
ax[0,1].hist(s2)
ax[0,0].set_title("Original Cos")
ax[0,1].set_title("Original Gaussian Noise")
ax[1,0].hist(sp1)
ax[1,1].hist(sp2)
ax[1,0].set_title("Recovered Cos")
ax[1,1].set_title("Recovered Gaussian Noise")
fig.suptitle("Original/Recovered Histograms")
plt.tight_layout()
