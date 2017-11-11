#include <iostream>
#include "neuron.hpp"
#include <cmath>
#include <random>


   
//constructeur
neuron::neuron(double mPot, double Iext, bool type,bool display, bool noise, double g, double mu, unsigned int spikesNb, int clock, double tRef)
: mPot_(mPot),Iext_(Iext), type_(type),displaySpikes_(display), noise_(noise), g_(g), MU_(mu), spikesNb_(spikesNb),  clock_(clock), tRef_(0.0), buffer_(16,0)
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
	std::vector<double> neuron::getTspike() const
	{
		return tSpike_;
	}
	bool neuron::getType() const
	{
		return type_;
	}

	bool neuron::getDisplay() const
	{
		return displaySpikes_;
	}
	
	double neuron::getBufferi(unsigned int i) const
	{
		return buffer_[i];
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
	void neuron::setBuffer(unsigned int i, int delayStep, double weight)
	{
		buffer_[(i+delayStep)% buffer_.size()] +=(weight); //give the weight to te buffer
	}
	void neuron::setDisplaySpikes(bool b)
	{
		displaySpikes_ = b;
	}


//update
	bool neuron::update(unsigned int i)
	{
		clock_ = i; // the neurone time is refresh and become the actual number of iteration 
		bool anySpike (false); // say if there's a spike, false initially
		
		if(mPot_ >= treshold_) // if there is a spike ->
		{
			++ spikesNb_; //increase number of spikes
			tSpike_.push_back(i*h_); //add the time of the new spike
			
			if (displaySpikes_) //if true allow to diplay spikes in terminal
			{
				std::cout<<"! Spike detected ! "<< "At time: "<< i*h_ << std:: endl;
			}
			
			refSteps_= (2/h_); // 2ms 
			mPot_= 0.0;
			anySpike = true;
		}
		if (refSteps_ <=0)  				
		{
			//backround noise
			double noiseCurrent (0.0);
			if (noise_)
			{
				static std::random_device rdm;
				static std::mt19937 gen(rdm());
				static std::poisson_distribution<> externalNoise(MU_);
				noiseCurrent= externalNoise(gen)*J_;
			}
			//read buffer
			double J = (buffer_[i%buffer_.size()]*J_); // go in the buffer to the place i%buffersize and take the value in it to add it to the membrane potential on next step if empty J=0
			if (type_== true)
			{
				mPot_ = (expn_*mPot_ + Iext_*cste_ + J + noiseCurrent); // +J if exitatory
			}
			else if (type_ == false)
			{
				mPot_ = (expn_*mPot_ + Iext_*cste_ + -J*g_ + noiseCurrent); // +J*g if inhibitory	
			}
		} 

		
		--refSteps_; // the refractory steps decrease 
		buffer_[i%buffer_.size()] = 0;
		
		return anySpike;
	}









