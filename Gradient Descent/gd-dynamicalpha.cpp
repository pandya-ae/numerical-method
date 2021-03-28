#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
using namespace std;

float f(float x1, float x2) // f(x1, x2) = (x1)^2 + (x2)^2 + x1 + x2 + 6
{
    return pow(x1,2) + pow(x2,2) + x1 + x2 + 6;
}
float dfdx1(float x1) // derivative of x1
{
    return 2 * x1 + 1; // df/dx1 = 2x1 + 1
}
float dfdx2(float x2) // derivative of x2
{
    return 2 * x2 + 1; // df/dx2 = 2x2 + 1
}

int main()
{
    float x1, x2, err;
    float a1 = 0, a2 = 1; // alpha 1 and alpha 2 initialization (minimum and maximum value)
    float e = 1.e-8; // small number
    int iter = 0; // amount of iteration

    cout << "Error: "; cin >> err;
    cout << "x1: "; cin >> x1;
    cout << "x2: "; cin >> x2;
    
    float mag = 100.;
    float gradx1, gradx2, ax; // ax: alpha extremum

    do
    {
        iter++; // incrementing iteration

        gradx1 = dfdx1(x1); // gradient of x1
        gradx2 = dfdx2(x2); // gradient of x2
        mag = sqrt(pow(gradx1, 2) + pow(gradx2, 2)); // magnitude of gradient

        cout << "Iteration " << iter << "\t | x1: " << x1 << "\t | x2: " << x2 << "\t | alpha: " << ax << endl;

        // binary search implementation
        if (f(x1 - e, x2 - e) > f(x1 + e, x2 + e))
        {
            a1 = ax;
        }
        else if (f(x1 - e, x2 - e) < f(x1 + e, x2 + e))
        {
            a2 = ax;
        }

        ax = 0.5 * (a1 + a2); // initialization: alpha extremum is in the middle
        x1 -= dfdx1(x1) * ax; // decrementing x1
        x2 -= dfdx2(x2) * ax; // decrementing x2
    }
    while (mag > err); // repeat until magnitude < error

    cout << "Extremum at x1: " << x1 << endl;
    cout << "Extremum at x2: " << x2 << endl;
    cout << "Alpha: \t\t" << ax << endl;
    cout << "Iteration: \t" << iter << endl;
};