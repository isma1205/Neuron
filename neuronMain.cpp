#include <iostream>
#include "neuron.hpp"
#include <fstream>
#include "cortex.hpp"


int main()
{
	
//create the interval of simultation
	double a, b;
do
{
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
			std::cout<<"ERROR interval not correct"<< std::endl;
		}
} while (b<=a or b<0 or a <0);

		
		

// the number of neurons:
		
	unsigned int ne = 10000; //excitatory
	unsigned int ni= 2500;	 	//inhibitory												
	
		
// create a cortex named c:
	cortex c;				
											 
// initiate the vector of pointer:
	int y(5);
do
{
	try
	{
		std::cout<<"would you like to display the spikes time and the number of connections in your cortex yes: 1 no:0?"<<std::endl;
		std::cin>>y;
		if((y!=0) and (y!=1)) {throw(5.0);}
	}
	catch (double x)
	{
		std::cout<<"please enter 0 or 1"<<std::endl;
	}
} while ((y!=0) and (y!=1));

bool display;
if(y==1){display=true;}
else if(y==0){display=false;}


std::cout<<"initialization of neurons in the cortex..."<<std::endl;

	for (unsigned int i = 0; i < ne; i++)
	{
		c.initiateNeurons(new neuron(0.0, 0.0 , true, display));
	}
	for (unsigned int i = 0; i < ni; i++)
	{
		c.initiateNeurons(new neuron(0.0, 0.0, false, display));
	}

//initilize the random connexions between neurons;
	std::cout<<"making connections..."<<std::endl;
	
	if(c.getNeuronsi(0)->getDisplay()==false) {c.createConnexions(ne, ni);} //won't display and count: speed +++
	else{c.createCountConnexions(ne, ni);} // display the number of connections, will count: speed++
	
	//update all neurons:
	unsigned int nit = (unsigned int) ((b-a)/c.getH()); // number of iteration for the simulation
	
	c.updates(nit);
	
	// store  in a file
	c.storeInFile();

	


	
	return 0;
}
