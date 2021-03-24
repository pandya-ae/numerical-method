#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(float x)
{
    double temp = pow(x, 2) + 2 * x + 1; // x^2 + 2x + 1
    return temp;
}

double derivate(float x)
{
    float h = 0.000001;
    double temp = (f(x + h) - f(x)) / h;
    return temp;
}

void NaiveSearch(float x)
{
    float e = 0.0000001;
    float alpha = 0.2;
    double Xnew = 0;
    int iteration = 0;
    double temp = 0;
    while(derivate(x) >= e)
    {
        temp = x;
        Xnew = x - derivate(x) * alpha;
        x = Xnew;
        iteration++;
    }
    cout << "Extremum: " << temp << endl;
    cout << "Iteration: " << iteration << endl;
}

int main()
{
    NaiveSearch(-1);
    return 0;
}