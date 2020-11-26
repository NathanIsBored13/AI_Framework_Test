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
	float* ret = &input[0];
	for (rsize_t i = 0; i < structure.size() - 1; i++)
	{
		ret = layers[i].Propigate(ret);
	}
	std::vector<float> a = std::vector<float>();
	return input;
}