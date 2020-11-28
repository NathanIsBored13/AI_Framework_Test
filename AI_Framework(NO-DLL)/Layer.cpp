#include "Neural_Network.h"

Neural_Network::Layer::Layer(int prevW, int width) : prevW(prevW), width(width), weight(new float[width * prevW]), bias(new float[width])
{
	for (int x = 0; x < width; x++)
	{
		bias[x] = RANDOM_FLOAT;
		for (int y = 0; y < prevW; y++)
			weight[x * prevW + y] = RANDOM_FLOAT;
	}
}

Neural_Network::Layer::Layer(const Layer& other) : prevW(other.prevW), width(other.width), weight(new float[width * prevW]), bias(new float[width])
{
	memcpy(weight, other.weight, sizeof(float) * width * prevW);
	memcpy(bias, other.bias, sizeof(float) * width);
}

Neural_Network::Layer::~Layer()
{
	delete[] weight;
	delete[] bias;
}

float* Neural_Network::Layer::Propigate(float* input)
{
	float* ret = new float[width];
	memcpy(ret, bias, width * sizeof(float));
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < prevW; y++)
			ret[x] += input[y] * weight[x * prevW + y];
		ret[x] = Activate(ret[x]);
	}
	delete[] input;

	return ret;
}

float Neural_Network::Layer::Activate(float in)
{
	if (in < 0)
		in = 0;
	else if (in > 1)
		in = 1;
	return in;
}

void Neural_Network::Layer::Nudge(float chance)
{
	for (int x = 0; x < width; x++)
	{
		bias[x] = RANDOM_FLOAT_ABS <= chance ? RANDOM_FLOAT : bias[x];
		for (int y = 0; y < prevW; y++)
			weight[x * prevW + y] = RANDOM_FLOAT_ABS <= chance ? RANDOM_FLOAT : weight[x * prevW + y];
	}
}