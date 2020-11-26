#include "Neural_Network.h"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "running\n";
	std::vector<int> vecA = std::vector<int>{ 2, 10, 10, 10 };
	Neural_Network* network = new Neural_Network(vecA);
	std::cout << "created\n";

	delete network;
}