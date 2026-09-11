#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct {
    double real;
    double imag;
} Complex;

Complex add(Complex a, Complex b) {
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

Complex sub(Complex a, Complex b) {
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

Complex multiply(Complex a, Complex b) {
    Complex c;

    c.real = a.real*b.real - a.imag*b.imag;
    c.imag = a.real*b.imag + a.imag*b.real;

    return c;
}

// Recursive FFT
void FFT(Complex a[], int n, int invert) {

    if(n == 1)
        return;

    Complex even[n/2];
    Complex odd[n/2];

    int i;

    for(i = 0; i < n/2; i++) {
        even[i] = a[2*i];
        odd[i] = a[2*i+1];
    }

    FFT(even, n/2, invert);
    FFT(odd, n/2, invert);

    double angle = 2 * PI / n * invert;

    Complex w = {1, 0};

    Complex wn;
    wn.real = cos(angle);
    wn.imag = sin(angle);

    for(i = 0; i < n/2; i++) {

        Complex t = multiply(w, odd[i]);

        a[i] = add(even[i], t);
        a[i+n/2] = sub(even[i], t);

        w = multiply(w, wn);
    }

    if(invert == -1) {
        for(i = 0; i < n; i++)
            a[i].real /= 2;
    }
}

int main() {

    int n, m;
    int size = 1;

    printf("Enter size of A: ");
    scanf("%d", &n);

    printf("Enter size of B: ");
    scanf("%d", &m);

    while(size < n + m - 1)
        size *= 2;

    Complex A[size];
    Complex B[size];

    for(int i = 0; i < size; i++) {
        A[i].real = 0;
        A[i].imag = 0;

        B[i].real = 0;
        B[i].imag = 0;
    }

    printf("Enter A:\n");

    for(int i = 0; i < n; i++)
        scanf("%lf", &A[i].real);

    printf("Enter B:\n");

    for(int i = 0; i < m; i++)
        scanf("%lf", &B[i].real);


    // FFT
    FFT(A, size, 1);
    FFT(B, size, 1);


    // Point-wise multiplication
    for(int i = 0; i < size; i++)
        A[i] = multiply(A[i], B[i]);


    // Inverse FFT
    FFT(A, size, -1);


    printf("Convolution:\n");

    for(int i = 0; i < n + m - 1; i++)
        printf("%.0f ", A[i].real);

    return 0;
}