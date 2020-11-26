#include "Neural_Network.h"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "running\n";
	std::vector<int> vecA = std::vector<int>{ 2, 10, 10, 5 };
	Neural_Network* network = new Neural_Network(vecA);
	std::cout << "created\n";
	std::vector<float> vecB = std::vector<float>{ 0.5, 0.5 };
	vecB = network->Propigate(vecB);
	std::cout << "propigate returned:" << std::endl;
	for (float f : vecB)
		std::cout << "\t" << f << std::endl;

	delete network;
}