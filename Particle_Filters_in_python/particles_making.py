## Our robot lives in a grid of 100 * 100 square world.
## The grid Cyclic which means when the robot fall off at one end it appears on the other end

# Now we want to create particles,
# p[i] = robot(). In this assignment, write
# code that will assign 1000 such particles
# to a list.
#
# Your program should print out the length
# of your list (don't cheat by making an
# arbitrary list of 1000 elements!)
from robot_class import robot
#import matplotlib.pyplot as plt

N =1000
p = []

for _ in range(N):
    x = robot()
    p.append(x)
    
p2 =[]
for i in range(N):
    p2.append(p[i].move(0.1,5.0))

p = p2
print(len(p))
#plt.show(p)
#print(p)
