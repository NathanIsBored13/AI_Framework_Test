#include <iostream>
#include <vector>

#pragma once
	class Neural_Network
	{
	public:
		Neural_Network(std::vector<int>&);
		Neural_Network(const Neural_Network&);
		~Neural_Network();
		std::vector<float> Propigate(std::vector<float>&);
	private:
		class Layer
		{
		public:
			Layer(int, int);
			Layer(const Layer&);
			~Layer();
			float* Propigate(float*);
		private:
			float Activate(float);
			int prevW, width;
			float* weight;
			float* bias;
		};
		std::vector<int> structure;
		Layer* layers;
	};