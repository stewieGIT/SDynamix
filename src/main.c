#include <stdio.h>
#include "vector.h"

int main(int argc, char** argv)
{
    vec3 v1 = { 1.0, 0.0, 1.5};
    vec3 v2 = { 2.3, 4.1, 11.2};
    
    printf("mag v1: %lf\n", mag(v1));
    printf("dot product: %lf\n", dot(v1, v2));

    vec3 r1 = sum(v1, v2);
    printf("sum: %lf %lf %lf\n", r1.x, r1.y, r1.z);

    vec3 r2 = sub(v1, v2);
    printf("sub: %lf %lf %lf\n", r2.x, r2.y, r2.z);

    vec3 r3 = cross(v1, v2);
    printf("cross: %lf %lf %lf\n", r3.x, r3.y, r3.z);

    vec3 r4 = mul(v1, 3.0);
    printf("mul: %lf %lf %lf\n", r4.x, r4.y, r4.z);
    
    return 0;
}