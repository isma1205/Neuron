#ifndef	EXPERIMENT_HPP
#define EXPERIMENT_HPP
#include "cortex.hpp"
#include <iostream>

class experiment
{
	private:
	cortex c_; ///<cortex
	bool percent_ = false; ///<boolean for percent display
	
	
	public:
	
	experiment(); ///<constructor
	//destructor;
	~experiment(); ///<destructor
	//method
	/**
	 @brief : make the simulation for the plots
	 @param double g: constant for inhibitory
	 @param double mu: constant eta for poisson distribution
	 @param double time: time of the simulation 
	 @param std::ofstream& file1 : file to store spikes
	 @param  bool percent : if true, display the percent of the simulation
	 */
	void simulation(double g, double mu, double time, std::ofstream& file1, bool percent = false);
	
	/**
	 @brief : set the display 
	 @param bool percent: if true, display the percent of the simulation
	 */
	void setPercent(bool percent);
	
	
};

#endif
