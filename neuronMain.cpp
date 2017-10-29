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
		
// Cortex 

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
		
		// create a cortex named c:
	cortex c;				
											 
		// initiate the vector of pointer:
	for (int i = 0; i < nbr; i++)
	{
		c.initiateNeurons(new neuron(0,1.01));
	}
	//initilize the random connexions between neurons;
	c.createConnexions(nbr);
	//update all neurons:

	unsigned int nit = (unsigned int) ((b-a)/c.getH()); // number of iteration for the simulation

	
	
	
		/*std::ofstream fichier;
		fichier.open ("membrane potential.txt");*/
	
	c.updates(nit/*, fichier*/);
	
		//fichier.close();
	


	
	return 0;
}
