#include "vector.h"
#include <math.h>

#define TOL 1e-6
#define TEST_START(name) int failed = 0; printf("[    RUN   ] %s\n", name)
#define EXPECT_TRUE(cond, msg) if (!(cond)) { printf("[  FAILED  ] %s (Line %d)\n", msg, __LINE__); failed = 1; }
#define EXPECT_NEAR(a, b, tol, msg) if (fabs((a) - (b)) > (tol)) { printf("[  FAILED  ] %s (Line %d: %f != %f)\n", msg, __LINE__, a, b); failed = 1; }
#define TEST_END(name) if (!failed) { printf("[    OK    ] %s\n", name); } else { printf("[  FAILED  ] %s\n", name); }

int test_vector_magnitude()
{
    TEST_START("test_vector_magnitude");

    vec3 v = VEC3_IN_M(3.0, 4.0, 0.0);
    double result = mag(v);

    EXPECT_NEAR(result, 5.0, TOL, "Magnitude math is inaccurate for vector [3, 4, 0]");

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

    // not true its 0.0 but for sake of test
    EXPECT_NEAR(result, 0.0, TOL, "Dot product math failed for perpendicular vectors");

    TEST_END("test_vector_dot_product");

    return failed;
}

int main()
{
    printf("[==========] Running SDynamix Test Suite...\n");
    int total_failures = 0;

    // Run your vector tests here
    total_failures += test_vector_magnitude();
    total_failures += test_vector_dot_product();

    printf("[==========] Test Suite Finished.\n");
    if (total_failures == 0) {
        printf("[  PASSED  ] All math properties validated.\n");
        return 0; // CTest reads 0 as absolute success
    } else {
        printf("[  FAILED  ] Test blocks broke constraints.\n");
        return 1; // Return non-zero to signal a failure to CMake/CI
    }
}