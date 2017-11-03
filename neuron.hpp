#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <cmath>
#include <iostream>

class neuron
{
	private: 
	//atributs:
	double mPot_;							///membrane potential
	double Iext_;							///external current
	bool type_ = true;						///type of the neuron: true if excitatory, false if inhibitory
	unsigned int spikesNb_;					///number of spikes 
	std::vector<double> tSpike_; 			///vector that keep in memory when spikes occur
	int clock_; 							///neuron time in step
	double tRef_;							///refractory time of the neuron
	const double tau_ = (20.0); 			///constant
	const double c_= (1.0);					///constant
	double h_ = (0.1); 						///step of the simulation: usually 1 ms
	double R_=(tau_/c_);					///constant
	double expn_=(exp(-h_/tau_));			///constant
	double cste_ =(R_*(1-expn_));			///constant
	const double treshold_ =(20.0); 		///level of the treshold
	int refSteps_ = (0);					///number of iteration for the refractory state
	std::vector<double> buffer_ ; 			///ring buffer that allows 10 slots of memory for spikes with delay
	const double J_ = 0.1; 					///potential transmitted to other neurons [mv] when spike occurs
	bool displaySpikes_ = true; 			///if true, allows spikes time to appear in the terminal
	int g_ = 5;								///constant

	
	public:
	//constructor:						
	neuron(double mPot=0.0, double Iext = 1.01, bool type = true, unsigned int spikesNb=0, int clock =0, double tRef_ = 2.0); ///constructor of neuron
	

	//getters:
	/**
	 @brief : getter for the membrane potential
	 @return : mPot_
	 */ 
	double getMPot();
	
	/**
	 @brief : getter for  the number of spikes
	 @return : spikesNb_
	 */ 
	double getSpikesNb();
	
	/**
	 @brief :getter for the vector that keep in memory when the spikes occur
	 @return : tSpike_
	 */ 
	std::vector<double> getTSpike();
	
		/**
	 @brief : getter for the step of the simulation h_
	 @return : h_
	 */ 
	double getH() const;
	
		/**
	 @brief : getter for the refractory time
	 @return : tRef_
	 */ 
	double getTRef () const;
	
		/**
	 @brief : getter for the type of neuron: true if excitatory, false if inhibitory
	 @return : type_
	 */ 
	bool getType();
	
	
	std::vector<double> getTspike() const;
	
	//setters
	
	/**
	 @brief : setter for the membrane potential: mPot_
	 @param : membrane potential
	 */ 
	void setMPot(double mPot);
	
	/**
	 @brief : setter for the the number of spikes
	 @param : the number of spikes
	 */ 
	void setSpikesNb(unsigned int spikesNb);
	
		/**
	 @brief : setter for the refractory time
	 @param : the refractory time you chose
	 */ 
	void setTRef(double dt);
	
	/**
	 @brief : setter for the buffer in delay:D & insert the strength of the connection:weight
	 @param int D: delay
	 @param double weight: weight of the connection
	 */ 
	void setBuffer(int D, double weight);
	
	/**
	 @brief : setter for the diplay option, set true if you want to diplay the spikes, set false if you don't.
	 @param bool b: boolean value
	 */ 
	void setDisplaySpikes(bool b);
	
	//update
	
	/**
	 @brief : update the values of the neuron for each step
	 @param unsigned int i: number of the iteration, used to store the time when a spike occur
	 @return : boolean value: true if a spike occur, false if not
	 */ 
	bool update(unsigned int i);
	
	
	


	
};


#endif
