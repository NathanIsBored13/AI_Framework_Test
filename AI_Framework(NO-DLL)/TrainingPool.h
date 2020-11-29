#include "Neural_Network.h"

#include <vector>

#pragma once
class TrainingPool
{
public:
	TrainingPool(int, std::vector<int>&);
	TrainingPool(const TrainingPool&) = delete;
	~TrainingPool();
	void Propigate(std::vector<float>&);
private:
	int count;
	Neural_Network* networks;
};