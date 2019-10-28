#include "Fuzzifier.hpp"

void category::setname (char *n)
{
	strcpy(name,n);
}

char* category::get_name (void)
{
	return name;
}

void category::setval (float &h, float &m, float &l)
{
	highval = h;
	midval = m;
	lowval = l;
}

// Getters
float category::get_lowval() const {return lowval;}
float category::get_midval() const {return midval;}
float category::get_highval() const {return highval;}

float category::getshare (const float &input)
{
	float output,midlow,highmid;
	
	midlow = midval - lowval;
	highmid = highval - midval;

	if ((input <= lowval) || (input >= highval))
		output = 0;
	else {
		if (input > midval)
			output = (highval - input) / highmid;
		else
			if (input == midval)
				output = 1.0;
			else
				output = (input - lowval) / midlow;
	}
	
	return output;
}

int randomnum(int maxval)
{
	srand((unsigned)time(NULL));
	return rand() % maxval;
}

int main()
{
	int i,j,numcat = 0;
	int randnum;
	float l,m,h;
	float inval = 1.0;

	char input[30] = "	";
	category *ptr[10];
	float relprob[10];
	float total,runtotal = 0;

	while (true) {
		std::cout << "\nPlease type in a catagory name, e.g Cool\n";
		std::cout << "Enter one word without spaces\n";
		std::cout << "When you are done, type 'done' :\n\n";

		ptr[i] = new category;
		std::cin >> input;

		if ((input[0] == 'd'&&
			input[1] == 'o'&&
			input[2] == 'n'&&
			input[3] == 'e'))
			break;

		ptr[i]->setname(input);	

		std::cout << "\nType in the lowval, midval, highval\n";
		std::cout << "for each catagory, seperated by spaces\n";
		std::cout << "e.g 1.0 3.0 5.0 :\n\n";

		std::cin >> l >> m >> h;
		ptr[i]->setval(h,m,l);
		i++;
	}

	numcat = i;

	std::cout << "\n\n";
	std::cout << " = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = \n";
	std::cout << " = = Fuzzifier is ready for data = = \n";
	std::cout << " = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = =  = \n";

	// Infinite loop
	while (true) {
		std::cout << "\ninput a data value, type 0 to terminate\n";
		std::cin >> inval;
		
		if (inval == 0) 
			break;

		total = 0;

		for (j = 0; j < numcat; j++) {
			relprob[j] = 100*ptr[i]->getshare(inval);
			total += relprob[j];
		}

		if (total == 0) {
			std::cout << "data out of range\n";
			exit(1);
		}

		randnum = randomnum((int)total);

		j = 0;
		runtotal = relprob[0];

		while ((runtotal < randnum) && (j++ < numcat))
			runtotal += relprob[j];
		
		std::cout << "\nOutput fuzzy category is  = = > " << ptr[j]->getname() << "< = = \n";
		
		std::cout << "catagory\t" << "membership\n";
		std::cout << "--------\n";

		for (j = 0; j<numcat; j++)
			std::cout << ptr[j]->getname() << "\t\t" << (relprob[j]/total) << "\n";

		std::cout << "\nEXITING\n";

	}
}
