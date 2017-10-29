#ifndef CORTEX_H
#define CORTEX_H

#include <vector>
#include "neuron.hpp"
#include <fstream>

class cortex: public neuron
{
	private:
	
	std::vector<neuron*> neurons_;
	size_t neuronsNbr_;
	const double D_ = 0.9; // delay in ms
	const double h_= 0.1; // SEE LATER
	const int stepDelay_ = (D_/h_);
	std::vector<std::vector<bool>> connexions_; // boolean vector for connexions between neurons
	
	

	
	public:
	//constructor:
	cortex(); //initialise avec un nombre de neuron vide
	// methods
	void receiveSpike(neuron n);
	void updates(unsigned int nit/*, std::ofstream fichier*/);
	void initiateNeurons(neuron* pointer);
	double randm(double a, double b); //return a random double number beetween a & b
	void createConnexions(unsigned int nbr);

	//getters
	double getH() const;
	size_t getSize() const;
	//destructeur
	~cortex();

	
	
};





#endif


