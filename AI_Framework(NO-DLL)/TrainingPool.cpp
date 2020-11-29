#include "TrainingPool.h"

TrainingPool::TrainingPool(int count, std::vector<int>& structure) : count(count * 2), networks((Neural_Network*)malloc(sizeof(Neural_Network)* (count * 2)))
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

void TrainingPool::Propigate(std::vector<float>& input)
{
	std::vector<float> exp = std::vector<float>{ 0.5, 0.5, 0.5, 0.5, 0.5 };
	std::vector<float> out;
	for (int i = 0; i < count; i++)
	{
		networks[i].Propigate(input);
		out = networks[i].GetOutBuffer();

		std::cout << "\nnetwork " << i << " returned:" << std::endl;
		for (float f : out)
			std::cout << "\t" << f << std::endl;
		std::cout << "network cost is " << networks[i].GetCost(exp) << std::endl;
	}
}