#include <iostream>
#include "neuron.hpp"
#include "cortex.hpp"
#include <fstream>
#include "experiment.hpp"

//hello world
int main()
{
	// two possibility: display plots (PART1) or make your own simulation (PART2):
	char ch('z');
	do
	{
		try
		{
			std::cout<<" press p to start plots" << std::endl;
			std::cout<<" press s to start your own simulation" << std::endl;
			std::cin>>ch;
			if((ch!='p') and (ch!='s')) {throw('h');}
		}
		catch (char h)
		{
			std::cout<<"please enter p to display plots or s for you own simulation"<<std::endl;
		}
	} while ((ch!='p') and (ch!='s'));
	
// PART 1:
	if (ch =='p')
	{
		
	int plot(7);
	do
	{
		try
		{
			std::cout<<"which plot do you want to create: 1, 2, 3 or 4 ?"<<std::endl
			;
			std::cin>>plot;
			if((plot!=1) and (plot!=2) and (plot!=3) and (plot!=4)) {throw(8);}
		}
		catch (int i)
		{
			std::cout<<"please enter 1, 2, 3 or 4 to create the plot you're interested in"<<std::endl;
		}
	} while ((plot!=1) and (plot!=2) and (plot!=3) and (plot!=4));
		
		//plot1
		if(plot==1)
		{
			std::cout<<"plot 1"<< std::endl;
			experiment plot1;
			std::cout<< "simulation for plot 1...please wait "<< std::endl;
			std::ofstream plot_1 ("plot_1.csv");
			if (plot_1.fail()){std::cout<<"impossible to open the file ''plot_1''"<<std::endl;}
			else {plot1.simulation(3,2,600,plot_1);}
			plot_1.close();
		}
		//plot2
		if(plot==2)
		{
			std::cout<<"plot 2"<< std::endl;
			experiment plot2;
			std::cout<< "simulation for plot 2...please wait "<< std::endl;
			std::ofstream plot_2 ("plot_2.csv");
			if (plot_2.fail()){std::cout<<"impossible to open the file ''plot_2''"<<std::endl;}
			else {plot2.simulation(6,4,1200,plot_2);}
			plot_2.close();
		}
		//plot3
		if(plot==3)
		{
			std::cout<<"plot 3"<< std::endl;
			experiment plot3;
			std::cout<< "simulation for plot 3...please wait "<< std::endl;
			
			std::ofstream plot_3 ("plot_3.csv");
			if (plot_3.fail()){std::cout<<"impossible to open the file ''plot_3''"<<std::endl;}
			else {plot3.simulation(5,2,1200,plot_3);}
			plot_3.close();
		}
		//plot4
		if(plot==4)
		{
			std::cout<<"plot 4"<< std::endl;
			experiment plot4;
			std::cout<< "simulation for plot 4...please wait "<< std::endl;
			std::ofstream plot_4 ("plot_4.csv");
			if (plot_4.fail()){std::cout<<"impossible to open the file ''plot_4''"<<std::endl;}
			else {plot4.simulation(4.5,0.9,1200,plot_4);}
			plot_4.close();
		}
	}


// PART 2: create your own simulation
else if (ch == 's')
{
		double a, b;
	do
	{
		try
			{
				std::cout<<"Please enter an interval [ms]"<<std::endl;
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
	// do you want to display ?
	char y('z');
	do
	{
		try
		{
			std::cout<<"would you like to display the spikes time and the number of connections in your cortex yes: y no: n?"<<std::endl;
			std::cin>>y;
			if((y!='y') and (y!='n')) {throw(5.0);}
		}
		catch (double x)
		{
			std::cout<<"please enter yes:y or no:n"<<std::endl;
		}
	} while ((y!='y') and (y!='n'));

	bool display;
	if(y=='y'){display=true;}
	else if(y=='n'){display=false;}

	// initiate the vector of pointer:
		std::cout<<"initialization of neurons in the cortex..."<<std::endl;

		for (unsigned int i = 0; i < ne; i++)
		{
			c.initiateNeurons(new neuron(0.0, 1.01 , true, display,true));
		}
		for (unsigned int i = 0; i < ni; i++)
		{
			c.initiateNeurons(new neuron(0.0, 1.01, false, display,true));
		}

	//initilize the random connexions between neurons;
		std::cout<<"making connections..."<<std::endl;
		
		if(c.getNeuronsi(0)->getDisplay()==false) {c.createConnexions(ne, ni);} //won't display and count: speed +++
		else{c.createCountConnexions(ne, ni);} // display the number of connections, will count: speed++
		
	//update all neurons:
		std::cout<< "simulation for "<< ne << " excitatory neurons and "<< ni << " inhibitory neurons starts" << std::endl;
		unsigned int nit = (unsigned int) ((b-a)/c.getH()); // number of iteration for the simulation
		c.updates(nit,false);
		
	// store  in a file
		std::cout<< "storing in file the membrane potentials..."<< std::endl;
		std::ofstream file1 ("membrane_potentials.csv");
		c.storeInFile(file1);
		std::cout<< "end of the simulation..." << std::endl;
		
		return 0;
	}

}
