# -*- coding: utf-8 -*-
"""
Basic simulator for blind source separation
"""

import numpy as np
import matplotlib.pyplot as plt

cs = 343       # speed of sound in air m/s
fs = 16e3      # sampling rate in Hz
T  = 0.1       # total observation time in s
N  = int(fs*T) # total number of points
t  = np.linspace(0,N-1,N) # time array

# spherical wave
def sWave(x,y,z,f):
    r = np.sqrt(x**2 + y**2 + z**2) # distance in m
    wavelength = f/cs;
    k = 2*np.pi/wavelength
    return np.cos(k*r - 2*np.pi*f*t/fs)/r

# convert spherical coordinates to cartesian
def s2c(r,theta,phi):
    x = r*np.cos(theta)*np.sin(phi)
    y = r*np.sin(theta)*np.sin(phi)
    z = r*np.cos(phi)
    return x,y,z

# same wave recorded by 4 microphones array
r     = 10
theta = np.pi/4
phi   = np.pi/3

x,y,z = s2c(r,theta,phi)

f = 0.01*fs

m1 = sWave(x+.05,y,z,f)
m2 = sWave(x,y+.05,z,f)
m3 = sWave(x-.05,y,z,f)
m4 = sWave(x,y-.05,z,f)

plt.figure()
plt.plot(t,m1,t,m2,t,m3,t,m4)