from math import sin,cos,pi
import numpy as np

angle = -pi/2
car_coord = (0,-4,angle)
particle_coord = (4,5)

def conv_car_to_map(car_coord,particle_coord):
    x,y,theta = car_coord
    xp,yp = particle_coord
    conv_mat = np.array([[cos(theta),-sin(theta),xp],[sin(theta),cos(theta),yp],[0,0,1]])
    meas_vect = np.array([x,y,1])
    return np.dot(conv_mat,meas_vect)

print(conv_car_to_map(car_coord,particle_coord))