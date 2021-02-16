#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "integr.h"

int main() {
    double x1 = 0.5, x2 = 0.8, eps;
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
