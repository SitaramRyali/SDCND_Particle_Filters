from math import sqrt

obs_v = [(6,3),(2,2),(0,5)]
map_v = [(5,3),(2,1),(6,1),(7,4),(4,7)]

mapped_v = []
rmse = 1000.0

for obs_c in obs_v:
    rmse = 1000.0
    for map_c in map_v:
        x_diff = obs_c[0]-map_c[0]
        y_diff = obs_c[1]-map_c[1]
        rmse_c = sqrt((x_diff**2)+(y_diff**2))
        if(rmse_c<rmse):
            nearest_coord = map_c
            rmse =rmse_c
    mapped_v.append(nearest_coord)
