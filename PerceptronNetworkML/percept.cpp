#include "percept.hpp"

ineuron::ineuron (double j)
{
	weight = j;
}

double ineuron::act (double x)
{
	return (x * weight);
}

void oneuron::actvation (double *inputv, ineuron *nrn)
{
	activation = 0;
	for (int i = 0; i < 4; i++) {
		std::cout << "\nweight for neuron " << i + 1 << " is " << nrn[i].weight;
		nrn[i].activation = nrn[i].act(inputv[i]);
		std::cout << "		activation is " << nrn[i].activation;
		activation += nrn[i].activation;
	}
	
	std::cout << "\n\nactivation is " << activation << "\n";
}

int oneuron::outvalue (double j)
{
	if (activation >= j) {
		std::cout << "\nthe output neuron activation exceeds the threshold value of " << j << "\n";
		return 1;
	}
	else {
		std::cout << "\nthe output neuron activation is less than the threshold value of " << j << "\n";
		return 0;
	}

	std::cout << "\noutput value is " << output;
	return output;
}

network::network (double a, double b, double c, double d)
{
	nrn[0] = ineuron(a);
	nrn[1] = ineuron(b);
	nrn[2] = ineuron(c);
	nrn[3] = ineuron(d);
	onrn = oneuron();
	onrn.activation = 0;
	onrn.output = 0;
}

int main (int argc, char** argv)
{
	double inputv1[] = {1.95, 0.27, 0.69, 1.25};
	double wtv1[] = {2, 3, 3, 2}, wtv2[] = {3, 0, 6, 2};
	FILE *wfile, *infile;
	int num = 0, vecnum = 0, i;
	double threshold = 7.0;

	if (argc < 2) {
		std::cerr << "Usage: percept weightfile inputfile";
		exit(1);
	}

	// Openfiles
	wfile = fopen(argv[1], "r");
	infile = fopen(argv[2], "r");

	if ((wfile==NULL) || (infile==NULL)) {
		std::cout << "cannot open a file\n";
		exit(1);
	}

	std::cout << "\nThis program is for a perceptron network with an input layer of";
	std::cout << "\n4 neurons, each connected to the output neuron";
	std::cout << "\nThis example takes real numbers as input signals\n";

	// Create the network by calling the constructor 
	// The constructor calls neuron constructor as many times as the number of 
	// neurons in input layer of the network
	
	std::cout << "please enter the number of weights/vectors ::" << std::flush;
	std::cin >> vecnum;
	std::cout << '\n';

	for (i = 1; i <= vecnum; i++) {
		fscanf(wfile, "%f %f %f %f\n", &wtv1[0], &wtv1[1], &wtv1[2], &wtv1[3]);
		network h1(wtv1[0], wtv1[1], wtv1[2], wtv1[3]);
		fscanf(infile, "%f %f %f %f\n", &inputv1[0], &inputv1[1], &inputv1[2], &inputv1[3]);
		std::cout << "this is vector =/= " << i << '\n';
		std::cout << "please enter a threshold value, e.g 7.0 ::" << std::flush;
		std::cin >> threshold;
		std::cout << "\n";

		h1.onrn.actvation(inputv1, h1.nrn);
		h1.onrn.outvalue(threshold);
		std::cout << "\n\n";
	}

	fclose(wfile);
	fclose(infile);
}
