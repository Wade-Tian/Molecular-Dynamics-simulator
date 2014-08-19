//FastEnsemble.h

#ifndef SIMULATOR_H_
#define SIMULATOR_H_

class Simulator
{
	double RFVoltage;
	double ECVoltage;
	double SimulatedTemperatur;
	double StartVelOfIons;
	int NumberOfIons;
	int MassOfIons;

	
	int Timesteps;
	int StartRecordingOfHistogram;
	int StepsPrRFPeriode;
	int SizeOfHistogramsX;
	int SizeOfHistogramsY;
	int SizeOfHistogramsZ;

	bool IsEveryVariableSet;
	bool SimAllowedToRun();

public:
	// Constructors
	Simulator();
	Simulator(double RFV, double ECV, double SimuT,
		      double StartVel, double IonNumber, double IonMass,
			  double steps, double StartOfHistogram, double RFPeriodeLength,
			  double histx, double histy, double histz);

	// Member funktions
	void SetRFVoltage(double RFV);
	void SetECVoltage(double ECV);
	void SetSimTemperatur(double Temp);
	void SetStartVel(double Vel);
	void SetIonsNumber(int N);
	void SetMass(int m);
	void SetTimesteps(int steps);
	void SetStartTimeOfHistogram(int time);
	void SetLengthOfRFPeriode(int steps);
	void SetSizeOfHistograms(int histx, int histy, int histz);

	void StartSimulation();
	
};
#endif