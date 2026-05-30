#include "orbit.h"
#include "constants.h"
#include "vector.h"

double calculate_parameter(vec3 h)
{
    // magnitude of H
    double H = mag(h);

    // p = h^2 / mu
    double mu;
    switch (h.unit)
    {
        case KM: mu = MU/1e9; break;
        case M: mu = MU; break;
    }

    return (H*H) / mu;
}

vec3 calculate_angular_m(vec3 r, vec3 v)
{
    return cross(r, v);
}

vec3 calculate_node_vector(vec3 h)
{
    vec3 K;
    switch (h.unit) 
    {
        case KM: K = VEC3_IN_KM(0.0, 0.0, 1.0); break;       
        case M: K = VEC3_IN_M(0.0, 0.0, 1.0); break;
    }
    return cross(K, h);
}