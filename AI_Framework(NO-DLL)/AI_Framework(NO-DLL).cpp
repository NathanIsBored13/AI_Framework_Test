#include "TrainingPool.h"

#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vecA = std::vector<int>{ 1, 5, 5, 1 };
	std::vector<TrainingPool::TrainingSample> samples = std::vector<TrainingPool::TrainingSample>
	{
		TrainingPool::TrainingSample(std::vector<float>{1}, std::vector<float>{0}),
		TrainingPool::TrainingSample(std::vector<float>{0}, std::vector<float>{1}),
	};
	TrainingPool p(2, vecA, samples);
	std::vector<float> vecB = std::vector<float>{ 0.5, 0.5 };
	for (int i = 0; i < 10; i++)
		p.Train(0.01);
}