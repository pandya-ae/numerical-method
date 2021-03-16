#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
	float temp = pow(x,2)-(2*x)-8;
	return(temp);
}

float df(float x)
{
	float temp = 2*x-2;
	return(temp);
}

int main()
{
	float x=10.;	//random
	float error=100.;
	float x_new;
	int count=0;
	
	while (fabs(error) > 1.e-5)
	{
		count++;
		float c=f(x)-(df(x)*x);
		x_new=(0-c)/df(x);
		error = f(x_new);
		x=x_new;
		printf("iteration %d, x_new=%f, c=%f\n", count, x_new, c);
	}
	
	printf("the root is=%f and f(x)=%f\n", x_new, f(x_new));
}
