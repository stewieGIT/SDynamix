#include "orbit.h"
#include "constants.h"
#include "vector.h"

#include <assert.h>

/*
 * THIS METHOD CALCULATES ORBIT PARAMETER GIVEN THE ANGULAR MOMENTUM H
*/
double calculate_parameter(vec3 h)
{
    // magnitude of H
    double H = mag(h);

    // p = h^2 / mu
    double mu;
    switch (h.unit)
    {
        case KM:
        {
            mu = MU/1e9;
            break;
        }

        case M:
        {
            mu = MU;
            break;
        }

        default:
        {
            mu = MU/1e9;
        }
    }

    return (H*H) / mu;
}

vec3 calculate_angular_m(vec3 r, vec3 v)
{
    assert(r.unit == v.unit && "[ERROR] Cannot calculate angular momentum with mismatched units");

    return cross(r, v);
}

vec3 calculate_node_vector(vec3 h)
{
    vec3 K;
    switch (h.unit) 
    {
        case KM: 
        {
            K = VEC3_IN_KM(0.0, 0.0, 1.0);
            break;
        }
        
        case M:
        {
            K = VEC3_IN_M(0.0, 0.0, 1.0);
            break;
        }

        default:
        {
            K = VEC3_IN_KM(0.0, 0.0, 1.0);
        }
    }
    return cross(K, h);
}