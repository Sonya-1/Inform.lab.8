#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "integr.h"

int main() {
    double x1 = 0, x2 = M_PI/3, eps;
    printf("Input eps: ");

    long sf_res = scanf("%lf", &eps);
     
    if (sf_res == 0 || 1 <= eps || eps <= 0) {
        printf("Incorrect value\n");
        return 1;
    }
   
    double s = integration(x1, x2, eps);

    printf("Result: %.10f\n", s);

    return 0;
}