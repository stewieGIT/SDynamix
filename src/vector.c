#include "vector.h"
#include <math.h>

/*
 * INPUT V > OUTPUT MAGNITUDE OF VECTOR V
*/
double mag(vec3 v)
{
    return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

/*
 * INPUT V1, V2 > OUTPUT DOT PRODUCT BETWEEN VECTOR V1 AND V2
*/
double dot(vec3 v1, vec3 v2)
{
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/*
 * INPUT V1, V2 > OUTPUT SUM OF VECTORS V1 AND V2
*/
vec3 sum(vec3 v1, vec3 v2)
{
    vec3 ret = { 0.0, 0.0, 0.0 };
    ret.x = v1.x + v2.x;
    ret.y = v1.y + v2.y;
    ret.z = v1.z + v2.z;
    return ret;
}

/*
 * INPUT V1, V2 > OUTPUT SUBTRACTION BETWEEN VECTOR V1 AND V2
*/
vec3 sub(vec3 v1, vec3 v2)
{
    vec3 ret = { 0.0, 0.0, 0.0 };
    ret.x = v1.x - v2.x;
    ret.y = v1.y - v2.y;
    ret.z = v1.z - v2.z;
    return ret;
}

/*
 * INPUT V1, V2 > OUTPUT MULTIPLICATION BETWEEN VECTOR V1 AND V2
*/
vec3 mul(vec3 v, double s)
{
    vec3 ret = { 0.0, 0.0, 0.0 };
    ret.x = v.x * s;
    ret.y = v.y * s;
    ret.z = v.z * s;
    return ret;
}

/*
 * INPUT V1, V2 > OUTPUT CROSS PRODUCT BETWEEN VECTOR V1 AND V2
*/
vec3 cross(vec3 v1, vec3 v2)
{
    vec3 ret = { 0.0, 0.0, 0.0 };
    ret.x = v1.y * v2.z - v1.z * v2.y;
    ret.y = -(v1.x * v2.z - v1.z * v2.x);
    ret.z = v1.x * v2.y - v1.y * v2.x;
    return ret;
}