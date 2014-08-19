#include "Simulator.h"

#include "integrator.h"
#include "FastEnsemble.h"
#include "DataPrinter.h"
// Constructor
Simulator::Simulator() 
{
	// Nothing has been set it, is not allowed to run;
	IsEveryVariableSet = false;

	// Setting variables to zero, for ease of checking the set values.
	// None of these should ever be zero.
	// Maybe StartRecordingOfHistogram in extreme cases.
	RFVoltage = 0.0;
	ECVoltage = 0.0;
	SimulatedTemperatur = 0.0;
	StartVelOfIons = 0.0;
	NumberOfIons = 0;
	Timesteps = 0;
	StartRecordingOfHistogram = 0;
	StepsPrRFPeriode = 0;
	SizeOfHistogramsX = 0;
	SizeOfHistogramsY = 0;
	SizeOfHistogramsZ = 0;


}

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

void Simulator::SetRFVoltage(double RFV)
{
	RFVoltage = RFV;
}
void Simulator::SetECVoltage(double ECV)
{
	ECVoltage = ECV;
}
void Simulator::SetSimTemperatur(double Temp)
{
	SimulatedTemperatur = Temp;
}
void Simulator::SetStartVel(double Vel)
{
	StartVelOfIons = Vel;
}
void Simulator::SetIonsNumber(int N)
{
	NumberOfIons = N;
}
void Simulator::SetMass(int m)
{
	MassOfIons = m;
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
}
void Simulator::SetSizeOfHistograms(int histx, int histy, int histz)
{
	SizeOfHistogramsX = histx;
	SizeOfHistogramsY = histy;
	SizeOfHistogramsZ = histz;
}

bool Simulator::SimAllowedToRun()
{
	// This is pretty ugly, shame on me.
	if (RFVoltage == 0.0 ) {}
	if (ECVoltage == 0.0) {}
	if (SimulatedTemperatur == 0.0 ) {}
	if (StartVelOfIons == 0.0 ) {}
	if (Timesteps == 0 ) {}
	if (StartRecordingOfHistogram == 0 ) {}
	if (StepsPrRFPeriode == 0) {}
	if (SizeOfHistogramsX == 0 ) {}
	if (SizeOfHistogramsY == 0 ) {}
	if (SizeOfHistogramsZ == 0 ) {}
	else {
		IsEveryVariableSet = true;
	}

	return IsEveryVariableSet;
}

void Simulator::StartSimulation() 
{
	if (SimAllowedToRun() == true ) 
	{
		// If the sim is allowed to run, now the relevant funktions will be called and the simulation will start.

		// Building the crystal.
		FastEnsemble crystal(MassOfIons,NumberOfIons);
		crystal.CrystalGenerator(RFVoltage,ECVoltage);
		crystal.SetSteadyStateTemperature(SimulatedTemperatur);

		// Starting the Integrator with the generate crystal.
		MADSDynamicTemperatureLeFrogintegrator(crystal, Timesteps, RFVoltage, ECVoltage);

		// Printing the data files.
		DataPrinter(crystal,SizeOfHistogramsX,SizeOfHistogramsY,SizeOfHistogramsZ);
	}
	else 
	{

		// Send an error or somethng TODO

	}
}