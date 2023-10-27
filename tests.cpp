//
//  tests.cpp
//  Fourier
//
//  Created by Eric Oliveira  on 10/9/23.
//

#include "unit_test_framework.h"
#include "Functions.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <complex>
#include <iomanip>
#include <chrono>
#include <algorithm>

using namespace std;



//Function that performs DFT and FFT and measures the elapsed time for both
void assert_dft_fft (vector<std::complex<double>> &dft, vector<std::complex<double>> &fft)
{
    cout << endl << "Asserting DFT = FFT...";
    
    for (int i = 0; i < dft.size(); i++)
    {
        ASSERT_ALMOST_EQUAL(real(dft.at(i)), real(fft.at(i)), 14)
        ASSERT_ALMOST_EQUAL(imag(dft.at(i)), imag(fft.at(i)), 14)
    }
}

//Function that compares times for DFT and FFT and retuns a
//pair <DFT, FFT>
pair<vector<std::complex<double>>, vector<std::complex<double>> > time_compare (vector<std::complex<double>> &x)
{
    //DFT
    auto startdft = std::chrono::high_resolution_clock::now(); // Start timer DFT
    
    //Take DFT
    vector<std::complex<double>> DFT = dft(x);
    
    auto stopdft = std::chrono::high_resolution_clock::now(); // Stop timer
    
    //Count time in timer
    auto durationdft = duration_cast<std::chrono::microseconds>(stopdft - startdft);
    
    cout << endl << "*********************************************" << endl;
    
    //Print duration DFT
    cout << " Time elapsed in DFT of size " << DFT.size() << " : " << durationdft.count() << " microseconds (us)" << endl << endl;
    
    //FFT
    
    
    auto startfft = std::chrono::high_resolution_clock::now(); // Start timer FFT
    
    //Take FFT
    vector<std::complex<double>> FFT = fft_rdx2_CT(x);
    
    auto stopfft = std::chrono::high_resolution_clock::now(); // Stop timer
    
    //Count time in timer
    auto durationfft = duration_cast<std::chrono::microseconds>(stopfft - startfft);
    
    //Print duration FFT
    cout << " Time elapsed in FFT of size " << FFT.size() << " : " << durationfft.count() << " microseconds (us)" << endl;
    
    cout << "*********************************************" << endl;
    
    //Build Return pair
    pair<vector<std::complex<double>>, vector<std::complex<double>> > fourier_pair;
    fourier_pair.first = DFT;
    fourier_pair.second = FFT;
    
    return fourier_pair;
    
    
}

//Prints out values of DFT and FFT
void compare_vals (vector<std::complex<double>> &dft, vector<std::complex<double>> &fft)
{
    
    cout << endl << "Comparing DFT and FFT: " << endl << endl;
    
    //DFT
    
    cout << "DFT = { ";
    for (int i = 0; i < dft.size(); i++)
    {
        cout << setprecision(7) << (dft.at(i)) << " ";
    }
    cout << "}" << endl;
    
    //FFT
    
    cout << endl << "FFT = { ";
    for (int i = 0; i < fft.size(); i++)
    {
        cout << fft.at(i) << " ";
    }
    cout << "}" << endl << endl;

}

TEST(test_powers_of_2)
{
    
    //4 SAMPLES
    vector<std::complex<double>> test4 = {1, 2, 3, 0};
    
    vector<std::complex<double>> DFT4 = dft(test4);
    vector<std::complex<double>> FFT4 = fft_rdx2_CT(test4);
    
    assert_dft_fft(DFT4, FFT4);
    
    //64 SAMPLES
    vector<std::complex<double>> test64;
    for (int i = 1; i < 65 ; i++)
    {
        test64.push_back(i);
    }

    //See computing time
    auto fourier64 = time_compare(test64);
    
    //Get DFT and FFT Vectors
    vector<std::complex<double>> DFT64 = fourier64.first;
    vector<std::complex<double>> FFT64 = fourier64.second;
    
    //Assert DFT == FFT
    assert_dft_fft(DFT64, FFT64);

    //256 SAMPLES
    vector<std::complex<double>> test256;
    for (int i = 1; i <= 256 ; i++)
    {
        test256.push_back(i);
    }
    //See computing time
    auto fourier256 = time_compare(test256);
    
    //compare_vals(DFT64, FFT64);
    
    //Get DFT and FFT Vectors
    vector<std::complex<double>> DFT256 = fourier256.first;
    vector<std::complex<double>> FFT256 = fourier256.second;
    
    //Assert equal
    assert_dft_fft(DFT256, FFT256);

    //4096 SAMPLES
    vector<std::complex<double>> test4096;
    for (int i = 1; i <= 4096 ; i++)
    {
        test4096.push_back(i);
    }

    //See computing time
    time_compare(test4096);

//    //32768 SAMPLES
//    vector<std::complex<double>> test32768;
//    for (int i = 1; i <= 32768 ; i++)
//    {
//        test32768.push_back(i);
//    }
    
    //See computing time
    //time_compare(test32768);
}

//TEST(test_odd_input)
//{
//    vector<std::complex<double>> test3 = {1, 2, 3};
//    vector<std::complex<double>> DFT3 = dft(test3);
//    vector<std::complex<double>> FFT3 = fft_padded(test3);
//
//    compare_vals(DFT3, FFT3);
//
//    assert_dft_fft(DFT3, FFT3);
//}

TEST_MAIN()

