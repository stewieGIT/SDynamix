#ifndef VECTOR_H
#define VECTOR_H

#include "constants.h"

typedef struct
{
    double x;
    double y;
    double z;
    enum M_UNIT unit;
} vec3;

#define VEC3_IN_KM(x_val, y_val, z_val) ((vec3){ .x = x_val, .y = y_val, .z = z_val, .unit = KM })
#define VEC3_ZERO_KM() VEC3_IN_KM(0.0, 0.0, 0.0)
#define VEC3_IN_M(x_val, y_val, z_val) ((vec3){ .x = x_val, .y = y_val, .z = z_val, .unit = M })
#define VEC3_ZERO_M() VEC3_IN_M(0.0, 0.0, 0.0)
#define VEC3_IN_KM_TO_M(v) ((vec3){ .x = KM2M(v.x), .y = KM2M(v.y), .z = KM2M(v.z) })
#define VEC3_IN_M_TO_KM(v) ((vec3){ .x = M2KM(v.x), .y = M2KM(v.y), .z = M2KM(v.z) })

double mag(vec3 v);
double dot(vec3 v1, vec3 v2);
vec3 sum(vec3 v1, vec3 v2);
vec3 sub(vec3 v1, vec3 v2);
vec3 mul(vec3 v, double s);
vec3 cross(vec3 v1, vec3 v2);

#endif