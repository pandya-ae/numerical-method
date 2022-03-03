#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>

using namespace std;

float f(float x, float y){
    //return pow(x,2) + pow(y,2) + x + y + 6;
    //return 2*pow(x,2) + 2*pow(y,2) + 3*x + 3*y + 6;
    return 2*pow(x,2) + pow(y,2) + x + y + 12;
    //return pow(x,4) + pow(y,4) + 2*pow(x,3) + 3*pow(y,3) + 2*pow(x,2) + 2*pow(y,2) + x + 4*y +3;
}

float dfdy(float y){
    //return 2*y + 1;
    //return 4*y + 3;
    return 2*y + 1;
    //return 4*pow(y,3) + 9*pow(y,2) + 4*y + 4;
}

float dfdx(float x){
    //return 2*x + 1;
    //return 4*x + 3;
    return 4*x + 1;
    //return 4*pow(x,3) + 6*pow(x,2) + 4*x + 1;
}

bool check (float num1, float num2, float num_mid, float error){
    float difference1 = num1 - num_mid;
    float difference2 = num2 - num_mid;
    if ((fabs(difference1) < error) && (fabs(difference2) < error)){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    float x, y, x1, y1, x2, y2, x_mid, y_mid, error_tolerance;
    float alpha1 = 0, alpha2 = 1;
    float small_num_1 = 0.999;
    float small_num_2 = 1.001;
    int count = 0;
    bool status = false;

    cout << setprecision(3) << fixed;

    cout << "Enter the error tolerance: ";
    cin >> error_tolerance;

    cout << "Enter two numbers: ";
    cin >> x >> y;
    
    float alpha_mid; 

    x1 = x, x2 = x, x_mid = x;
    y1 = y, y2 = y, y_mid = y;

    do{
        count++;
        
        alpha_mid = 0.5 * (alpha1 + alpha2);
        x1 = x_mid - dfdx(x_mid)*small_num_1*alpha_mid;
        x2 = x_mid - dfdx(x_mid)*small_num_2*alpha_mid;
        y1 = y_mid - dfdy(y_mid)*small_num_1*alpha_mid;
        y2 = y_mid - dfdy(y_mid)*small_num_2*alpha_mid;
        x_mid = x_mid - dfdx(x_mid)*alpha_mid;
        y_mid = y_mid - dfdy(y_mid)*alpha_mid;

        cout << x_mid << setw(20) << y_mid << setw(20) << f(x_mid, y_mid) << setw(20) << alpha_mid << setw(20) << count << endl;

        status = check(f(x1, y1), f(x2, y2), f(x_mid, y_mid), error_tolerance);
        if (status == false){
            if (f(x1, y1) < f(x_mid, y_mid)){
                alpha2 = alpha_mid;
            }
            else if (f(x2, y2) < f(x_mid, y_mid)){
                alpha1 = alpha_mid;
            }
        }
        else{
            break;
        }

    } while(status == false && count < 20); 
        
    cout << "Extremum is at x: " << x_mid << " and y: " << y_mid << " alpha: " << alpha_mid << " iteration: "  << count;
};