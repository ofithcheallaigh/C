/*
* Program finds the variance of a signal
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIGNAL_LENGTH 320
//*********************************************************************
// Function prototype
// ********************************************************************
double cal_signal_mean(double *signal_source_arr, int signal_length);
double calc_signal_variance(double *signal_source_arr, double signal_mean, int signal_length);

// ********************************************************************
// Access to external files, and variables names
// ********************************************************************
extern double InputSignal_f32_1kHz_15kHz[SIGNAL_LENGTH];          // Gives us access to our waveforms file
double MEAN;
double VARIANCE;
int i,j;


int main()
{
    MEAN = cal_signal_mean(&InputSignal_f32_1kHz_15kHz[0],SIGNAL_LENGTH);
    VARIANCE = calc_signal_variance(&InputSignal_f32_1kHz_15kHz[0],MEAN,SIGNAL_LENGTH);
    printf("\n\nVariance = %f\n\n\n",VARIANCE);

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

double calc_signal_variance(double *signal_source_arr, double signal_mean, int signal_length)
{
    double _variance = 0.0;
    for(j = 0; j < signal_length; j++)
    {
        _variance = _variance + pow((signal_source_arr[j]-signal_mean),2);      // Using pow requires math.h to be included
    }
    _variance = _variance/(signal_length-1);
    return _variance;
}
