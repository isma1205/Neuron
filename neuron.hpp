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
	const double tau_ = (20.0); 			///constant for membtrane potential
	const double c_= (1.0);					///constant for membtrane potential
	double h_ = (0.1); 						///step of the simulation: usually 1 ms
	double R_=(tau_/c_);					///constant for membrane potential
	double expn_=(exp(-h_/tau_));			///constant for membtrane potential
	double cste_ =(R_*(1-expn_));			///constant for membtrane potential
	const double treshold_ =(20.0); 		///level of the treshold
	int refSteps_ = (0);					///number of iteration for the refractory state
	std::vector<double> buffer_ ; 			///ring buffer that allows 16 slots of memory for spikes with delay
	const double J_ = 0.1; 					///potential transmitted to other neurons [mv] when spike occurs
	bool displaySpikes_ = false; 			///if true, allows spikes time to appear in the terminal
	int g_ = 5;								///constant for random backround noise
	bool noise_ = true;						///if true the poisson distribution for backround noise is available
	double MU_ = 2;
	
	public:
	//constructor:		
	/**
	 @brief : constructor of neuron
	 @param double mPot: membrane potential
	 @param double Iext: external current
	 @param bool type: true if excitatory, false if inhibitory
	 @param bool display: display spikes time and number of connections in terminal if true
	 @param bool noise: if true activate the background noise
	 @param unsigned int spikes Nb: the number of spikes that occured
	 @param int clock: neuron time in step
	 @param double tRef: refcractory time
	*/				
	neuron(double mPot=0.0, double Iext = 1.01, bool type = true, bool display = false, bool noise =true, double g =5, double mu =2, unsigned int spikesNb=0, int clock =0, double tRef_ = 2.0); 
	

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
	bool getType() const;
	
	
	std::vector<double> getTspike() const;
	
	bool getDisplay() const;
	
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
	void setBuffer(unsigned int i, int D, double weight);
	
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
	
	/**
	@brief : will return the containt of the ine the space i of the buffer_
	@param unsigned int i: the number of the space we are interested in
	@return : the value of the  membrane potential the neuron will read
	*/
	double getBufferi(unsigned int i) const;
	
	
};


#endif
