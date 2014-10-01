//FastEnsemble.h

#ifndef SIMULATOR_H_
#define SIMULATOR_H_

class Simulator
{
	double RFVoltage;
	double ECVoltage;
	double SimulatedTemperatur;
	double StartVelOfIons;
	
	// For one ion.
	int NumberOfIons;
	int MassOfIons;
	double IonsCharge;

	// For two ions.
	int IonOneMass;
	int IonOneN;
	int IonTwoMass;
	int IonTwoN;
	double IonOneCharge;
	double IonTwoCharge;

	
	int Timesteps;
	int StartRecordingOfHistogram;
	int StepsPrRFPeriode;
	int SizeOfHistogramsX;
	int SizeOfHistogramsY;
	int SizeOfHistogramsZ;

	double r0;
	double z0;
	double eta;
	double binSize;
	double OmegaRF;
	

	bool TwoIonSimulation;
	bool IsEveryVariableSet;
	bool SimAllowedToRun();

public:
	// Constructors
	Simulator();
	//Simulator(double RFV, double ECV, double SimuT,
	//	      double StartVel, double IonNumber, double IonMass,
	//		  double steps, double StartOfHistogram, double RFPeriodeLength,
	//		  double histx, double histy, double histz);

	// Member funktions
	
	// Trap
	void SetRFVoltage(double RFV);
	void SetECVoltage(double ECV);
	void SetEta(double value);
	void SetR0(double value);
	void SetZ0(double value);
	void SetOmegaRF (double value);

	// Simulation
	void SetSimTemperatur(double Temp);
	void SetStartVel(double Vel);
	void SetTimesteps(int steps);
	void SetStartTimeOfHistogram(int time);
	void SetLengthOfRFPeriode(int steps);
	void SetSizeOfHistograms(int histx, int histy, int histz);
	void SetBinSize(double size);

	//Ions
	void SetIonsNumber(int N);
	void SetIonsNumber(int N1,int N2); // For two ions.
	void SetMass(int m);
	void SetMass(int M1, int M2);      // For two ions.
	void SetIonsCharge(double c);
	void SetIonsCharge(double c1, double c2); // For two ions
	
	void StartSimulation();
	
};
#endif