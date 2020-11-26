#include "Neural_Network.h"

	Neural_Network::Layer::Layer(int prevW, int width) : prevW(prevW), width(width), weight(new float[width * prevW]), bias(new float[width])
	{
		std::cout << static_cast <float> (rand()) / static_cast <float> (RAND_MAX) << std::endl;
		for (int x = 0; x < width; x++)
		{
			bias[x] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			for (int y = 0; y < prevW; y++)
			{
				weight[x * prevW + y] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			}
		}
	}

	Neural_Network::Layer::~Layer()
	{
		delete[] weight;
		delete[] bias;
		std::cout << "Layer Deleted" << std::endl;
	}

	float* Neural_Network::Layer::Propigate(float* input)
	{
		float* ret = new float[width];
		memcpy(ret, bias, width);

		std::cout << "Layer input:" << std::endl;
		for (int i = 0; i < prevW; i++)
			std::cout << "\t" << input[i] << std::endl;

		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < prevW; y++)
			{
				ret[x] += input[y] * weight[x * prevW + y];
			}
			ret[x] = Activate(ret[x]);
		}
		delete[] input;

		std::cout << "Layer outputs:" << std::endl;
		for (int i = 0; i < width; i++)
			std::cout << "\t" << ret[i] << std::endl;

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