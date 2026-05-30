#include "vector.h"
#include <math.h>

double mag(vec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

double dot(vec3 v1, vec3 v2)
{
    ASSERT_SAME_UNIT(v1, v2);
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

vec3 sum(vec3 v1, vec3 v2)
{
    ASSERT_SAME_UNIT(v1, v2);
    return (vec3){ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.unit };
}

vec3 sub(vec3 v1, vec3 v2)
{
    ASSERT_SAME_UNIT(v1, v2);
    return (vec3){ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.unit };
}

vec3 mul(vec3 v, double s)
{
    return (vec3){ v.x * s, v.y * s, v.z * s, v.unit };
}

vec3 cross(vec3 v1, vec3 v2)
{
    ASSERT_SAME_UNIT(v1, v2);
    double x = v1.y * v2.z - v1.z * v2.y;
    double y = -(v1.x * v2.z - v1.z * v2.x);
    double z = v1.x * v2.y - v1.y * v2.x;
    return (vec3){ x, y, z, v1.unit };
}