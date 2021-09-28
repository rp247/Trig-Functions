#include "mathlib.h"

#include <math.h>
#include <stdio.h>

#define EPSILON 1E-10

/* calculates absolute of a value */
static inline double absolute(double x) {
    return x < 0 ? -x : x;
}

/*
 * arcSin w/ inverse and newton's method 
 * function to find roots of :  sin(x) - x
 * newton's method formula   :  xk+1 = xk - (sin(x) - x)/cos(x) 
 * 				     = xk + (x - sin(x))/cos(x)
 */
double arcSin(double x) {
    double inp_x = 0.0; // initial guess
    double temp_res = 0.1; // xk to be compared to epsilon
    while (absolute(temp_res) > EPSILON) {
        temp_res = (x - sin(inp_x)) / cos(inp_x); // calculating f(xk)/f'(xk)
        inp_x += temp_res; // xk+1 += xk
    }
    return inp_x;
}

/*
 * arcCos w/ inverse and newton's method 
 * function to find roots of :  cos(x) - x
 * newton's method formula   :  xk+1 = xk - (cos(x) - x)/-sin(x) 
 * 				     = xk + (cos(x) - x)/sin(x)
 */
double arcCos(double x) {
    double inp_x = 1.0; // initial guess
    double temp_res = 0.1; // xk to be compared to epsilon
    while (absolute(temp_res) > EPSILON) {
        temp_res = (cos(inp_x) - x) / sin(inp_x); // calculating f(xk)/f'(xk)
        inp_x += temp_res; // xk+1 += xk
    }
    return inp_x;
}

/* 
 * square root with inverse and newton's method 
 * function to find roots of :  xk^2 - x
 * newton's method formula   :  xk+1 = xk - (xk^2 - x)/2xk
 * 				     = xk + (x - xk^2)/2xk
 */
static double sq_root(double x) {
    double inp_x = x / 2; // initial guess
    double temp_res = 0.1; // xk to be compared to epsilon
    while (absolute(temp_res) > EPSILON) {
        temp_res = ((x - (inp_x * inp_x)) / (2 * inp_x)); // calculating f(xk)/f'(xk)
        inp_x += temp_res; // xk+1 += xk
    }
    return inp_x;
}

/*
 * arcTan with the formula arctan = arccos(1/sq_root(1+x^2))
 */
double arcTan(double x) {
    return arcCos(1 / (sq_root(1 + (x * x))));
}

/*
 * calculating e^x with taylor series x^k/k!
 * CREDITS: Code is from the professor's lecture slides 
 */
static double Exp(double x) {
    double term = 1, sum = 1;
    for (int k = 1; absolute(term) > EPSILON; k += 1) {
        term *= x / k; // previous term *= x/k (current term)
        sum += term; // sum so far
    }
    return sum;
}

/* 
 * Log(x) with inverse and newton's method 
 * function to find roots of :  e^xk - x
 * newton's method formula   :  xk+1 = xk - (e^xk - x)/e^xk
 * 				     = xk + (x - e^xk)/e^xk
 */
double Log(double x) {
    double inp_x = 1.0; // initial guess
    double temp_res = 0.1; // xk to be compared to epsilon
    while (absolute(temp_res) > EPSILON) {
        temp_res = ((x - Exp(inp_x)) / Exp(inp_x)); // calculating f(xk)/f'(xk)
        inp_x += temp_res; // xk+1 += xk
    }
    return inp_x;
}
