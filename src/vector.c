#include "vector.h"

static int assert_same_unit(vec3 v1, vec3 v2) {
    if (v1.unit == v2.unit) return 1;

    #ifdef DEBUG
        fprintf(stderr, "[  ERROR   ] Cannot proceed with calculations with mismatched units\n");
    #endif

    return 0;
}

inline vec3 vector_convert_kmtom (vec3 v) {
    return (vec3){ km_to_m(v.x), km_to_m(v.y), km_to_m(v.z), M };
}
inline vec3 vector_convert_mtokm (vec3 v) {
    return (vec3){ m_to_km(v.x), m_to_km(v.y), m_to_km(v.z), KM };
}

double mag(vec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double dot(vec3 v1, vec3 v2)
{
    if (!assert_same_unit(v1, v2))
        return NAN;
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vec3 sum(vec3 v1, vec3 v2)
{
    if (!assert_same_unit(v1, v2))
        return VEC3_INVALID();
    return (vec3){ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.unit };
}

vec3 sub(vec3 v1, vec3 v2)
{
    if (!assert_same_unit(v1, v2))
        return VEC3_INVALID();
    return (vec3){ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.unit };
}

vec3 mul(vec3 v, double s)
{
    return (vec3){ v.x * s, v.y * s, v.z * s, v.unit };
}

vec3 cross(vec3 v1, vec3 v2)
{
    if (!assert_same_unit(v1, v2))
        return VEC3_INVALID();

    double x = v1.y * v2.z - v1.z * v2.y;
    double y = -(v1.x * v2.z - v1.z * v2.x);
    double z = v1.x * v2.y - v1.y * v2.x;
    return (vec3){ x, y, z, v1.unit };
}