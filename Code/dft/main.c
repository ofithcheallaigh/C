#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// **************** Define statements ****************** //
#define     SIG_LENGTH  320
#define     PI          3.14159265359

// ************ Accessing external files *************** //
double InputSignal_f32_1kHz_15kHz[SIG_LENGTH];
double Output_REX[SIG_LENGTH/2];
double Output_IMX[SIG_LENGTH/2];

// ************* Variables declared ******************** //
int i,j,k;

// ************** Function prototypes ****************** //
void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length);


// *************** Main Function *********************** //
int main()
{
    FILE *fptr1, *fptr2, *fptr3;

    calc_sig_dft((double *)&InputSignal_f32_1kHz_15kHz[0], (double *)&Output_REX[0], (double *)&Output_IMX[0], (int) SIG_LENGTH);

    fptr1 = fopen("input_signal.dat","w");
    fptr2 = fopen("output_rex.dat","w");
    fptr3 = fopen("output_imx.dat","w");

    for(i = 0; i < SIG_LENGTH; i++)
    {
        fprintf(fptr1,"\n%f", InputSignal_f32_1kHz_15kHz[i]);
    }

    for(i = 0; i < SIG_LENGTH/2; i++)
    {
        fprintf(fptr2,"\n%f",Output_REX[i]);
        fprintf(fptr3,"\n%f",Output_IMX[i]);
    }

    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);

    return 0;
}


// **************** DFT Function *********************** //
void calc_sig_dft(double *sig_src_arr, double *sig_dest_rex_arr, double *sig_dest_imx_arr, int sig_length)
{
    for(j = 0; j < sig_length/2; j++)
    {
        sig_dest_rex_arr[j] = 0;            // Initialises output array for Re part to zero
        sig_dest_imx_arr[j] = 0;            // Initialises output array for Im part to zero
    }

    for(k = 0; k < sig_length/2; k++)
    {
        for(i = 0; i < sig_length; i++)
        {
            sig_dest_rex_arr[k] = sig_dest_rex_arr[k] + sig_src_arr[i] * cos(2*PI*k*i/sig_length);
            sig_dest_imx_arr[k] = sig_dest_imx_arr[k] - sig_src_arr[i] * sin(2*PI*k*i/sig_length);
        }
    }
}
