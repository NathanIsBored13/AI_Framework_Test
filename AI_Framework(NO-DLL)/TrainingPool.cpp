#include "TrainingPool.h"

TrainingPool::TrainingPool(int count, std::vector<int>& structure, std::vector<TrainingSample>& samples) : count(count * 2), samples(samples), networks((Neural_Network*)malloc(sizeof(Neural_Network)* (count * 2)))
{
	for (int i = 0; i < this->count; i++)
		new(&networks[i]) Neural_Network(structure);
}

TrainingPool::~TrainingPool()
{
	for (int i = 0; i < count; i++)
		networks[i].~Neural_Network();
	free(networks);
}

Neural_Network TrainingPool::GetBestNetwork()
{
	return Neural_Network(networks[best]);
}

void TrainingPool::Train(float mutate)
{
	std::pair<int, float>* costs = new std::pair<int, float>[count];

	for (int i = 0; i < count; i++)
	{
		float cost = 0;
		for (size_t j = 0; j < samples.size(); j++)
		{
			networks[i].Propigate(samples[j].input);
			cost += networks[i].GetCost(samples[j].output);
		}
		new(&costs[i]) std::pair<int, float>(i, cost);
	}

	std::qsort(costs, count, sizeof(std::pair<int, float>), [](const void* a, const void* b) { return static_cast<const std::pair<int, float>*>(a)->second < static_cast<const std::pair<int, float>*>(b)->second ? 1 : -1; });

	for (int i = 0; i < count / 2; i++)
	{
		networks[costs[i].first].~Neural_Network();
		new(&networks[costs[i].first]) Neural_Network(networks[costs[i + count / 2].first]);
		networks[costs[i].first].Nudge(mutate);
	}

	best = costs[count - 1].first;
	delete[] costs;
}