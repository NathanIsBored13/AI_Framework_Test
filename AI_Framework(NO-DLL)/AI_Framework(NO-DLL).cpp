#include "TrainingPool.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vecA = std::vector<int>{ 2, 10, 10, 5 };
	TrainingPool p(2, vecA);
	std::vector<float> vecB = std::vector<float>{ 0.5, 0.5 };
	p.Propigate(vecB);
}