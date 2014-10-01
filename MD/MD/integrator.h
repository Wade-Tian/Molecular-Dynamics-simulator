//integrator.h
#ifndef INTEGRATOR_H_
#define INTEGRATOR_H_

#include "FastIon.h"
#include "FastEnsemble.h"
#include <cstring>
#include <iostream>

void MADSDynamicTemperatureLeFrogintegrator(FastEnsemble & ensemble, int TimeSteps, int StartHistograms, double Vrf, double Vend, double StepsPrPeriode); // 
void TwoIonDynamicTemperatureLeFrogintegrator(FastEnsemble & ensemble, int TimeSteps, int StartHistograms, double Vrf, double Vend, double StepsPrPeriode); // 
void TauPeriodeCudaLeFrogintegrator(FastEnsemble & ensemble, int TimeSteps,int StartHistograms, double Vrf, double Vend);
#endif
