/*
* Program finds the mean of a given signal
*/

#include <stdio.h>
#include <stdlib.h>

#define SIGNAL_LENGTH 320
//*********************************************************************
// Function prototype
// ********************************************************************
double cal_signal_mean(double *signal_source_arr, int signal_length);

// ********************************************************************
// Access to external files, and variables names
// ********************************************************************
extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGTH];          // Gives us access to our waveforms file
double MEAN;
int i;


int main()
{
    MEAN = cal_signal_mean(&InputSignal_f32_1kHz_15kHz[0],SIGNAL_LENGTH);
    printf("\n\nMean = %f\n\n\n",MEAN);

    return 0;
}

// Function which will do the calculation
double cal_signal_mean(double *signal_source_arr, int signal_length)
{
    double _mean = 0.0;
    for(i = 0 ; i < signal_length; i++)
    {
        _mean = _mean + signal_source_arr[i];
    }
    _mean = _mean/(double)signal_length;
    return _mean;
}
