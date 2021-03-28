#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// f(x1, x2) = (x1)^2 + (x2)^2 + x1 + x2 + 6
float dydx1(float x) // derivative of x1
{
    return 2 * x + 1; // dy/dx1 = 2x1 + 1
}
float dydx2(float x) // derivative of x2
{
    return 2 * x + 1; // dy/dx2 = 2x2 + 1
}

int main()
{
    const float alpha = 0.1; // constant alpha = 0.1
    float x1, x2, gradx1, gradx2, err;
    float mag = 100.;
    int iter = 0; // amount of iteration

    cout << "Error: "; cin >> err;
    cout << "x1: "; cin >> x1;
    cout << "x2: "; cin >> x2;
    
    do
    {
        iter++; // incrementing iteration

        gradx1 = dydx1(x1); // gradient of x1
        gradx2 = dydx2(x2); // gradient of x2
        mag = sqrt(pow(gradx1, 2) + pow(gradx2,2)); // magnitude of gradient

        cout << "Iteration " << iter << "\t | x1: " << x1 << "\t | x2: " << x2 << "\t | Magnitude of gradient: " << mag << endl;

        if (mag != 0) // if magnitude is not zero
        {
            x1 -= gradx1 * alpha; // keep decrementing x1
            x2 -= gradx2 * alpha; // keep decrementing x2
        }
    }
    while (mag > err); // repeat until magnitude < error
        
    cout << "Extremum at x1: " << x1 << endl;
    cout << "Extremum at x2: " << x2 << endl;
    cout << "Iteration: \t" << iter << endl;
};