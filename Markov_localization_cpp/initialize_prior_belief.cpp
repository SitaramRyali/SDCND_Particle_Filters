// Markov_localization_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

using std::vector;

// initialize priors assuming vehicle at landmark +/- 1.0 meters position stdev
vector<float> initialize_priors(int map_size, vector<float> landmark_positions,
	float position_stdev);

int main() {
	// set standard deviation of position
	float position_stdev = 1.0f;

	// set map horizon distance in meters 
	int map_size = 25;

	// initialize landmarks
	vector<float> a;
	a.push_back(90);
	//std::cout<<"a size is:"<<a.size()<<'\n';

	vector<float> landmark_positions{ 5, 10, 20 };
	//std::cout<<"l size is:"<<landmark_positions.size()<<'\n';

	// initialize priors
	vector<float> priors = initialize_priors(map_size, landmark_positions,
		position_stdev);

	// print values to stdout 
	for (int p = 0; p < priors.size(); ++p) {
		std::cout << priors[p] << std::endl;
	}

	return 0;
}

// TODO: Complete the initialize_priors function
vector<float> initialize_priors(int map_size, vector<float> landmark_positions,
	float position_stdev) {

	// initialize priors assuming vehicle at landmark +/- 1.0 meters position stdev

	// set all priors to 0.0
	vector<float> priors(map_size, 0.0);
	int num_pos = landmark_positions.size();
	//std::cout<<"l size again is:"<<num_pos<<'\n';
	int total_pos = num_pos * (2 * position_stdev + 1);
	float prob_each_pos = 1.0 / total_pos;
	// TODO: YOUR CODE HERE
	for (int i = 0; i < map_size; i++)
	{
		priors[i] = 0;

		for (int j = 0; j < num_pos; j++)
		{
			if (i == landmark_positions[j] - 1 || (i == landmark_positions[j]) || (i == landmark_positions[j] + 1))
			{
				priors[i] = prob_each_pos;
			}

		}

	}


	return priors;
}