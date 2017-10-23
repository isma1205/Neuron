#include <iostream>
#include "neuron.hpp"
#include <fstream>
#include "cortex.hpp"


int main()
{

//create the interval of simultation
	double a, b;

	
		try
		{
			std::cout<<"entrez un intervalle [ms]"<<std::endl;
			std::cin>>a>>b;
			
			if (b<=a or b<0 or a <0)
			{
				throw 1;
			}
		
		}
		catch(int x)
		{
			std::cout<<"ERROR interval not correct"<< std::endl;
		}
// create the cortex
	int nbr; 															// the number of neurons
	
		try
		{
			std::cout<< "how many neurons your cortex has"<<std::endl;
			std::cin>>nbr;
			std::cout<<"Start simulation for " << nbr << " neurons"<< std::endl;
				if (nbr<1) {throw 2;}
		}
		catch (int y)
		{
			std::cout<<"ERROR there isn't enough neurons"<< std::endl;
		}
	
	cortex c;				
												// create a cortex named c

																		// initiate the vector of pointer
	for (int i = 0; i < nbr; i++)
	{
		c.initiateNeurons(new neuron(0,1.00));
		//debugg
		std::cout<<"taille du vector: " << c.getSize()<<std::endl;
	
	}
	//update all neurons:

	unsigned int nit = (unsigned int) ((b-a)/c.getH()); // number of iteration for the simulation
	//std::cout<<"N1 MPOT !!!! " << n1.getMPot() << std::endl;
	
	c.updates(nit);

	/*std::cout<<"enter your input current "<<std::endl;
	std::cin>>Iext;;*/
	
	

	
//	std::ofstream file1("membrane potential.txt");

/*
	for (unsigned int i = 0; i < nit; ++i)
	{
		n1.update(i);
		file1 << n1.getMPot()<<"\n"; // store the membrane potential in a file
	
		
		//std::cout<<"time[s]: "<< a <<std::endl;
		std::cout<<"membrane potential[mv] "<<n1.getMPot()<<std::endl;
		
		
	}

	file1.close();*/
	
	
	return 0;
}
