#include <iostream>
#include "cortex.hpp"



/*// constructor:
cortex::cortex(size_t neuronsNbr, double J)
: neurons_(neuronsNbr), J_(J)
{}*/

void cortex::receiveSpike(neuron n) // transmit the J to the membrane
{
	n.setBuffer(stepDelay_);
}
void cortex::updates(unsigned int nit)
{
	for (unsigned int i = 0; i < nit ; ++i)
	{
		for (unsigned int j = 1; j <= neurons_.size() ; ++j)
		{
			bool isThereSpike (neurons_[j]->update(i));
			if ((isThereSpike) and (j+1)<=neurons_.size())
			{
				receiveSpike(*neurons_[j+1]); // transmit the J to the neurone j+1 in its buffer
			}
			
		}
		
	}
	
}
