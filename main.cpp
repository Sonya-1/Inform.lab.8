#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "q.h"

int main() {
    double x1, x2 = 70000, eps; 
   
    printf("Input x: ");
    long sn_res = scanf("%lf", &x1);

    if (sn_res == 0) {
        printf("Incorrect value\n");
        return 1;
    }


    if (x1 == -INFINITY) {
        printf("Result: 1");
        return 0;
    }

    if (x1 == INFINITY) {
        printf("Result: 0");
        return 0;
    }
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