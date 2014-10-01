//FastEnsemble.h

#ifndef FASTENSEMBLE_H_
#define FASTENSEMBLE_H_

#include <cmath>
#include <cstring>
#include "integrator.h"
#include <iostream>
#include <fstream>

class FastIon; // dealing with circular dependens same in Ion header.

class FastEnsemble
{
public:
	int NumberOfIons;               // Number of ions in ensemble.
	FastIon *ions;					// pointer to array of ion objects.
	
	long int ***histogram;			// pointer to 3d histogram array of size ?
	long double ***VelHistogram;    // pointer to 3d histogram array of size ?
	long int ***CountHistogram;     // pointer to 3d histogram array of size ?
	double VzSecRMS; // RMS secular z-velocity of ions - used to rescale velocity distribution
	double VrSecRMS; // RMS secular radial-velocity of ions - used to rescale velocity distribution
	double SteadyStateTemperature;  // The temperature simulated.
	double Radius;					// Radius of crystal.
	double Length;					// Length of the crystal

	long double ****histograms;

	int HistNx;
    int HistNy; 
    int HistNz;
	double r0;
	double z0;
	double eta;
	double PixelToDistance;
	double OmegaRF;
	double t0;


	int IonOneN;
	int IonTwoN;
	double ReducedMass;

//public:
	// constructor
	FastEnsemble(int mass, int N, int histx,int histy, int histz,double vel0, double c, double R0, double Z0, double ETA,double wRF, double BinSize);
	FastEnsemble(int m1, int n1, int m2, int n2,int histx,int histy, int histz,double vel0, double c1, double c2, double R0, double Z0, double ETA,double wRF, double BinSize);
	// Member functions
	void CrystalGenerator(double Vrf, double Vend); // set ions initial positions in grid and set initial velocities using the plasma model in bcc structure - under construction
	void RescaleVelocityXYZ(double Total_V_x_rms, double Total_V_y_rms,double Total_V_z_rms);
	void CleanUpEnsemble();
	
	// Ememble set and gets
	void SetSteadyStateTemperature(double Val);
	int GetNumberOfIons();
	double Mass(int N); // returning mass of ion N
	double Position(int dim, int N); // returning position
	double Velocity(int dim, int N); // returning velocity
	double getRho0(double Vrf);
	double GetCurrentTemperature();
	double Ekin(); // return total kinetic energy of crystal for given time step
	double Ttot(); // return total temperature of crystal for given time step
	double GetOmegaRF();
	// Histogram and data functions
	void SavePositionToFile();
	void SaveIonDataToFile();

	void MyUpdateVelocityHistogram();
	void InitialiseHistogram();
	void InitialiseVelocityHistogram();
	void InitialiseCountHistogram();
	void UpdateHistogram();
	void UpdateCountHistogram();

	void InitialiseHistograms();
	void UpdateVelandCountHistograms();
	void UpdateHistograms();

	double ReturnHist(int i, int j, int k); //returning value of bin (i,j,k) in histogram
	double ReturnVelHist(int i, int j, int k); //returning value of bin (i,j,k) in histogram
	double ReturnCountHist(int i, int j, int k);

	// friend function
	friend double DistanceSquar(FastIon & ion1, FastIon & ion2);
	friend double Distance(FastIon & ion1, FastIon & ion2);
	friend double Ftrap(FastEnsemble & ensemble, int N, int TimeStep, int dim, double Vrf, double Vend,double dt);
	friend double Fcoulumb(FastEnsemble & ensemble, int N, int dim);
	friend double Ffriction(FastEnsemble & ensemble, int N, int dim);
};
#endif

