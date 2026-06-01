#include "orbit.h"
#include "constants.h"
#include "vector.h"

double calculate_parameter(vec3 h)
{
    if (h.unit == INVALID_UNIT)
        return NAN;

    // magnitude of H
    double H = mag(h);

    // p = h^2 / mu
    double mu;
    switch (h.unit)
    {
        case KM: mu = MU/1e9; break;
        case M: mu = MU; break;
        case INVALID_UNIT: mu = NAN; break;
    }

    return (H*H) / mu;
}

vec3 calculate_angular_m(vec3 r, vec3 v)
{
    if (r.unit == INVALID_UNIT ||
        v.unit == INVALID_UNIT)
        return VEC3_INVALID();
        
    return cross(r, v);
}

vec3 calculate_node_vector(vec3 h)
{
    if (h.unit == INVALID_UNIT)
        return VEC3_INVALID();

    vec3 K;
    switch (h.unit) 
    {
        case KM: K = VEC3_IN_KM(0.0, 0.0, 1.0); break;       
        case M: K = VEC3_IN_M(0.0, 0.0, 1.0); break;
        case INVALID_UNIT: K = VEC3_INVALID(); break;
    }
    return cross(K, h);
}

double calculate_inclination(vec3 h)
{
    if (h.unit == INVALID_UNIT)
        return NAN;

    double h_xy = sqrt(h.x * h.x + h.y * h.y);
    double i = atan2(h_xy, h.z);

    return i * (180 / PI);
}

double calculate_RAAN(vec3 n)
{
    if (n.unit == INVALID_UNIT)
        return NAN;

    double RAAN = atan2(n.y, n.x);
    if (RAAN < 0.0) 
    {
        RAAN += 2 * PI;
    }

    return RAAN * (180.0 / PI);
}