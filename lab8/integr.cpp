#include <stdio.h>
#include <math.h>
#include "integr.h"

double trape_area(double x1, double x2) {
    double y1 = cos(x1);
    double y2 = cos(x2);
    double s;

    s = (y1 + y2) * (x2 - x1) / 2;

    return s;
}

double integration(double x1, double x2, double eps) {
    double s = trape_area(x1, x2); 
    double s_new = 0, x, step, delta = s;
    int n = 1;

    while (delta > eps) {
        n *= 10; 
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
    }
    return s_new;
}
