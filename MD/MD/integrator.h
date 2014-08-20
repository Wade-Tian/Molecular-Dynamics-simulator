//integrator.h
#ifndef INTEGRATOR_H_
#define INTEGRATOR_H_

#include "FastIon.h"
#include "FastEnsemble.h"
#include <cstring>
#include <iostream>

void MADSDynamicTemperatureLeFrogintegrator(FastEnsemble & ensemble, int TimeSteps, int StartHistograms, double Vrf, double Vend); // Testing temperature control as in articles
void TauPeriodeCudaLeFrogintegrator(FastEnsemble & ensemble, int TimeSteps,int StartHistograms, double Vrf, double Vend);
#endif
