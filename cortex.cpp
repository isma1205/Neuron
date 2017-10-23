
#include <iostream>
#include "cortex.hpp"
#include <vector>


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
	
	
// methods
void cortex::receiveSpike(neuron n) // transmit the J to the membrane
{
	n.setBuffer(stepDelay_);
}


void cortex::updates(unsigned int nit)
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
		}
	}
}

	void cortex::initiateNeurons(neuron* pointer)
	{
		neurons_.push_back(pointer);
		//debugg
		std::cout<< "correctement push"<<std::endl;
	}

