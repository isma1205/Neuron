#ifndef NEURON_H
#define NEURON_H
#include <vector>
#include <cmath>

class neuron
{
	private: 
	//atributs:
	double mPot_; //membrane potential
	double Iext_;
	unsigned int spikesNb_;//number of spikes 
	std::vector<double> tSpike_; //
	double clock_; // neuron time
	double tRef_; //refractory time
	const double tau_ = (20.0); //20 ms
	const double c_= (1.0);
	double h_ = (0.1); // choice of the step: 1 ms
	double R_=(tau_/c_);
	double expn_=(exp(-h_/tau_));
	double cste_ =(R_*(1-expn_));
	const double treshold_ =(20.0); //initialization of the threshold
	
	int refSteps_ = (0); //number of iteration for the refractory state

	
	public:
	//constructor
	neuron(double mPot, double Iext_ = 10.0 ,unsigned int spikesNb=0, int clock =0, double tRef_ = 2.0);
	
	//methods
	double getMPot();
	double getSpikesNb();
	std::vector<double> getTSpike();
	void setMPot(double mPot);
	void setSpikesNb(unsigned int spikesNb);
	double getH () const;
	bool update(unsigned int i);
	void setTRef(double dt);
	double getTRef () const;
	
	
};


#endif
