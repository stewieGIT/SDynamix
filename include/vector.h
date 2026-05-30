/**
 * @file vector.h
 * @brief Core 3D vector math library with active unit tracking for SDynamix.
 * * This header defines the vec3 structural primitives, unit conversion utilities, 
 * and strict compile/runtime unit assertions for orbital mechanics math.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <assert.h>
#include "constants.h"

typedef struct
{
    double x;
    double y;
    double z;
    enum M_UNIT unit;
} vec3;

/*
    MACROS FOR VECTOR CREATION
*/
#define VEC3_IN_KM(x_val, y_val, z_val) ((vec3){ .x = x_val, .y = y_val, .z = z_val, .unit = KM })
#define VEC3_ZERO_KM() VEC3_IN_KM(0.0, 0.0, 0.0)
#define VEC3_IN_M(x_val, y_val, z_val) ((vec3){ .x = x_val, .y = y_val, .z = z_val, .unit = M })
#define VEC3_ZERO_M() VEC3_IN_M(0.0, 0.0, 0.0)

#define ASSERT_SAME_UNIT(v1, v2) \
    assert(v1.unit == v2.unit && "[ERROR] Cannot proceed with calculations with mismatched units")

#define PRINT_VEC3(v) printf("x: %lf y: %lf z: %lf [%d]\n", v.x, v.y, v.z, v.unit)

inline vec3 vector_convert_kmtom (vec3 v) {
    return (vec3){ km_to_m(v.x), km_to_m(v.y), km_to_m(v.z), M };
}
inline vec3 vector_convert_mtokm (vec3 v) {
    return (vec3){ m_to_km(v.x), m_to_km(v.y), m_to_km(v.z), KM };
}

/**
 * @brief Calculates the magnitude of the vector v
 * @param v the input vector
 * @return the magnitude of the vector
 */
double mag(vec3 v);

/**
 * @brief Calculates the dot product between vector v1 and v2
 * * Computes the algebraic dot product @f$ \mathbf{v}_1 \cdot \mathbf{v}_2 @f$.
 * * @pre Both input vectors must have matching measurement units.
 * @param v1 the first input vector
 * @param v2 the second input vector
 * @return the dot product between the two vectors
 */
double dot(vec3 v1, vec3 v2);

/**
 * @brief Calculates the sum between vector v1 and v2
 * * @pre Both input vectors must have matching measurement units.
 * @param v1 the first input vector
 * @param v2 the second input vector
 * @return the sum between the two vectors
 */
vec3 sum(vec3 v1, vec3 v2);

/**
 * @brief Calculates the difference between vector v1 and v2
 * * @pre Both input vectors must have matching measurement units.
 * @param v1 the first input vector
 * @param v2 the second input vector
 * @return the difference between the two vectors
 */
vec3 sub(vec3 v1, vec3 v2);

/**
 * @brief Calculates the multiplication between vector v and scalar s
 * @param v the input vector
 * @param s the scalar s
 * @return the multiplication between the vector v and scalar s
 */
vec3 mul(vec3 v, double s);

/**
 * @brief Calculates the cross product between vector v1 and v2
 * * @pre Both input vectors must have matching measurement units.
 * @param v1 the first input vector
 * @param v2 the second input vector
 * @return the cross product between the two vectors
 */
vec3 cross(vec3 v1, vec3 v2);

#endif