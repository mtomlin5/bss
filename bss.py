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

# same wave recorded by a 4 microphone array
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


# Experiment 1: Separate two different sources

# Wave 1
r1     = 10
theta1 = np.pi/4
phi1   = np.pi/3

x1,y1,z1 = s2c(r1,theta1,phi1)

f1 = 0.01*fs

# Wave 2
r2     = 15
theta2 = np.pi/3
phi2   = np.pi/5

x2,y2,z2 = s2c(r2,theta2,phi2)

f2 = 0.02*fs

# Microphone measurements
m10  = sWave(x1+.05,y1,z1,f1) + sWave(x2+.05,y2,z2,f2) 
m01  = sWave(x1,y1+.05,z1,f1) + sWave(x2,y2+.05,z2,f2)
mn10 = sWave(x1-.05,y1,z1,f1) + sWave(x2-.05,y2,z2,f2)
m0n1 = sWave(x1,y1-.05,z1,f1) + sWave(x2,y2-.05,z2,f2)

plt.figure()
plt.plot(t,m10,t,m01,t,mn10,t,m0n1)


# Calculate xi
x00 = (m10 + m01 + mn10 + m0n1)/4.
x10 = (m10 - mn10)/2.
x01 = (m01 - m0n1)/2.









