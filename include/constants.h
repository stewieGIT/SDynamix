/**
 * @file constants.h
 * @brief Constants header file
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stdio.h>

#define PI 3.1415926
#define E_RADIUS 6371e3
#define MU 3.986e14

#define PRINT_DOUBLE(x) printf("value: %lf", x)

inline double km_to_m(double x) { return x * 1e3; }
inline double m_to_km(double x) { return x / 1e3; }

enum M_UNIT {
    M,
    KM,
    INVALID_UNIT
};

#endif