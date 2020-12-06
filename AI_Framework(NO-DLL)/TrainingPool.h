#include "Neural_Network.h"

#include <vector>

#pragma once
class TrainingPool
{
public:
	struct TrainingSample
	{
	public:
		std::vector<float> input, output;
		TrainingSample(std::vector<float> input, std::vector<float> output) : input(input), output(output) {}
	};
	TrainingPool(int, std::vector<int>&, std::vector<TrainingSample>&);
	TrainingPool(const TrainingPool&) = delete;
	~TrainingPool();
	Neural_Network GetBestNetwork();
	void Train(float);
private:
	int count, best = -1;
	Neural_Network* networks;
	std::vector<TrainingSample> samples;
};