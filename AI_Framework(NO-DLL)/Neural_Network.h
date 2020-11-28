#include <iostream>
#include <vector>

#define RANDOM_FLOAT_ABS (static_cast <float> (rand()) / static_cast <float> (RAND_MAX))
#define RANDOM_FLOAT (static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 2)) - 1.0f)

#pragma once
class Neural_Network
{
public:
	Neural_Network(std::vector<int>&);
	Neural_Network(const Neural_Network&);
	~Neural_Network();
	std::vector<float> Propigate(std::vector<float>&);
	void Nudge(float);
private:
	class Layer
	{
	public:
		Layer(int, int);
		Layer(const Layer&);
		~Layer();
		float* Propigate(float*);
		void Nudge(float);
	private:
		float Activate(float);
		int prevW, width;
		float* weight;
		float* bias;
	};
	std::vector<int> structure;
	Layer* layers;
};