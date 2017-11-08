#include <iostream>
#include "neuron.hpp"
#include "cortex.hpp"
#include <cmath>
#include "gtest/gtest.h"


// tests on one neuron:
	//verification: no spike if I<=1.00
	TEST(neuronAlone, noSpike ) // sur un intervalle de 0 à 1000ms le neurone ne doit pas avoir de spike si le courant est inferieur ou égale à 1.00
	{
		neuron n(10,1.00, true, false, false);
		unsigned int nit = 1000/n.getH(); //#interation
		n.update(nit);
		EXPECT_EQ(0, n.getSpikesNb());
	}
	
	//verify that the mPot isn't bigger than 20 if I<=1.00
	TEST(neuronAlone, mpottwenty ) // sur un intervalle de 0 à 1000ms le neurone devrait atteindre a la fin de la simulation un potentiel 20mv si le courant est égale à 1.00
	{
		neuron n(0,1.00, true, false, false);
		unsigned int nit = (1000/n.getH()); //#interation
		for (unsigned int i = 0; i < nit; i++)
		{
			n.update(i);
		}
		
		//std::cout<<n.getMPot()<<std::endl;
		ASSERT_FLOAT_EQ(20, n.getMPot());
	}

	// test of the spikes times if I = 1.01
	TEST(neuron_Alone, spikesTime ) // sur un intervalle de 0 à 400ms le neurone devrait avoir des pics à 92.4, 186.6, 281.2, 375.6 ms
	{
		neuron n(0,1.01, true, false, false);
	
		unsigned int nit = (400/n.getH()); //#interation
		for (unsigned int i = 0; i < nit; i++)
		{
			n.update(i);
		}
		std::vector<double> spikesTime = (n.getTSpike()); // je copie le tableau de temps des spike pour l'utiliser plus facilement.
		std::vector<double> expectedTime; // creation d'un vecteur de temps attendu
			expectedTime.push_back(92.4);
			expectedTime.push_back(186.8);
			expectedTime.push_back(281.2);
			expectedTime.push_back(375.6);
			
		for (unsigned int i = 0; i < spikesTime.size(); i++) // verify that the expected time are the same than the test's ones
		{
			ASSERT_FLOAT_EQ(expectedTime[i], spikesTime[i]); 
		}
		EXPECT_EQ(4, n.getSpikesNb()); // verify that there are only 4 spikes, verify if the spikes are correctly counted
	}

		
	//test of the connections between neurons
	TEST(connections, connexions_Not_Empty )
	{
		cortex c;
		
		EXPECT_EQ(0,c.getConnexions().size()); // we expect the vector of connections to be empty.
		
		c.createConnexions(10000,2500);// create random connexions between 10000 excitatory and 2500 inhibitory
		int hasToStayOne = 1;
		if (c.getConnexions().size() == 0){hasToStayOne = 0;} // if there's no connections the become 0
		
		EXPECT_EQ(1,hasToStayOne); // verify that connections a correctly made
	}
	
	TEST(connections, number_of_connections)
	{
		cortex c;
	
	for (unsigned int i = 0; i < 10000; i++)
	{
		c.initiateNeurons(new neuron(0.0, 1.01 , true, false, false));
	}
	for (unsigned int i = 0; i < 25000; i++)
	{
		c.initiateNeurons(new neuron(0.0, 1.01 , false, false, false));
	}
		// create random connexions between 10000 excitatory and 2500 inhibitory
		int hasToStayOne = 1;
		std::vector<int> counts = c.createCountConnexions(10000,2500);
		
		if ( ((counts[0]+counts[1]) < 11718750) or ((counts[0]+counts[1]) > 19531250) ){hasToStayOne = 0;} 
		/*We expect the number of connections to be approximatively 10%
		so it should be, with that number of neurons, (12500*12500)*10% and let say +/- 2.5% */
		
		EXPECT_EQ(1,hasToStayOne);
		
	}

	/*TEST(connections, received_a_spike_in_the_buffer)
{
	cortex c;
	c.initiateNeurons(new neuron(0.0, 1.01 , true, false, false));
	//will spike at 92.4ms so the 924th iteration (cause h_=0.1), -> take place in ((924+15)%16)=11th place in the buffer.
	c.initiateNeurons(new neuron(0.0, 0.0 , true, false, false));
	int nit (924);
	c.updates(nit);
	if()
	
	//setOneConnexions2neurons(0,1, 1); //the connection between neuron 0 and neuron 1 will be 1
	

}*/




