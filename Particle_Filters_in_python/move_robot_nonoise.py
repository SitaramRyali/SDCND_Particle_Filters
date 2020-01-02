from robot_class import robot,eval

from math import *
import random

myrobot = robot()
##set a position of the robot
#myrobot.set(10.0,10.0,0.0)

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
