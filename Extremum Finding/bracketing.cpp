#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

float dydx(float x)
{
    float derivative = 2 * x - 2; // function = x^2 - 2x + 1
    return derivative;
}

float check(float x1, float x2)
{
    float tempx1 = dydx(x1);
    float tempx2 = dydx(x2);
    
    if (tempx1 * tempx2 < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

int main()
{
    float x1, x2;
    bool status = false;
    
    cout << "Enter two numbers: ";
    cin >> x1 >> x2;
    
    // if f'(x1) * f'(x2) < 0, then the loop stops iterating
    while (status == false) { 
        status = check(x1, x2);
        if (status == true)
        {
            break;
        }
        else
        {
            cout << "Enter two numbers: ";
            cin >> x1 >> x2;
        }
    }
    
    float xnew;
    float error = 100.;
    int count = 0;
    
    while (fabs(error) > 1.e-5)
        {
            count++;
            xnew = (x1 + x2)/2.;
            float dydx_xnew = dydx(xnew);
            if ((dydx_xnew > 0) && (dydx(x1) > 0))
                x1 = xnew;
            else if ((dydx_xnew < 0) && (dydx(x1) < 0))
                x1 = xnew;
            else if ((dydx_xnew > 0) && (dydx(x2) > 0))
                x2 = xnew;
            else if ((dydx_xnew < 0) && (dydx(x2) < 0))
                x2 = xnew;
                
            error = dydx(xnew);
            printf("iteration %d, x_new=%f f(x)=%f\n", count, xnew, dydx(xnew));
        }
        
        printf("the extrenum is %f and f(x)=%f \n", xnew, dydx(xnew));
};