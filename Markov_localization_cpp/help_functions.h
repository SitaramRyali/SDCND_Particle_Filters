#ifndef HELP_FUNCTIONS_H
#define HELP_FUNCTIONS_H

#include <math.h>

constexpr static float M_PI = 3.14159265358979323846;
class Helpers {
public:
	// definition of one over square root of 2*pi:
	//float M_PI = 3.14159265358979323846;

	constexpr static float STATIC_ONE_OVER_SQRT_2PI = 1 / (2 * M_PI);

	/**
	 * normpdf(X,mu,sigma) computes the probability function at values x using the
	 * normal distribution with mean mu and standard deviation std. x, mu and
	 * sigma must be scalar! The parameter std must be positive.
	 * The normal pdf is y=f(x,mu,std)= 1/(std*sqrt(2pi)) e[ -(x−mu)^2 / 2*std^2 ]
	 */
	static float normpdf(float x, float mu, float std_d) {
		return (STATIC_ONE_OVER_SQRT_2PI / std_d) * exp(-0.5 * pow((x - mu) / std_d, 2));
	}
};

#endif  // HELP_FUNCTIONS_H