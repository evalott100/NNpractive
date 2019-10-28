#ifndef PERCEPT_HPP
#define PERCEPT_HPP

#include <iostream>

class ineuron
{
	protected:
		friend class oneuron;
		double weight;
		double activation;

	public:
		ineuron (){}
		ineuron (double);
		double act (double);
};

class oneuron
{
	protected:
		friend class network;
		int output;
		double activation;

	public:
		oneuron (){}
		void actvation (double[4], ineuron*);
		int outvalue (double);
};

class network
{
	public:
		ineuron nrn[4];
		oneuron onrn;
		network (double, double, double, double);
};

#endif // PERCEPT_HPP
