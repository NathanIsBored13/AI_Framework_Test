#include "Neural_Network.h"

Neural_Network::Neural_Network(std::vector<int>& structure) : structure(structure), layers((Layer*)malloc(sizeof(Layer) * (structure.size() - 1)))
{
	for (size_t i = 0; i < structure.size() - 1; i++)
	{
		std::cout << "layer " << i << " created\n";
		new(&layers[i]) Layer(structure[i], structure[i + 1]);
	}
};

Neural_Network::~Neural_Network()
{

	for (size_t i = 0; i < structure.size() - 1; i++)
		layers[i].~Layer();
	free(layers);
	std::cout << "Network Deleted" << std::endl;
}

std::vector<float> Neural_Network::Propigate(std::vector<float>& input)
{

	float* buffer = new float[input.size()];
	std::copy(input.begin(), input.end(), buffer);

	std::cout << "network input:" << std::endl;
	for (int i = 0; i < structure[0]; i++)
		std::cout << "\t" << buffer[i] << std::endl;

	for (size_t i = 0; i < structure.size() - 1; i++)
		buffer = layers[i].Propigate(buffer);

	std::vector<float> ret(buffer, buffer + structure[structure.size() - 1]);
	delete[] buffer;
	return ret;
}