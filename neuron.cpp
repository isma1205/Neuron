#include <iostream>
#include "neuron.hpp"
#include <cmath>


//constructeur
neuron::neuron(double mPot, double Iext, unsigned int spikesNb, int clock, double tRef)
: mPot_(mPot),Iext_(Iext), spikesNb_(spikesNb),  clock_(clock), tRef_(0.0), buffer_(10,0)
{}



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
	double neuron::getTRef() const
	{
		return tRef_;
	}
	double neuron::getH() const
	{
		return h_;
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
	void neuron::setTRef( double dt)
	{
		tRef_= dt;
	}
	void neuron::setBuffer(int delayStep)
	{
		buffer_[(clock_+delayStep)% buffer_.size()] +=1;
	}
	
	/*void setTspike()
	 {
		
	 }
	 */


//update
bool neuron::update(unsigned int i)
{
	bool anySpike (false); // return if there's a spike, false initially
	
	if(mPot_ >= treshold_) // if there is a spike ->
	{
		++ spikesNb_; //increase number of spikes
		tSpike_.push_back(i*h_); //add the time of the new spike
		
		std::cout<<"! Spike detected ! "<<std::endl;
		std:: cout << i*h_ << std:: endl;
		refSteps_= (2/h_); // 2ms 
		mPot_= 0.0;
		anySpike = true;
	}
	
	if (refSteps_ <=0)  				
	{
		double J = (buffer_[i%buffer_.size()]*J_); // go in the buffer to the place i%buffersize and take the value in it to add it to the membrane potential on next step
		mPot_ = (expn_*mPot_ + Iext_*cste_ + J);
		
		//std::cout<<"no spike"<<std::endl;
	}

	clock_ = i; // the neurone time is refresh and become the actual number of restant iteration 
	--refSteps_; // the refractory steps decrease 
	buffer_[i%buffer_.size()] = 0;
	return anySpike;

}

/*
 * new constants c1 &c2:
 recompute exp*V 
 recompute IextR(1-exp)
*/







