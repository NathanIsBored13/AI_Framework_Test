#include "Neural_Network.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vecA = std::vector<int>{ 2, 10, 10, 5 };
	Neural_Network* network = new Neural_Network(vecA);
	std::vector<float> vecB;
	
	vecB = std::vector<float>{ 0.5, 0.5 };
	network->Propigate(vecB);
	vecB = network->GetOutBuffer();

	std::cout << "propigate returned:" << std::endl;
	for (float f : vecB)
		std::cout << "\t" << f << std::endl;
	vecB = std::vector<float>{ 0.5, 0.5, 0.5, 0.5, 0.5 };
	std::cout << "network cost is " << network->GetCost(vecB) << std::endl;

	delete network;
}