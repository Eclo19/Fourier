//
//  Functions.h
//  Fourier
//
//  Created by Eric Oliveira  on 10/9/23.
//

#ifndef Functions_h
#define Functions_h

#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <iomanip>
#include <chrono>

using namespace std;
 

//Take the DFT of vector x
vector<std::complex<double>> dft(vector<std::complex<double>> &x) {
    
    //DTF{x[n]} = \sum_(k = 0, k = N-1) x[n]*exp(-i*2*pi*n*k/N)
    
    //Get size
    long N = x.size();
    
    //Create vector that contains all k values for one n to be summed
    vector<std::complex<double>> toBeSummed;
    
    //Vector X_k is the DFT{x}
    vector<std::complex<double>> X_k;
    
    //loop through all k instances
    for (int k = 0; k < N; k++)
    {
        //loop through all k instances
        for (int n = 0; n < N; n++)
        {
            //Add to sum vec
            toBeSummed.push_back(x.at(n) * polar(1.0, (-1)*2*M_PI*n*k/N));
        }
        //Go through toBeSummed and sum all values into sum variable
        complex<double> sum(0.0, 0.0);
        for (int n = 0; n < N; n++)
        {
            sum += toBeSummed.at(n);
        }
        //Add value of DFT corresponding to n
        X_k.push_back(sum);
        
        //Restart sum variables
        sum = 0;
        toBeSummed.clear();
    }
    
  return X_k;

}

//FFT of radix 2 vectors Cooley and Tukey : Divide and Conquer
vector<std::complex<double>> fft_rdx2_CT (vector<std::complex<double>> &x)
{
    //Get size
    long N = x.size();

    //Base Case
    if(N == 1)
    {
        return x;
    }

    //Create even and odd vectors in time:
    vector<std::complex<double>> even;
    vector<std::complex<double>> odd;

    //Populate even and odd vectors
    for (int n = 0; n < N ; n++)
    {
        //Even
        if (n % 2 == 0) even.push_back(x.at(n));
        //Odd
        else odd.push_back(x.at(n));
    }

    //Recursive call until single element FFT
    vector<std::complex<double>> evenFFT = fft_rdx2_CT(even);
    vector<std::complex<double>> oddFFT = fft_rdx2_CT(odd);

    //Build DFT vector

    //Add first N/2 values
    vector<std::complex<double>> X_k;
    for (int k = 0;  k < N/2; k++)
    {

        X_k.push_back(evenFFT.at(k) + polar(1.0, (-1)*2*M_PI*k / N)* oddFFT.at(k));
    }

    //Add second N/2 values
    for (int k = 0;  k < N/2; k++)
    {

        X_k.push_back(evenFFT.at(k) + polar(1.0, (-1)*2*M_PI*((N/2)+k)/ N)* oddFFT.at(k));
    }

    return X_k;

}

//FFT algorithm with zero padding: pads the end of the signal until it
//has lenght equal to a power of 2 and takes Cooley and Tukey FFT.
vector<std::complex<double>> fft_padded(vector<std::complex<double>> &x)
{
    //Get next power of 2 relative to x's length
    int nextPowerOf2 = pow(2, ceil((float)log2(x.size())));
    
    //Get Zero padded Vector
    vector<std::complex<double>> zero_padded = x;
    
    for (long i = x.size(); i < nextPowerOf2; i++)
    {
        zero_padded.push_back(0);
    }
    
    cout << "Zero padded vector: { ";
    for (int i = 0; i < zero_padded.size(); i++)
    {
        cout << zero_padded.at(i) << " " ;
    }
    cout << "}" << endl;
    
    //Build return vector
    vector<std::complex<double>> X_k;
    
    vector<std::complex<double>> rdx2 = fft_rdx2_CT(zero_padded);
    
    for (int i = 0; i < x.size(); i++)
    {
        X_k.push_back(rdx2.at(i));
    }
    
    return X_k;
    
}

#endif /* Functions_h */
