from math import pi
import random
from robot_class import robot

myrobot = robot()
myrobot = myrobot.move(0.1,5.0)
Z = myrobot.sense()

print(Z)
print(myrobot)


N =1000
p = []

for _ in range(N):
    x = robot()
    x.set_noise(0.05,0.05,5.0)
    p.append(x)
    
p2 =[]
for i in range(N):
    p2.append(p[i].move(0.1,5.0))

p = p2

# Now we want to give weight to our 
# particles. This program will print a
# list of 1000 particle weights.
w =[]
W = 0
for i in range(N):
    weight = p[i].measurement_prob(Z)
    w.append(weight)
    W += weight

# You should make sure that p3 contains a list with particles
# resampled according to their weights.
# Also, DO NOT MODIFY p.
#normalize weights
w_norm = []
for i in range(N):
    w_norm.append(w[i]/W)

p3 = []
for i in range(N):
    choice  = random.choice(w_norm)
    id_c = w_norm.index(choice)
    p3.append(p[id_c])


