#include "constants.h"
#include "vector.h"

int main()
{
    vec3 v1 = VEC3_IN_KM(1.0, 0.0, 1.5);
    vec3 v2 = VEC3_IN_KM(2.3, 4.1, 11.2);
    
    PRINT_DOUBLE(mag(v1));
    PRINT_DOUBLE(dot(v1, v2));

    PRINT_VEC3(sum(v1, v2));
    PRINT_VEC3(sub(v1, v2));
    PRINT_VEC3(mul(v1, 3.0));
    PRINT_VEC3(cross(v1, v2));
    
    return 0;
}