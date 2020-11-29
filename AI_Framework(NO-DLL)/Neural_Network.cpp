#include "Neural_Network.h"

Neural_Network::Neural_Network(std::vector<int>& structure) : structure(structure), layers((Layer*)malloc(sizeof(Layer) * (structure.size() - 1)))
{
	for (size_t i = 0; i < structure.size() - 1; i++)
		new(&layers[i]) Layer(structure[i], structure[i + 1]);
};

Neural_Network::Neural_Network(const Neural_Network& other) : structure(other.structure), layers((Layer*)malloc(sizeof(Layer)* (structure.size() - 1)))
{
	for (size_t i = 0; i < structure.size() - 1; i++)
		new(&layers[i]) Layer(other.layers[i]);
}

Neural_Network::~Neural_Network()
{
	for (size_t i = 0; i < structure.size() - 1; i++)
		layers[i].~Layer();
	free(layers);
}

void Neural_Network::Propigate(std::vector<float>& input)
{
	float* buffer = new float[input.size()];
	memcpy(buffer, &input[0], structure[0] * sizeof(float));

	for (size_t i = 0; i < structure.size() - 1; i++)
		buffer = layers[i].Propigate(buffer);

	outBuffer = std::vector<float>(buffer, buffer + structure[structure.size() - 1]);
	delete[] buffer;
}

std::vector<float>& Neural_Network::GetOutBuffer()
{
	return outBuffer;
}

float Neural_Network::GetCost(std::vector<float>& expected)
{
	float ret = 0;
	for (int i = 0; i < expected.size(); i++)
		ret += pow(outBuffer[i] - expected[i], 2);
	return ret;
}

void Neural_Network::Nudge(float chance)
{
	for (size_t i = 0; i < structure.size() - 1; i++)
		layers[i].Nudge(chance);
}