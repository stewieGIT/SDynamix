#include "test.h"
#include "constants.h"
#include "vector.h"
#include <math.h>

int test_vector_magnitude()
{
    TEST_START("test_vector_magnitude");

    vec3 v = VEC3_IN_M(3.0, 4.0, 0.0);
    double result = mag(v);

    EXPECT_NEAR(result, 5.0, TOL, "Magnitude math is inaccurate for vector  v = [3, 4, 0]");

    vec3 zero = VEC3_ZERO_M();
    EXPECT_NEAR(mag(zero), 0.0, TOL, "Zero vector magnitude must be 0.0");

    TEST_END("test_vector_magnitude");

    return failed;
}

int test_vector_dot_product()
{
    TEST_START("test_vector_dot_product");

    vec3 v1 = VEC3_IN_M(1.0, 0.0, 0.0);
    vec3 v2 = VEC3_IN_M(0.0, 1.0, 0.0);
    double result = dot(v1, v2);

    EXPECT_NEAR(result, 0.0, TOL, "Dot product math failed for perpendicular vectors");

    TEST_END("test_vector_dot_product");

    return failed;
}

int test_vector_dot_product_UNIT_MISMATCH_FAIL()
{
    TEST_START("test_vector_dot_product_UNIT_MISMATCH_FAIL");

    vec3 v1 = VEC3_IN_M(1.0, 0.0, 0.0);
    vec3 v2 = VEC3_IN_M(0.0, 1.0, 0.0);
    v1.unit = KM;
    double result = dot(v1, v2);

    EXPECT_TRUE(isnan(result), "Result of dot product should be NAN on unit mismatch");

    TEST_END("test_vector_dot_product_UNIT_MISMATCH_FAIL");

    return failed;
}

int test_vector_sum()
{
    TEST_START("test_vector_sum");

    vec3 v1 = VEC3_IN_M(1.0, 2.0, 5.0);
    vec3 v2 = VEC3_IN_M(1.5, 1.0, 0.0);
    vec3 result = sum(v1, v2);

    EXPECT_NEAR(result.x, 2.5, TOL, "Property x was incorrect");
    EXPECT_NEAR(result.y, 3.0, TOL, "Property y was incorrect");
    EXPECT_NEAR(result.z, 5.0, TOL, "Property z was incorrect");

    TEST_END("test_vector_sum");

    return failed;
}

int test_vector_sum_UNIT_MISMATCH_FAIL()
{
    TEST_START("test_vector_sum_UNIT_MISMATCH_FAIL");

    vec3 v1 = VEC3_IN_M(1.0, 2.0, 5.0);
    vec3 v2 = VEC3_IN_M(1.5, 1.0, 0.0);
    v1.unit = KM;
    vec3 result = sum(v1, v2);

    EXPECT_TRUE(isnan(result.x), "Vector x should be contaminated with NAN");
    EXPECT_TRUE(isnan(result.y), "Vector y should be contaminated with NAN");
    EXPECT_TRUE(isnan(result.z), "Vector z should be contaminated with NAN");
    EXPECT_EQUAL(result.unit, INVALID_UNIT, "Vector unit state should be flagged with INVALID_UNIT");

    TEST_END("test_vector_sum_UNIT_MISMATCH_FAIL");

    return failed;
}

int run_vector_tests()
{
    int domain_test_failures = 0;

    domain_test_failures += test_vector_magnitude();
    printf("\n");
    domain_test_failures += test_vector_dot_product();
    printf("\n");
    domain_test_failures += test_vector_dot_product_UNIT_MISMATCH_FAIL();
    printf("\n");
    domain_test_failures += test_vector_sum();
    printf("\n");
    domain_test_failures += test_vector_sum_UNIT_MISMATCH_FAIL();

    return domain_test_failures;
}