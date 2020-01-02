
from math import pi
#import random
from robot_class import robot

myrobot = robot()

#initiate robot with noise in measurements
#forward_noise = 5.0, turn_noise = 0.1, sense_noise = 5.0
myrobot.set_noise(5.0,0.1,5.0)
#starts at coordinates 30, 50 heading north (pi/2).
myrobot.set(30.0,50.0,pi/2)
print(myrobot)
print(myrobot.sense())
##move the robot 10m forward
#myrobot = myrobot.move(0.0,10.0)

##turn clockwise by pi/2, move 15 m, and sense
myrobot = myrobot.move(-pi/2,15.0)
print(myrobot)
print(myrobot.sense())

##turn the robot pi/2 further and move 10m forward
myrobot = myrobot.move(-pi/2,10.0)
print(myrobot)
##generate measurements.
print(myrobot.sense())
