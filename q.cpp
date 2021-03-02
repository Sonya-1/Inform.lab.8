#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include "q.h"

double q_funct(double t) {
    double y, p;

    p = -(t * t) / 2;
    y = 1 / sqrt(2 * M_PI) * pow(M_E, p);
    return y;
}

double trape_area(double x1, double x2) {
    double y1 = q_funct(x1);
    double y2 = q_funct(x2);
    double s;

    s = (y1 + y2) * (x2 - x1) / 2;

    return s;
}

double integration(double x1, double x2, double eps) {
    double s = trape_area(x1, x2);
    double s_new = 0, x, step, delta = s;
    int n = 1, i = 0;

    while (delta > eps) {
        n *= 10;
        //printf("%i   %i   %f\n", i, n, s);

        s_new = 0;
        step = (x2 - x1) / n;

        for (x = x1; x + step / 2 < x2; x += step) {
            s_new += trape_area(x, x + step);
        }

        delta = s_new - s;

        if (delta < 0) {
            delta = -delta;
        }

        s = s_new;
        i++;
    }
    return s_new;
}