# Fourier Transform Implementation

This repository contains a C++ implementation of various algorithms related to the Fourier Transform, including the Discrete Fourier Transform (DFT), Fast Fourier Transform (FFT), and their inverse functions. The primary goal of this project was to test my knowledge in the Fourier Transform and practice coding recursion algorithms in C++.

## Features

- **Discrete Fourier Transform (DFT)**: A straightforward implementation that computes the DFT of a complex input vector using the mathematical definition.
  
- **Fast Fourier Transform (FFT)**: An efficient implementation based on the Cooley-Tukey radix-2 algorithm, which reduces the computational complexity compared to the DFT.
  
- **Zero Padding for FFT**: A feature to pad the input signal to the next power of two, improving the efficiency of the FFT computation.
  
- **Inverse DFT (IDFT)**: Computes the inverse of the DFT to reconstruct the original signal from its frequency domain representation.

- **Inverse FFT**: Computes the inverse FFT using a conjugate and normalization method.

## Usage

To use the functions defined in `Functions.h`, include the header file in your C++ project. Below is a simple example demonstrating how to compute the DFT and FFT of a sample signal:

```cpp
#include "Functions.h"

int main() {
    // Sample input signal as a vector of complex numbers
    std::vector<std::complex<double>> signal = {1, 2, 3, 4};
    
    // Compute Discrete Fourier Transform (DFT)
    auto dft_result = dft(signal);
    
    // Compute Fast Fourier Transform (FFT)
    auto fft_result = fft_rdx2_CT(signal);
    
    // Compute Inverse Discrete Fourier Transform (IDFT)
    auto idft_result = idft(dft_result);
    
    // Compute Inverse FFT
    auto ifft_result = ifft_rdx2_CT(fft_result);
    
    return 0;
}
