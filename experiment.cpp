#include "experiment.hpp"
#include <iostream>


experiment::experiment()
{
	char per ('z');
	do
	{
		try
		{
			std::cout<<"do you want to display the percent of simulation: y = yes n= no"<<std::endl;
			std::cin>>per;
			if((per!='y') and (per!='n')) {throw('j');}
		}
		catch (char j)
		{
			std::cout<<"please enter p to display plots or s for you own simulation"<<std::endl;
		}
	} while ((per!='y') and (per!='n'));
	if(per == 'y'){setPercent(true);}
	if(per == 'n'){setPercent(false);}
		
}

experiment::~experiment()
{}

void experiment::simulation(double g, double mu, double time, std::ofstream& file1, bool percent)
{

// the number of neurons:	
	unsigned int ne = 10000; //excitatoryamke
	unsigned int ni= 2500;	 //inhibitory	
	
	// initiate the vector of pointer:
	std::cout<<"initialization of neurons in the cortex..."<<std::endl;
	
	for (unsigned int i = 0; i < ne; i++)
	{
		c_.initiateNeurons(new neuron(0.0, 1.01 , true, false,true,g,mu));
	}
	for (unsigned int i = 0; i < ni; i++)
	{
		c_.initiateNeurons(new neuron(0.0, 1.01, false, false,true,g,mu));
	}
// making connections:
std::cout<< "making connections..." << std::endl;
	c_.createCountConnexions(ne, ni);
	
//update all neurons:
	unsigned int nit = time/c_.getH(); // number of iteration for the simulation
	std::cout<< "simulation for "<< ne << " excitatory neurons and "<< ni << " inhibitory neurons starts" << std::endl;
	c_.updates(nit, percent_);

//storing in a file
	std::cout<< " -> storing in file the membrane potentials..."<< std::endl;
	c_.storeInFile(file1);
	std::cout<< "end of the simulation..." << std::endl;
	
	c_.getNeurons().clear();
	c_.getConnexions().clear();
}

//setter
void experiment::setPercent(bool percent)
{
	percent_=percent;
}
