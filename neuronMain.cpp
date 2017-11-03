#include <iostream>
#include "neuron.hpp"
#include <fstream>
#include "cortex.hpp"


int main()
{
	
//create the interval of simultation
	double a, b;
do
{
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
} while (b<=a or b<0 or a <0);

		
		

// the number of neurons:
		
	unsigned int ne = 10000;
	unsigned int ni= 2500;	
	unsigned int nbr = (ne+ni); 													
	
		
// create a cortex named c:
	cortex c;				
											 
// initiate the vector of pointer:
std::cout<<"initialization of neurons in the cortex..."<<std::endl;

	for (unsigned int i = 0; i < ni; i++)
	{
		c.initiateNeurons(new neuron(0.0, 1.01 , false));
	}
	for (unsigned int i = 0; i < ne; i++)
	{
		c.initiateNeurons(new neuron(0.0, 1.01 , true));
	}

	
	
	
	//initilize the random connexions between neurons;
	std::cout<<"making connections..."<<std::endl;
	c.createConnexions(ne, ni);
	//update all neurons:

	unsigned int nit = (unsigned int) ((b-a)/c.getH()); // number of iteration for the simulation
	
	c.updates(nit);
	
	// store  in a file
	c.storeInFile();

	


	
	return 0;
}
