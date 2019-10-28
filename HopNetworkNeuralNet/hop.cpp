#include "Hop.hpp"

neuron::neuron (int *j)
{
	for (int i = 0; i < 4; i++)
		weightv[i] = *(j + i);
}

int neuron::act (int m, int *x)
{
	int a = 0;
	for (int i = 0;i < 4; i++)
		a += x[i] * weightv[i];
	return a;
}

int network::threshld (int k)
{
	return (k >= 0) ? 1 : 0;
}

network::network (int a[4], int b[4], int c[4], int d[4])
{
	nrn[0] = neuron(a);
	nrn[1] = neuron(b);
	nrn[2] = neuron(c);
	nrn[3] = neuron(d);
	
}

void network::activation(int *patrn)
{
	for (int i = 0; i < 4; i++) {
		for (int f = 0; f < 4; f++)
			std::cout << "\n nrn[" << i << "].weightv[" << f << "] is " << nrn[i].weightv[f];

		nrn[i].activation = nrn[i].act(4,patrn);
		std::cout << "\nactivation is " << nrn[i].activation;
		output[i] = threshld(nrn[i].activation);
		std::cout << "\noutput is " << output[i] << "\n";
	}
}

int main()
{
	int patrn1[] = {1,0,1,0}, i;
	int wt1[] = {0,-3,3,-3};
	int wt2[] = {-3,0,-3,3};
	int wt3[] = {3,-3,0,-3};
	int wt4[] = {-3,3,-3,0};

	std::cout << "THIS PROGRAM IS FOR A HOPFIELD NETWORK WITH A\nSINGLE LAYER OF FULLY INTERCONNECTED NEURONS.\nTHE NETWORK SHOULD RECALL THE PATTERNS 1010 AND 0101 CORRECTLY.\n";
	network hl(wt1,wt2,wt3,wt4);
	hl.activation(patrn1);
	for (int i = 0; i < 4; i++) {
		if(hl.output[i] == patrn1[i])
			std::cout << "\n pattern =" << patrn1[i] << "\t output = " << hl.output[i] << "\t component matches\n";
		else
			std::cout << "\ndiscrepancy";
	}
}
