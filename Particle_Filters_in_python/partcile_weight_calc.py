from math import pi,exp
obs_v = [(6,3),(2,2),(0,5)]
stdv_pos = 0.3
#this mapped vector is result of earlier nearest neihbour calculations
mapped_v = [(5, 3), (2, 1), (2, 1)]

def multivariate_gau_prob(obs_v,mapped_v,stdv_pos):
    gaussian_prob = []
    denom_value = 1/(2*pi*stdv_pos*stdv_pos)
    for i in range(len(obs_v)):
        obs_c = obs_v[i]
        mapped_c =mapped_v[i]
        x_component = pow(obs_c[0]-mapped_c[0],2)/(2*pow(stdv_pos,2))
        y_component = pow(obs_c[1]-mapped_c[1],2)/(2*pow(stdv_pos,2))
        res = denom_value*exp(-(x_component+y_component))
        gaussian_prob.append(res)
    return  gaussian_prob
val = multivariate_gau_prob(obs_v,mapped_v,stdv_pos)
print(val)