//
#include "FastEnsemble.h"
// To save files.
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdarg.h>

	using namespace std;

class DataPrinter
{
public:
	DataPrinter(FastEnsemble crystal,int Histx, int Histy, int Histz);
	~DataPrinter(void);
};

