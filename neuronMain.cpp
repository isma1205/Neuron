#include <iostream>
#include <ctime>
#include "neuron.hpp"
#include <fstream>


int main()
{

	double a, b;

	
	try
	{
		std::cout<<"entrez un intervalle [ms]"<<std::endl;
		std::cin>>a>>b;
		
		if (b<=a or b<0 or a <0)
		{
			throw 1;
		}
	
	}
	catch(int x)
	{
		std::cout<<"ERROR l'intervalle n'est pas valable"<< std::endl;
	}
	
	neuron n1(10.0); 
	unsigned int nit = ((b-a)/n1.getH()); // number of iteration for the simulation
	std::cout<<"N1 MPOT !!!! " << n1.getMPot() << std::endl;
	


	/*std::cout<<"enter your input current "<<std::endl;
	std::cin>>Iext;;*/
	
	

	
	std::ofstream file1("membrane potential.txt");

	for (unsigned int i = 0; i < nit; ++i)
	{
		n1.update(i);
		file1 << n1.getMPot()<<"\n"; // store the membrane potential in a file
	
		
		//std::cout<<"time[s]: "<< a <<std::endl;
		std::cout<<"membrane potential[mv] "<<n1.getMPot()<<std::endl;
		
		
	}

	file1.close();
	
	
	return 0;
}
