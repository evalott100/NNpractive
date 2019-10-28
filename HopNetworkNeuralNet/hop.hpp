#ifndef HOP_HPP
#define HOP_HPP

//Example Neural Network
#include <iostream>

class neuron {
protected:
	friend class network;
	int activation;
public:
	int weightv[4];
	neuron (){};
	neuron (int*);
	int act (int,int*);
};

class network {
public:
	neuron nrn[4];
	int output[4];
	int threshld (int);
	void activation (int[4]);
	network (int*,int*,int*,int*);
};

#endif // HOP_HPP
