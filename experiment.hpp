#ifndef	EXPERIMENT_HPP
#define EXPERIMENT_HPP
#include "cortex.hpp"
#include <iostream>

class experiment
{
	private:
	cortex c_;
	bool percent_ = false;
	
	
	public:
	//constructor
	experiment();
	//destructor;
	~experiment();
	//method
	void simulation(double g, double mu, double time, std::ofstream& file1, bool percent = false);
	void setPercent(bool percent);
	
	
};

#endif
