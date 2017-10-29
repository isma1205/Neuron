#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <cmath>
#include <iostream>

class neuron
{
	private: 
	//atributs:
	double mPot_;							//membrane potential
	double Iext_;
	bool type_;								//true if excitatory, false if inhibitory
	unsigned int spikesNb_;					//number of spikes 
	std::vector<double> tSpike_; 			// vector that keep in memory when spikes occure
	int clock_; 							// neuron time in step
	double tRef_;							//refractory time
	const double tau_ = (20.0); 			//20 ms
	const double c_= (1.0);
	double h_ = (0.1); 						// choice of the step: 1 ms
	double R_=(tau_/c_);
	double expn_=(exp(-h_/tau_));
	double cste_ =(R_*(1-expn_));
	const double treshold_ =(20.0); 		//initialization of the threshold
	int refSteps_ = (0);					//number of iteration for the refractory state
	std::vector<int> buffer_ ; 				//ring buffer that allows 10 slots of memory for spikes with delay
	const double J_ = 0.1; 					// potential transmitted [mv]
	bool displaySpikes_ = true; // if true allow spikes time to appear in the terminal

	
	public:
	//constructor
	neuron(double mPot=0.0, double Iext = 1.01, bool type = true,unsigned int spikesNb=0, int clock =0, double tRef_ = 2.0);
	
	//methods
	double getMPot();
	double getSpikesNb();
	std::vector<double> getTSpike();
	void setMPot(double mPot);
	void setSpikesNb(unsigned int spikesNb);
	double getH() const;
	bool update(unsigned int i);
	void setTRef(double dt);
	double getTRef () const;
	void setBuffer(int D);
	std::vector<double> getTspike() const;
	void setDisplaySpikes(bool b);

	
};


#endif
