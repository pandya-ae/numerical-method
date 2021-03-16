#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
	float temp = pow(x,2)-(2*x)-8;
	return(temp);
}

int main()
{
	float x1=10.;	//random
	float delta=1.e-1;
	float x2=x1+delta;
	float error=100.;
	float x_new;
	int count=0;
	
	while (fabs(error) > 1.e-5)
	{
		count++;
		x_new = (((x2-x1)/(f(x2)-f(x1)))*(0-f(x1)))+x1;
		error = f(x_new);
		x1=x_new;
		x2=x1+delta;
		printf("iteration %d, x_new=%f, f(x)=%f\n", count, x_new, f(x_new));
	}
	
	printf("the root is=%f and f(x)=%f\n", x_new, f(x_new));
}