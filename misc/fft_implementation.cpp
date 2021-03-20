// This program takes in an integer N for the first
// line of input. The next two lines contain N + 1
// integers each. Each line represents the coefficients
// of a polynomial. The program outputs the coefficients
// of the polynomial formed by multiplying the input
// polynomials together. It uses a Fast Fourier
// Transform to do this in O(N log N).

// A link to the problem for which this code was made:
// https://mcpt.ca/problem/fft6


#include <iostream>
#include <stdio.h>
#include <complex>
#include <vector>
#include <cmath>

using namespace std;

typedef complex<double> cd;

double pi = 3.14159265358979;

int nextPowerOf2 (int x)
{
    if (x < 0) {
        return 0;
    }
    --x;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x+1;
}

vector<cd> FFT(const vector<cd>& a, int m, cd w) {
    if (m==1) {
        vector<cd> temp(1, a[0]);
        return temp;
    }
    vector<cd> a_even(m/2, 0);
    vector<cd> a_odd(m/2, 0);
    for (int i = 0; i < m/2; i++) {
        a_even[i] = a[2*i];
        a_odd[i] = a[1+(2*i)];
    }
    vector<cd> fft_a_even = FFT(a_even, m/2, w*w);
    vector<cd> fft_a_odd = FFT(a_odd, m/2, w*w);
    vector<cd> fft(m, 0);
    cd x = cd(1, 0);
    for (int i = 0; i < m/2; i++) {
        fft[i] = fft_a_even[i] + x*fft_a_odd[i];
        fft[i+(m/2)] = fft_a_even[i] - x*fft_a_odd[i];
        x *= w;
    }
    
    return fft;
}

vector<cd> convolve(const vector<cd>& a, const vector<cd> b) {
    vector<cd> c(a.size(), 0);
    for (int i = 0; i < a.size(); i++) {
        c[i] = a[i]*b[i];
    }
    
    return c;
}

vector<cd> multiply2Polynomials(const vector<cd>& a_1, const vector<cd>& b_1) {
    vector<cd> ans(0,0);
    
    int greaterVect = max(a_1.size(), b_1.size());
    int length = 2*nextPowerOf2(greaterVect);
    
    vector<cd> a(length-a_1.size(), 0);
    vector<cd> b(length-b_1.size(), 0);
    
    a.insert(a.end(), a_1.begin(), a_1.end());
    b.insert(b.end(), b_1.begin(), b_1.end());
    
    // DFT using recursive FFT
    vector<cd> a_fft = FFT(a, a.size(), cd(cos(2*pi/a.size()), sin(2*pi/a.size())));
    vector<cd> b_fft = FFT(b, b.size(), cd(cos(2*pi/b.size()), sin(2*pi/b.size())));
    
    // Point-wise convolution
    vector<cd> multiply = convolve(a_fft, b_fft);
    // Inverse FFT
    vector<cd> answer = FFT(multiply, multiply.size(), cd(cos(-2*pi/multiply.size()), sin(-2*pi/multiply.size())));
    
    return answer;
}

int main()
{
    int n;
    scanf ("%i", &n);
    vector<cd> a(0,0);
    cd temp1;
    for (int i = 0; i < n+1; i++) {
        cin >> temp1;
        a.push_back(temp1);
    }
    vector<cd> b(0,0);
    cd temp2;
    for (int i = 0; i < n+1; i++) {
        cin >> temp2;
        b.push_back(temp2);
    }
    
    vector<cd> answer = multiply2Polynomials (a, b);
    for (int i = answer.size()-(2*n+2); i < answer.size()-1; i++) {
        cout << (answer[i].real())/answer.size() << " ";
    }
    
    return 0;
}
