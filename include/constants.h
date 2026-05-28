#ifndef CONSTANTS_H
#define CONSTANTS_H

#define PI 3.1415926
#define E_RADIUS 6371e3
#define MU 3.986e14

#define KM2M(x) ((double)x * 1e3)
#define M2KM(x) ((double)x / 1e3)

enum M_UNIT {
    CM,
    M,
    KM
};

#endif