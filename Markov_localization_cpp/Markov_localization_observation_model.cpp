/*For each observation:
..determine if a pseudo range vector exists for the current pseudo position x
..if the vector exists, extract and store the minimum distance, element 0 of the sorted vector, and remove that element (so we don't re-use it). This will be passed to norm_pdf
..if the pseudo range vector does not exist, pass the maximum distance to norm_pdf
..use norm_pdf to determine the observation model probability
..return the total probability*/


#include <algorithm>
#include <iostream>
#include <vector>

#include "help_functions.h"

using std::vector;

// function to get pseudo ranges
vector<float> pseudo_range_estimator(vector<float> landmark_positions,
	float pseudo_position);

// observation model: calculate likelihood prob term based on landmark proximity
float observation_model(vector<float> landmark_positions,
	vector<float> observations, vector<float> pseudo_ranges,
	float distance_max, float observation_stdev);

int main() {
	// set observation standard deviation:
	float observation_stdev = 1.0f;

	// number of x positions on map
	int map_size = 25;

	// set distance max
	float distance_max = map_size;

	// define landmarks
	vector<float> landmark_positions{ 5, 10, 12, 20 };

	// define observations
	vector<float> observations{ 5.5, 13, 15 };

	// step through each pseudo position x (i)
	for (int i = 0; i < map_size; ++i) {
		float pseudo_position = float(i);

		// get pseudo ranges
		vector<float> pseudo_ranges = pseudo_range_estimator(landmark_positions,
			pseudo_position);

		//get observation probability
		float observation_prob = observation_model(landmark_positions, observations,
			pseudo_ranges, distance_max,
			observation_stdev);
		//print to stdout
		std::cout << observation_prob << std::endl;
	}

	return 0;
}

// TODO: Complete the observation model function
// calculates likelihood prob term based on landmark proximity
float observation_model(vector<float> landmark_positions,
	vector<float> observations, vector<float> pseudo_ranges,
	float distance_max, float observation_stdev) {
	float distance_prob=1.0;
	// YOUR CODE HERE
	float dist;

	for (int i = 0; i < observations.size(); i++)
	{
		if (pseudo_ranges.size() > 0)
		{
			dist = pseudo_ranges[0];
			//erase the 0th element
			pseudo_ranges.erase(pseudo_ranges.begin());
		}
		else
		{
			dist = distance_max;
		}
		distance_prob *= Helpers::normpdf(observations[i],dist,observation_stdev) * (2 * M_PI) / sqrt(2 * M_PI);
		
	}
	


	return distance_prob;
}

vector<float> pseudo_range_estimator(vector<float> landmark_positions,
	float pseudo_position) {
	// define pseudo observation vector
	vector<float> pseudo_ranges;

	// loop over number of landmarks and estimate pseudo ranges
	for (int l = 0; l < landmark_positions.size(); ++l) {
		// estimate pseudo range for each single landmark 
		// and the current state position pose_i:
		float range_l = landmark_positions[l] - pseudo_position;

		// check if distances are positive: 
		if (range_l > 0.0f) {
			pseudo_ranges.push_back(range_l);
		}
	}

	// sort pseudo range vector
	sort(pseudo_ranges.begin(), pseudo_ranges.end());

	return pseudo_ranges;
}