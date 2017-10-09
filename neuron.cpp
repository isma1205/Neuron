#include <iostream>
#include "neuron.hpp"
#include <cmath>


//constructeur
neuron::neuron(double mPot, unsigned int spikesNb)
: mPot_(mPot), spikesNb_(spikesNb)
{}

const double treshold(20.0); //initialization of the threshold

// getters
	double neuron::getMPot()
	{
		return mPot_;
	}
	
	double neuron::getSpikesNb()
	{
		return spikesNb_;
	}
	
	std::vector<double> neuron::getTSpike()
	{
		return tSpike_;
	}

// setters
	void neuron::setMPot(double mPot)
	{
		mPot_=mPot;
	}
	void neuron::setSpikesNb(unsigned int spikesNb)
	{
		spikesNb_= spikesNb;
	}
	/*void setTspike()
	 {
		
	 }
	 */

//update
void neuron::update(double t, double expn, double cste, double Iext)
{
	if(mPot_ >= treshold) // if there is a spike ->
	{
		++ spikesNb_; //increase number of spikes
		tSpike_.push_back(t); //add the time of the new spike
		mPot_= 0.0;
		std::cout<<"! Spike detected ! "<<std::endl;
	}
	else   					// this allow me to don't care about the refractory time, because the step is 2ms = refractory time, so the ref.time is always respected. I will increment 
	{
		mPot_= (expn*mPot_ + Iext*cste);
		std::cout<<"no spike"<<std::endl;
	}
	
}
















