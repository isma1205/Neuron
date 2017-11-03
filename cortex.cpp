#include <iostream>
#include "cortex.hpp"
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <fstream>


//constructor:
cortex::cortex()
{}

// destructor
cortex::~cortex()
{
	for (size_t i = 0; i < neurons_.size(); ++i)
	{
		delete neurons_[i];
		neurons_[i] = NULL;
	}
	
}

//getters:

double cortex::getH() const
	{
		return h_;
	}
	
size_t cortex::getSize() const
{
	return (neurons_.size());
}


neuron* cortex::getNeuronsi(int i)
{
	return neurons_[i];
}	

std::vector<std::vector<double> > cortex::getConnexions()
{
	return connexions_;
}
	
// methods
void cortex::receiveSpike(neuron n, double weight) // transmit the J to the membrane
{
	n.setBuffer(stepDelay_, weight);
}


void cortex::updates(unsigned int nit)
{
	
	for (unsigned int i = 0; i < nit ; ++i)
	{	
		for (unsigned int j = 0; j < neurons_.size() ; ++j)
		{	
			bool isThereSpike (neurons_[j]->update(i));
			if (isThereSpike)
			{	
				for (unsigned int k = 0; k < neurons_.size(); k++)
				{
					if (connexions_[j][k] != 0)
					{	
						
						receiveSpike(*neurons_[k], connexions_[j][k]); // transmit the J*weight to the neurone k in its buffer
					}
				}
			}
		}
	}
}

void cortex::initiateNeurons(neuron* pointer)
	{
		neurons_.push_back(pointer);
	}

double cortex::randm(double a, double b)
{
	srand(time(NULL)); 
	return (( rand()/(double)RAND_MAX ) * (b-a)) + a ; 
}

void cortex::createConnexions(unsigned int ne, unsigned int ni)
{
	
	connexions_.resize((ne+ni), std::vector<double> (ne+ni)); // open the correctly number of slots to prevent segmentation fault
	srand(time(NULL)); 
	int countE (0);
	int countI (0);
	for (unsigned int i = 0; i < (ne+ni) ; i++)
	{
	//connections for excitarory neurons
				// conections between neuron i and excitators
		for (unsigned int j = 0; j < ne ; j++)
		{	
			double weight (0);
			double chance = ((( rand()/(double)RAND_MAX ) * (1-0)) + 0) ; //used the same way as randm but the time as to be initze before the loops.
			if (chance > 0.9) // the neurons have 10% chance to be connected, if  neuron i and j connected their connection will have a weight between 0.1 - 5.0
			{
				weight = ((( rand()/(double)RAND_MAX ) * (5.0-0.1)) + 0);
				countE++;
			}
			connexions_[i][j]=weight;
		}
				//connections between neuron i and inhibitories
		for (unsigned int k = (ne+1); k < (ne+ni) ; k++)
		{	
			double weight (0);
			double chance = ((( rand()/(double)RAND_MAX ) * (1-0)) + 0) ;
			if (chance > 0.9) 
			{
				weight = ((( rand()/(double)RAND_MAX ) * (5.0-0.1)) + 0);
				countI ++;
			}
			connexions_[i][k]=weight;
		}
	}
	std::cout<<"#connections with excitatory neurons "<<countE<<std::endl;
		std::cout<<"#connections with inhibitory neurons "<<countI<<std::endl;
}

void cortex::storeInFile()
{
	std::ofstream file1 ("membrane potentials.csv");
	try
	{
		if (file1.fail()){throw 4;}
		else
		{
			for (size_t i = 0; i < neurons_.size() ; i++)
			{
				for (size_t j = 0; j < neurons_[i]->getTspike().size(); j++)
				{
					file1<< neurons_[i] -> getTSpike()[j] << '\t'<<i <<'\n';
				}
			}
		}
	}
	catch (int four)
	{
		std::cout<<" faile in opening file1 containing membrane potentials " <<std::endl;
	}
	file1.close();
}
