#ifndef ORBIT_H
#define ORBIT_H

#include "vector.h"

double calculate_parameter(vec3 h);
vec3 calculate_angular_m(vec3 r, vec3 v);
vec3 calculate_node_vector(vec3 h);

#endif