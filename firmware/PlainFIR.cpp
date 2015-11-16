#include "PlainFIR.h"

PlainFIR::PlainFIR(void) 
{
/* Constructor */
}

PlainFIR::~PlainFIR(void)
{ 
/* Destructor */
}



double PlainFIR::SetFilter(uint8_t filterType, uint16_t order, uint16_t samplingFrequency, uint8_t windowType, uint16_t transition1, uint16_t transition2) 
/* Order shall be an even number in order to simplify the code */
{
      uint16_t _order  = order;
	uint16_t taps = order + 1;
      double * _vFilter = (double *)malloc(taps * sizeof(double)); /* allocate memory for n taps buffer */
	double normTransFreq1 = transition1 / samplingFrequency;
	double normTransFreq2 = transition2 / samplingFrequency;
	/* Compute half + 1 weighing factors, because the filter is symetric */
	for (uint16_t n = 0; n < (order >> 1) + 1; n++) {
		double a = M_PI * (n - (order >> 1));
		double weigthingFactor;
		/* Compute weighing factor */
		switch(filterType){
		case FIR_FIL_TYP_LOW_PASS:
			if (n != (order >> 1)) {
				weigthingFactor = sin(2.0 * normTransFreq1 * a) / a;
			}
			else {
				weigthingFactor = 2.0 * normTransFreq1;
			}
			break;		
		case FIR_FIL_TYP_HIG_PASS:
			if (n != (order >> 1)) {
				weigthingFactor = - sin(2.0 * normTransFreq1 * a) / a;
			}
			else {
				weigthingFactor = 1.0 - (2.0 * normTransFreq1);
			}
			break;		
		case FIR_FIL_TYP_BAN_PASS:
			if (n != (order >> 1)) {
				weigthingFactor = (sin(2.0 * normTransFreq2 * a) - sin(2.0 * normTransFreq1 * a)) / a;
			}
			else {
				weigthingFactor = 2.0 * (normTransFreq2 - normTransFreq1);
			}
			break;		
		case FIR_FIL_TYP_BAN_STOP:
			if (n != (order >> 1)) {
				weigthingFactor = (sin(2.0 * normTransFreq1 * a) - sin(2.0 * normTransFreq2 * a)) / a;
			}
			else {
				weigthingFactor = 1.0 - (2.0 * (normTransFreq2 - normTransFreq1));
			}
			break;			
		};
		/* Apply windowing */
		switch(windowType){
		case FIR_WIN_TYP_BARLETT:
			weigthingFactor *= 1.0 - ((2.0 * abs(n - (order >> 1))) / order);
			break;
		case FIR_WIN_TYP_BLACKMAN:
			weigthingFactor *= 0.42 - (0.5 * cos((2.0 * M_PI * n) / order)) + (0.08 * cos((4.0 * M_PI * n) / order));
			break;
		case FIR_WIN_TYP_RECTANGLE:
			weigthingFactor *= 1.0;
			break;
		case FIR_WIN_TYP_HAMMING:
			weigthingFactor *= 0.5 - (0.46 * cos((2.0 * M_PI * n) / order));
			break;
		case FIR_WIN_TYP_HANN:
			weigthingFactor *= 0.5 - (0.5 * cos((2.0 * M_PI * n) / order));
			break;
		};
		/* Record weighing factors in filter vector */
		_vFilter[n] = weigthingFactor;
		_vFilter[taps - (n +1)] = weigthingFactor;
	}
	return(_vFilter)//////////prosthiki
};
