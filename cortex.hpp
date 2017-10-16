#ifndef CORTEX_H
#define CORTEX_H

#include <vector>
#include "neuron.hpp"

class cortex: public neuron
{
	private:
	
	std::vector<neuron*> neurons_;
	size_t neuronsNbr_;
	const double D_ = 0.9; // delay in ms
	const double h_= 0.1; // SEE LATER
	const int stepDelay_ = (D_/h_);
	
	

	
	public:
	//constructor:
	cortex(size_t neuronsNbr, double J);
	// methods
	void receiveSpike(neuron n);
	void updates(unsigned int nit);

	
	
};





#endif


