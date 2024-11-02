# Fourier Transform Implementation

This repository contains a C++ implementation of various algorithms related to the Fourier Transform, including the Discrete Fourier Transform (DFT), Fast Fourier Transform (FFT), and their inverse functions. The primary goal of this project was to test my knowledge in the Fourier Transform and practice coding recursion algorithms in C++.

## Features

- **Discrete Fourier Transform (DFT)**: A straightforward implementation that computes the DFT of a complex input vector using the mathematical definition.
  
- **Fast Fourier Transform (FFT)**: An efficient implementation based on the Cooley-Tukey radix-2 algorithm, which reduces the computational complexity compared to the DFT.
  
- **Zero Padding for FFT**: A feature to pad the input signal to the next power of two, improving the efficiency of the FFT computation.
  
- **Inverse DFT (IDFT)**: Computes the inverse of the DFT to reconstruct the original signal from its frequency domain representation.

- **Inverse FFT**: Computes the inverse FFT using a conjugate and normalization method.

## Testing

The repository includes a comprehensive testing framework implemented in `tests.cpp`. It utilizes the `unit_test_framework.h`, which was provided by EECS faculty from the University of Michigan for EECS 280 FA 2022. EECS 280 has a website with several free resources for algorithms and data structures [here](https://eecs280.org/).

### Test Functions

- **`assert_dft_fft`**: Validates that the results of DFT and FFT are approximately equal, asserting their values up to 14 decimal places.

- **`time_compare`**: Measures and compares the execution time for DFT and FFT on a given input vector, printing out the time taken for both algorithms.

- **`compare_vals`**: Displays the computed values of DFT and FFT for visual comparison.

