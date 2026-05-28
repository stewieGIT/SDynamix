#ifndef VECTOR_H
#define VECTOR_H

typedef struct
{
    double x;
    double y;
    double z;
} vec3;

double mag(vec3 v);
double dot(vec3 v1, vec3 v2);
vec3 sum(vec3 v1, vec3 v2);
vec3 sub(vec3 v1, vec3 v2);
vec3 mul(vec3 v, double s);
vec3 cross(vec3 v1, vec3 v2);

#endif