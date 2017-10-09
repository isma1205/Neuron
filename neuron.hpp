#ifndef NEURON_H
#define NEURON_H
#include <vector>


class neuron
{
	private:
	double mPot_; //membrane potential
	unsigned int spikesNb_;//numbre of spikes 
	std::vector<double> tSpike_;
	
	public:
	//constructor
	neuron(double mPot, unsigned int spikesNb=0);
	
	//methods
	double getMPot();
	double getSpikesNb();
	std::vector<double> getTSpike();
	void setMPot(double mPot);
	void setSpikesNb(unsigned int spikesNb);
	//void setTspike()
	void update(double t, double expn, double cste, double Iext);
	
	
};


#endif
