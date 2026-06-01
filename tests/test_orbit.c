#include "test.h"
#include "orbit.h"
#include "vector.h"

int test_calculate_parameter()
{
    TEST_START("test_calculate_parameter");

    vec3 h = VEC3_IN_KM(100.0, 200.0, 400.0);
    double p = calculate_parameter(h);

    EXPECT_NEAR(p, 0.526843954, TOL, "Orbit semiparameter calculation was inaccurate for h = [100.0, 200.0, 400.0]");

    TEST_END("test_calculate_parameter");

    return failed;
}

int test_calculate_angular_momentum()
{
    TEST_START("test_calculate_angular_momentum");

    vec3 r = VEC3_IN_KM(300.0, 400.0, 500.0);
    vec3 v = VEC3_IN_KM(7.5, 0.0, 0.0);

    vec3 h = calculate_angular_m(r, v);
    vec3 h1 = VEC3_IN_KM(0.0, 3750.0, -3000.0);
    EXPECT_VECTOR3_NEAR(h, h1, TOL, "Specific angular momentum vector layout incorrect");
    EXPECT_EQUAL(h.unit, h1.unit, "Angular momentum should maintain KM unit scalar context")

    TEST_END("test_calculate_angular_momentum");

    return failed;
}

int test_calculate_inclination()
{
    TEST_START("test_calculate_inclination");

    vec3 h = VEC3_IN_KM(100.0, 200.0, 400.0);

    double i = calculate_inclination(h);

    EXPECT_NEAR(i, 29.205932241, TOL, "Inclination value is not correct");
    
    TEST_END("test_calculate_inclination");

    return failed;
}

int test_calculate_RAAN()
{
    TEST_START("test_calculate_RAAN");

    vec3 n = VEC3_IN_KM(100.0, 200.0, 0.0);

    double RAAN = calculate_RAAN(n);

    EXPECT_NEAR(RAAN, 63.434948855, TOL, "RAAN value is not correct");
    
    TEST_END("test_calculate_RAAN");

    return failed;
}

int run_orbit_tests()
{
    int domain_test_failures = 0;

    domain_test_failures += test_calculate_parameter();
    printf("\n");
    domain_test_failures += test_calculate_angular_momentum();
    printf("\n");
    domain_test_failures += test_calculate_inclination();
    printf("\n");
    domain_test_failures += test_calculate_RAAN();

    return domain_test_failures;
}