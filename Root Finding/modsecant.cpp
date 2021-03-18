#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
using namespace std;

/* Defining equation to be solved. Change this equation to solve another problem. */
double f( double x ) { return x * x * x - 4; } // x^3 - 4

int main()
{
   double x0, x1, f0, f1, eps, h;
   int step = 1, N;

   cout << setprecision(6) << fixed;

   cout << "1st initial: ";   cin >> x0;
   cout << "2nd initial: ";   cin >> x1;
   cout << "Error: ";   cin >> eps;
   cout << "h: ";   cin >> h;    
   cout << "Maximum iteration: ";   cin >> N;

   /* Implementing Secant Method */
   cout << "\n*************\n";
   cout <<   "Secant Method";
   cout << "\n*************\n";
   
   f0 = f(x0);
   f1 = f(x1);

   do
   {
      if ( step > N )
      {
         cout << "Not Convergent";
         exit(0);
      }

      double dfdx = ( f(x1+0.5*h) - f(x1-0.5*h) ) / h;

      if ( dfdx == 0 )
      {
         cout << "Mathematical error";
         exit(0);
      }

      x0 = x1;
      f0 = f1;
      x1 -= f1 / dfdx;
      f1 = f(x1);

      cout << "Iteration-" << step << ":\t x = " << setw(10) << x1 << " and f(x) = " << setw(10) << f1 << '\n';
      
      step++;
   } 

   while ( abs( f1 ) > eps );

   cout << "\nRoot is: " << x1;
}