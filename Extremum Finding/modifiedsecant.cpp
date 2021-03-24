#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

// defining the function
double f(double x) { return x * x - 10 * x + 16; } // x^2 - 10x + 16

int main()
{
    double x0, x1, xnew, d0, d1, dnew, y0, y1, err, h;

loop:
    cout << setprecision(6) << fixed;
    cout << "h: "; cin >> h; // h is a small number

    cout << "1st initial: "; cin >> x0; // 1st initial (guess) -> x0
    cout << "2nd initial: "; cin >> x1; // 2nd initial (guess) -> x1

    // turning x into f'(x)
    d0 = (f(x0 + 0.5 * h) - f(x0 - 0.5 * h)) / h; // d0 -> f'(x0)
    d1 = (f(x1 + 0.5 * h) - f(x1 - 0.5 * h)) / h; // d1 -> f'(x1)

    // x0 and x1 both in the left or right side of extremum (if f'(x0) * f'(x1) > 0)
    if (d0 * d1 > 0)
    {
        cout << endl << "f'(x0) * f'(x1) > 0, please re-enter where f'(x0) * f'(x1) < 0\n\n";
        goto loop;
    }

    // setting x1 with (+) d and x0 with (-) d
    if (d1 < d0)
    {
        int temp = x1;
        x1 = x0;
        x0 = temp;
        temp = d1;
        d1 = d0;
        d0 = temp;
    }

    cout << "Error: "; cin >> err; // tolerable error is a small number

    y0 = f(x0);
    y1 = f(x1);

    int N = 0; // iteration
    do
    {
        // interpolation
        xnew = (d0 * x0 - d1 * x1 + y1 - y0) / (d0 - d1);

        dnew = (f(xnew + 0.5 * h) - f(xnew - 0.5 * h)) / h;

        if (dnew > 0)
        {
            x1 = xnew;
            d1 = (f(x1 + 0.5 * h) - f(x1 - 0.5 * h)) / h;
            y1 = f(x1);
        }
        else
        {
            x0 = xnew;
            d0 = (f(x0 + 0.5 * h) - f(x0 - 0.5 * h)) / h;
            y0 = f(x0);
        }
        N++;
        cout << "Iteration " << N << ":\t x = " << setw(10) << xnew << " and f'(x) = " << setw(10) << dnew << '\n';
    } 
    while (abs(dnew) > err); // until f'(xnew) < error

    cout << endl << "Extremum: " << xnew;
}