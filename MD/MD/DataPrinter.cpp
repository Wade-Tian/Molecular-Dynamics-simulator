#include "DataPrinter.h"


DataPrinter::DataPrinter(FastEnsemble crystal, int Histx, int Histy, int Histz)
{
		// Saves histogram data to file
	ofstream Histogramfile ("HistogramData.txt");
	Histogramfile << "Bin  i j k" << endl ;

	ofstream VHistfile ("VelocityHistogramData.txt");
	VHistfile << "Sum of all velocity in this bin  i \t j \t k" << endl ;

	ofstream CHistfile ("CountHistogramData.txt");
	CHistfile << "bin  i j k" << endl ;

	for(int i=0; i < Histx; i++)
	{
		for(int j=0; j < Histy; j++)
		{
			for(int k=0; k < Histz; k++)
			{
				if (Histogramfile.is_open())
				{
					Histogramfile	<< crystal.ReturnHist(i, j, k)				<< ",  " 
									<< i										<< ",  " 
									<< j										<< ",  " 
									<< k				
									<< endl;

				}
				if (VHistfile.is_open())
				{
					VHistfile		<< crystal.ReturnVelHist(i, j, k)			<< ",  " 
									<< i										<< ",  " 
									<< j										<< ",  " 
									<< k				
									<< endl;

				}
				if (CHistfile.is_open())
				{
					CHistfile		<< crystal.ReturnCountHist(i, j, k)			<< ",  " 
									<< i										<< ",  " 
									<< j										<< ",  " 
									<< k				
									<< endl;

				}
			}
		}
	}

	Histogramfile.close();
	VHistfile.close();
	CHistfile.close();

	crystal.SaveIonDataToFile();


}

DataPrinter::~DataPrinter(void)
{
}

