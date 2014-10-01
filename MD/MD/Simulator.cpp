#include "Simulator.h"

#include "integrator.h"
#include "FastEnsemble.h"
#include "DataPrinter.h"
#include <stdio.h>
using namespace std;
// Constructor
Simulator::Simulator() 
{
	// Nothing has been set it, is not allowed to run;
	IsEveryVariableSet = false;

	// Setting variables to zero, for ease of checking the set values.
	// None of these should ever be zero.
	// Maybe StartRecordingOfHistogram in extreme cases.
	RFVoltage					= 0.0;
	ECVoltage					= 0.0;
	SimulatedTemperatur			= 0.0;
	StartVelOfIons				= 0.0;
	NumberOfIons				= 0;
	Timesteps					= 0;
	StartRecordingOfHistogram	= 0;
	StepsPrRFPeriode			= 0;
	SizeOfHistogramsX			= 0;
	SizeOfHistogramsY			= 0;
	SizeOfHistogramsZ			= 0;
	r0							= 0.0;
	z0							= 0.0;
	eta							= 0.0;
	IonOneCharge				= 0.0;
	IonTwoCharge				= 0.0;
	IonsCharge					= 0.0;
	binSize						= 0.0;

}

/*
Simulator::Simulator(double RFV, double ECV, double SimuT,
		      double StartVel, double IonNumber, double IonMass,
			  double steps, double StartOfHistogram, double RFPeriodeLength,
			  double histx, double histy, double histz)
{
	// Lets just set this mess to the right variables.
	RFVoltage = RFV;
	ECVoltage = ECV;
	SimulatedTemperatur = SimuT;
	StartVelOfIons = StartVel;
	NumberOfIons = IonNumber;
	Timesteps = steps;
	StartRecordingOfHistogram = StartOfHistogram;
	StepsPrRFPeriode = RFPeriodeLength;
	SizeOfHistogramsX = histx;
	SizeOfHistogramsY = histy;
	SizeOfHistogramsZ = histz;

	// Everything for a simulation is set, it is allowed to run.
	IsEveryVariableSet = true;

}

*/


// Trap
void Simulator::SetRFVoltage(double RFV)
{
	RFVoltage = RFV;
}
void Simulator::SetECVoltage(double ECV)
{
	ECVoltage = ECV;
}
void Simulator::SetEta(double value) 
{
	eta = value;

}
void Simulator::SetR0(double value)
{
	r0 = value;
}
void Simulator::SetZ0(double value)
{
	z0 = value;

}
void Simulator::SetOmegaRF(double value) 
{
	OmegaRF = value;
}
// Simulation
void Simulator::SetSimTemperatur(double Temp)
{
	SimulatedTemperatur = Temp;
}
void Simulator::SetStartVel(double Vel)
{
	StartVelOfIons = Vel;
}
void Simulator::SetTimesteps(int steps)
{
	Timesteps = steps;
}
void Simulator::SetStartTimeOfHistogram(int time)
{
	StartRecordingOfHistogram = time;
}
void Simulator::SetLengthOfRFPeriode(int steps)
{
	StepsPrRFPeriode = steps;
	// IM JUST GONNA OVERWRITE FOR NOW
	StepsPrRFPeriode = 105;
}
void Simulator::SetSizeOfHistograms(int histx, int histy, int histz)
{
	SizeOfHistogramsX = histx;
	SizeOfHistogramsY = histy;
	SizeOfHistogramsZ = histz;
}
void Simulator::SetBinSize(double size)
{
	binSize = size;
}


// Ions
void Simulator::SetIonsNumber(int N)
{
	NumberOfIons = N;
	TwoIonSimulation = false;
}
void Simulator::SetIonsNumber(int N1, int N2)
{
	IonOneN = N1;
	IonTwoN = N2;
	TwoIonSimulation = true;
}
void Simulator::SetMass(int m)
{
	MassOfIons = m;
}
void Simulator::SetMass(int M1, int M2)
{
	IonOneMass = M1;
	IonTwoMass = M2;
}
void Simulator::SetIonsCharge(double c) 
{
	IonsCharge = c;
}
void Simulator::SetIonsCharge(double c1, double c2) 
{
	IonOneCharge = c1;
	IonTwoCharge = c2;
}



bool Simulator::SimAllowedToRun()
{

	// This is pretty ugly, shame on me.
	if (RFVoltage					== 0.0) {}
	if (ECVoltage					== 0.0) {}
	if (SimulatedTemperatur			== 0.0) {}
	if (StartVelOfIons				== 0.0) {}
	if (Timesteps					== 0 )  {}
	if (StartRecordingOfHistogram	== 0 )  {}
	if (StepsPrRFPeriode			== 0)   {}
	if (SizeOfHistogramsX			== 0 )  {}
	if (SizeOfHistogramsY			== 0 )  {}
	if (SizeOfHistogramsZ			== 0 )  {}
	if (z0							== 0.0) {}
	if (r0							== 0.0) {}
	if (eta							== 0.0) {}
	if (binSize						== 0.0) {}
	if( OmegaRF						== 0.0) {}
	else {
		IsEveryVariableSet = true;
	}

	return IsEveryVariableSet;
}

void Simulator::StartSimulation() 
{
	if (SimAllowedToRun() == true ) 
	{
		if (TwoIonSimulation == true)
		{
			// If the sim is allowed to run, now the relevant funktions will be called and the simulation will start.
			// Building the crystal.
			FastEnsemble crystal(IonOneMass, IonOneN, IonTwoMass, IonTwoN,
								SizeOfHistogramsX,SizeOfHistogramsY,SizeOfHistogramsZ,
								StartVelOfIons,IonOneCharge,IonTwoCharge,r0,z0,eta,OmegaRF,binSize);
			crystal.CrystalGenerator(RFVoltage,ECVoltage);
			crystal.SetSteadyStateTemperature(SimulatedTemperatur);
			cout << "Start of sim " << endl;
			
			// Starting the Integrator with the generate crystal.
			TwoIonDynamicTemperatureLeFrogintegrator(crystal, Timesteps, StartRecordingOfHistogram , RFVoltage, ECVoltage,StepsPrRFPeriode);

			// Printing the data files.
			DataPrinter(crystal,SizeOfHistogramsX,SizeOfHistogramsY,SizeOfHistogramsZ);
		}
		if (TwoIonSimulation == false )
		{
			// If the sim is allowed to run, now the relevant funktions will be called and the simulation will start.
			// Building the crystal.
			FastEnsemble crystal(MassOfIons,NumberOfIons,
								SizeOfHistogramsX,SizeOfHistogramsY,SizeOfHistogramsZ,
								StartVelOfIons,IonsCharge,r0,z0,eta,OmegaRF,binSize);
			crystal.CrystalGenerator(RFVoltage,ECVoltage);
			crystal.SetSteadyStateTemperature(SimulatedTemperatur);

			cout << "Start of sim " << endl;

			// Starting the Integrator with the generate crystal.
			MADSDynamicTemperatureLeFrogintegrator(crystal, Timesteps, StartRecordingOfHistogram ,
													RFVoltage, ECVoltage,StepsPrRFPeriode);

			// Printing the data files.
			DataPrinter(crystal,SizeOfHistogramsX,SizeOfHistogramsY,SizeOfHistogramsZ);
		}
	}
	else 
	{

		cout << "Simulation did not get startet." << endl;

	}
}