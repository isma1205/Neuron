
#include <iostream>
#include "cortex.hpp"
#include <vector>
#include <cstdlib> 
#include <ctime> 


//constructor:
cortex::cortex()
{
	
}

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
	
	
// methods
void cortex::receiveSpike(neuron n) // transmit the J to the membrane
{
	n.setBuffer(stepDelay_);
}


void cortex::updates(unsigned int nit /*, std::ofstream fichier*/)
{
	for (unsigned int i = 0; i < nit ; ++i)
	{
		for (unsigned int j = 0; j < neurons_.size() ; ++j)
		{	
			
			bool isThereSpike (neurons_[j]->update(i));
			if ((isThereSpike) and (j+1)< neurons_.size())
			{
				receiveSpike(*neurons_[j+1]); // transmit the J to the neurone j+1 in its buffer
			}
			//fichier << neurons_[j]->getMPot()<<"\n"; // store the membrane potential in a file
		}
	}
}

void cortex::initiateNeurons(neuron* pointer)
	{
		neurons_.push_back(pointer);
		//debugg
		std::cout<< "correctement push"<<std::endl;
	}

double cortex::randm(double a, double b)
{
	srand(time(NULL)); 
	return (( rand()/(double)RAND_MAX ) * (b-a)) + a ; 
}
void cortex::createConnexions(unsigned int nbr)
{
	
	connexions_.resize(nbr, std::vector<bool> (nbr)); // open the correctly number of slots to prevent segmentation fault
	srand(time(NULL)); 
	for (unsigned int i = 0; i < neurons_.size() ; i++)
	{
		for (unsigned int j = 0; j < neurons_.size() ; j++)
		{	
			bool b(false);
			double c ((( rand()/(double)RAND_MAX ) * (1-0)) + 0) ; //used the same way as randm but the time as to be initze before the loops.
			if (c > 0.5){b=true;} // if the number is >0.5 then the connextion between neuron i and j will be created. 
			connexions_[i][j]=b;
			//debugg
			std::cout<<"connexion between neuron " <<i<<" and "<<j<< " is " <<b<<std::endl;
		}
	}
	
}
