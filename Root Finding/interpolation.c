#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x)
{
	float temp=pow(x,2)-(2*x)-8;
	return (temp);
}

int check(float x1, float x2)
{
	if (f(x1)*f(x2) > 0)
		return(0);
	else if (f(x1)*f(x2) < 0)
		return(1);
	else
		return(2);
}

float shift_left(float x1, float x2)
{
	int status_check= check(x1,x2);
	float temp_x1;
	
	while (status_check == 0)
	{
		temp_x1 = x1;
		x1 -= 2.;
		if (f(temp_x1) > 0)	//non negative
		{
			if (f(x1) > f(temp_x1))
				return(temp_x1);
			else if (f(x1) < f(temp_x1))
			{
				if (check(x1,x2) == 1)
					return(x1);
				else
					continue;
			}
		}
		
		else if (f(temp_x1) < 0)	//negative
		{
			if (f(x1) < f(temp_x1))
				return(temp_x1);
			else if (f(x1) > f(temp_x1))
			{
				if (check(x1,x2) == 1)
					return(x1);
				else
					continue;
			}
		}
	}
	
	return(x1);
}

float shift_right(float x1, float x2)
{
	int status_check= check(x1,x2);
	float temp_x2;
	
	while (status_check == 0)
	{
		temp_x2 = x2;
		x2 += 2.;
		if (f(temp_x2) > 0)	//non negative
		{
			if (f(x2) > f(temp_x2))
				return(temp_x2);
			else if (f(x2) < f(temp_x2))
			{
				if (check(x1,x2) == 1)
					return(x2);
				else
					continue;
			}
		}
		
		else if (f(temp_x2) < 0)	//negative
		{
			if (f(x2) < f(temp_x2))
				return(temp_x2);
			else if (f(x2) > f(temp_x2))
			{
				if (check(x1,x2) == 1)
					return(x2);
				else
					continue;
			}
		}
	}
	
	return(x2);
}

int main()
{
	float x1, x2;
	int status_check=0;
	
	x1= -1;		//must be less than x2
	x2= 3;
	status_check = check(x1, x2);
	if (status_check == 0)
	{
		x1 = shift_left(x1,x2);
		x2 = shift_right(x1,x2);
	}
	else if (status_check == 2)
	{
		if (f(x1) == 0)
			printf("the root is %f\n", x1);
		else if (f(x2) == 0)
			printf("the root is %f\n", x2);
		
		exit(0);
	}
	
	float error = 100.;
	float x_new;
	int count=0;
	while (fabs(error) > 1.e-5)
	{
		count++;
		x_new = ((x2-x1)*(0-f(x1))/(f(x2)-f(x1)))+x1;
		float f_x_new = f(x_new);
		if ((f_x_new > 0) && (f(x1) > 0))
			x1 = x_new;
		else if ((f_x_new < 0) && (f(x1) < 0))
			x1 = x_new;
		else if ((f_x_new > 0) && (f(x2) > 0))
			x2 = x_new;
		else if ((f_x_new < 0) && (f(x2) < 0))
			x2 = x_new;
			
		error = f(x_new);
		printf("iteration %d, x_new=%f f(x)=%f\n", count, x_new, f(x_new));
	}
	
	printf("the root is %f and f(x)=%f \n", x_new, f(x_new));
}
