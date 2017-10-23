#include <iostream>
#include "neuron.hpp"
#include "cortex.hpp"
#include <cmath>
#include "gtest/gtest.h"


TEST(neuronAlone, noSpike ) // sur un intervalle de 0 à 1000ms le neurone ne doit pas avoir de spike si le courant est inferieur ou égale à 1.00
{
	neuron n(10,1.00);
	unsigned int nit = 1000/n.getH(); //#interation
	n.update(nit);
	EXPECT_EQ(0, n.getSpikesNb());
}

TEST(neuronAlone, mpottwenty ) // sur un intervalle de 0 à 1000ms le neurone devrait atteindre a la fin de la simulation un potentiel 20mv si le courant est égale à 1.00
{
	neuron n(0,1.00);
	unsigned int nit = (1000/n.getH()); //#interation
	for (int i = 0; i < nit; i++)
	{
		n.update(i);
	}
	
	//std::cout<<n.getMPot()<<std::endl;
	ASSERT_DOUBLE_EQ(20, n.getMPot());
}
