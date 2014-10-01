//FastIon.h

#ifndef FASTION_H_
#define FASTION_H_


#include "integrator.h"
#include <cstring>

class FastEnsemble;

class FastIon
{
public:
	double m;	  	// Ion mass [kg]
	double charge;  // charge [C] 
	double *Pos; 	// pointer to array of size: 3 but memory is not allocated before member function initialize
	double *Vel; 	// pointer to array of size: 3 but memory is not allocated before member function initialize
//public:
	// member functions
	void CleanUpIon();
	void initialize(int mass, double c); // mass [amu] c [electron charge]. allocate memory for Pos and Vel.
	void SetPosition(int dim, double Val); // set position
	void SetVelocity(int dim, double Val); // set velocity
	double GetMass();
	double GetVsec();
	double GetCharge();
	double Position(int dim); // returning position
	double Velocity(int dim); // returning velocity
	double Velocity(); // return norm of velocity
	double Ekin(); // return kinetic energy
	
	// friend functions
	friend double DistanceSquar(FastIon & ion1, FastIon & ion2);
	friend double Distance(FastIon & ion1, FastIon & ion2);
	friend double Ffriction(FastEnsemble & ensemble, int N, int dim);
	friend double Ftrap(FastEnsemble & ensemble, int N, int TimeStep, int dim, double Vrf, double Vend, double dt);
	friend double Fcoulumb(FastEnsemble & ensemble, int N, int dim);

};

#endif
