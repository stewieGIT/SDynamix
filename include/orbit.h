/**
 * @file orbit.h
 * @brief Orbit calculation functions
 */

#ifndef ORBIT_H
#define ORBIT_H

#include "vector.h"

/**
 * @brief Calculates the orbit parameter given the angular momentum h
 * * Computes the algebraic dot product @f$ \mathbf{v}_1 \cdot \mathbf{v}_2 @f$.
 * @param v the input vector
 * @return the parameter p
 */
double calculate_parameter(vec3 h);

/**
 * @brief Calculates the angular momentum h given r and v vectors
 * * @pre Both input vectors must have matching measurement units.
 * @param r the position vector in geocentric reference frame
 * @param v the velocity vector in geocentric reference frame
 * @return the angular momentum vector h
 */
vec3 calculate_angular_m(vec3 r, vec3 v);

/**
 * @brief Calculates the angular momentum h given r and v vectors
 * @param h the angular momentum vector in geocentric reference frame
 * @return the node vector n
 */
vec3 calculate_node_vector(vec3 h);

#endif