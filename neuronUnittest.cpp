#include <iostream>
#include "neuron.hpp"
#include "cortex.hpp"
#include <cmath>
#include "gtest/gtest.h"


// tests on one neuron:
	//verification: no spike if I<=1.00
	TEST(neuronAlone, noSpike ) // sur un intervalle de 0 à 1000ms le neurone ne doit pas avoir de spike si le courant est inferieur ou égale à 1.00
	{
		neuron n(10,1.00);
		unsigned int nit = 1000/n.getH(); //#interation
		n.update(nit);
		EXPECT_EQ(0, n.getSpikesNb());
	}
	
	//verify that the mPot isn't bigger than 20 if I<=1.00
	TEST(neuronAlone, mpottwenty ) // sur un intervalle de 0 à 1000ms le neurone devrait atteindre a la fin de la simulation un potentiel 20mv si le courant est égale à 1.00
	{
		neuron n(0,1.00);
		unsigned int nit = (1000/n.getH()); //#interation
		for (unsigned int i = 0; i < nit; i++)
		{
			n.update(i);
		}
		
		//std::cout<<n.getMPot()<<std::endl;
		ASSERT_FLOAT_EQ(20, n.getMPot());
	}

	// test of the spikes times if I = 1.01
	TEST(neuronAlone, spikesTime ) // sur un intervalle de 0 à 400ms le neurone devrait avoir des pics à 92.4, 186.6, 281.2, 375.6 ms
	{
		neuron n(0,1.01);
		n.setDisplaySpikes(false); // arrête l'affiche des pics du neurone
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
