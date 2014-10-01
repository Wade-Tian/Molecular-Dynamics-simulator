// MolecularDynamics.cpp : Defines the entry point for the console application.
// include from making project in VS-10
#include "stdafx.h"
#include <stdio.h>

// From the original MD.cpp
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "FastEnsemble.h"
#include "integrator.h"
#include "constants.h"
#include "Simulator.h"
// To save files.
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdarg.h>
using namespace std;


int main(int argc, char* argv[])
{	
	if (argc < 19) 
	{
		cout << "Not enough arguments: " <<  argc << endl;
		cout << " press a button to stop the program" << endl;
		cin.get();
		return 0;
	}
	if (argc == 19 )
	{
	cout << "The program is trying to start!" << endl;

	double RFVoltage			= strtod(argv[1], 0);
	double ECVoltage			= strtod(argv[2], 0);
	double SimulatedTemperatur	= strtod(argv[3], 0);
	double StartVelOfIons		= strtod(argv[4], 0);
	int NumberOfIons			=  atoi(argv[5]);
	int MassOfIons				=  atoi(argv[6]);

	
	int Timesteps					= atoi(argv[7]);
	int StartRecordingOfHistogram	= atoi(argv[8]);
	int StepsPrRFPeriode			= atoi(argv[9]);
	int SizeOfHistogramsX			= atoi(argv[10]);
	int SizeOfHistogramsY			= atoi(argv[11]);
	int SizeOfHistogramsZ			= atoi(argv[12]); // Fra før

	double OmegaRF					= strtod(argv[13], 0);
	double r0						= strtod(argv[14], 0);
	double z0						= strtod(argv[15], 0);
	double eta						= strtod(argv[16], 0);
	double binSize					= strtod(argv[17], 0);
	double IonsCharge				= strtod(argv[18],0);
	Simulator sim = Simulator();

	// Setting the values for the simulator.
	sim.SetRFVoltage(RFVoltage);
	sim.SetECVoltage(ECVoltage);
	sim.SetSimTemperatur(SimulatedTemperatur);
	sim.SetStartVel(StartVelOfIons);
	sim.SetIonsNumber(NumberOfIons);
	sim.SetMass(MassOfIons);
	sim.SetTimesteps(Timesteps);
	sim.SetStartTimeOfHistogram(StartRecordingOfHistogram);
	sim.SetLengthOfRFPeriode(StepsPrRFPeriode);
	sim.SetSizeOfHistograms(SizeOfHistogramsX,SizeOfHistogramsY,SizeOfHistogramsZ);
	sim.SetR0(r0);
	sim.SetZ0(z0);
	sim.SetEta(eta);
	sim.SetBinSize(binSize);
	sim.SetOmegaRF(OmegaRF);
	sim.SetIonsCharge(IonsCharge);
	
	/*
	cout << "Parameter for simulation: " << endl
		 << RFVoltage   << endl
		 << ECVoltage << endl
		 << SimulatedTemperatur << endl
		 << StartVelOfIons << endl
		 <<	NumberOfIons << endl
		 << MassOfIons << endl
		 << Timesteps << endl
		 << StartRecordingOfHistogram << endl
		 << StepsPrRFPeriode << endl
		 << SizeOfHistogramsX<< endl
		 << SizeOfHistogramsY<< endl
		 << SizeOfHistogramsZ << endl
		 << r0 << endl
		 << z0 << endl
		 << eta << endl
		 << binSize << endl
		 << OmegaRF << endl
		<< IonsCharge << endl;

	*/
	cout << "Simulation setting up" << endl;
	sim.StartSimulation();

	return 0;
	
	}

	else {

	cout << "The program is trying to start, with more than one ion!" << endl;

	double RFVoltage			= strtod(argv[1], 0);
	double ECVoltage			= strtod(argv[2], 0);
	double SimulatedTemperatur	= strtod(argv[3], 0);
	double StartVelOfIons		= strtod(argv[4], 0);
	int IonOneN					=  atoi(argv[5]);
	int IonOneMass				=  atoi(argv[6]);
	int IonTwoN					=  atoi(argv[7]);
	int IonTwoMass				=  atoi(argv[8]);
	
	int Timesteps					= atoi(argv[9]);
	int StartRecordingOfHistogram	= atoi(argv[10]);
	int StepsPrRFPeriode			= atoi(argv[11]);
	int SizeOfHistogramsX			= atoi(argv[12]);
	int SizeOfHistogramsY			= atoi(argv[13]);
	int SizeOfHistogramsZ			= atoi(argv[14]);

	double OmegaRF					= strtod(argv[15], 0);
	double r0						= strtod(argv[16], 0);
	double z0						= strtod(argv[17], 0);
	double eta						= strtod(argv[18], 0);
	double binSize					= strtod(argv[19], 0);

	double IonsOneCharge			= strtod(argv[20],0);
	double IonsTwoCharge			= strtod(argv[21],0);

	Simulator sim = Simulator();

	// Setting the values for the simulator.
	sim.SetRFVoltage(RFVoltage);
	sim.SetECVoltage(ECVoltage);
	sim.SetSimTemperatur(SimulatedTemperatur);
	sim.SetStartVel(StartVelOfIons);
	sim.SetIonsNumber(IonOneN,IonTwoN);
	sim.SetMass(IonOneMass,IonTwoMass);
	sim.SetTimesteps(Timesteps);
	sim.SetStartTimeOfHistogram(StartRecordingOfHistogram);
	sim.SetLengthOfRFPeriode(StepsPrRFPeriode);
	sim.SetSizeOfHistograms(SizeOfHistogramsX,SizeOfHistogramsY,SizeOfHistogramsZ);
	sim.SetR0(r0);
	sim.SetZ0(z0);
	sim.SetEta(eta);
	sim.SetBinSize(binSize);
	sim.SetOmegaRF(OmegaRF);
	sim.SetIonsCharge(IonsOneCharge,IonsTwoCharge);

	cout << "Parameter for simulation: " << " " << SizeOfHistogramsX << " "<< SizeOfHistogramsY << " "<<
			SizeOfHistogramsZ << " "<< RFVoltage << " " << " "<< ECVoltage << " "<< SimulatedTemperatur <<endl;

	cout << "Simulation setting up" << endl;
	sim.StartSimulation();

	return 0;
	}
}
