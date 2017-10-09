#include <iostream>
#include <ctime>
#include "neuron.hpp"
#include <cmath>
#include <fstream>


int main()
{

	double a, b;
	
	try
	{
		std::cout<<"entrez un intervalle [s]"<<std::endl;
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
	
	double Iext;
	std::cout<<"enter your input current [mv]"<<std::endl;
	std::cin>>Iext;;
	
	
	double h (0.002); // choice of the step

	const double tau (0.02); //20 ms
	const double c (1.0);
	neuron n1(0.0);
	double R(tau/c);
	double expn(exp(-h/tau));
	double cste ((R/tau)*(1-expn));
	std::ofstream file1("membrane potential.txt");

	while (a<=b) //while a is <=b incrase a = a+h
	{
		a+=h;
		n1.update(a, expn, cste,Iext);
		file1 << n1.getMPot()<<"\n";
		std::cout<<"time[s]: "<< a <<std::endl;
		std::cout<<"membrane potential[mv] "<<n1.getMPot()<<std::endl;
	}

	file1.close();
	
	
	return 0;
}
