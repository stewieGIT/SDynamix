#ifndef TEST_H
#define TEST_H

#define TOL 1e-6
#define TEST_START(name) int failed = 0; printf("[    RUN   ] %s\n", name)
#define EXPECT_TRUE(cond, msg) if (!(cond)) { printf("[  FAILED  ] %s (Line %d)\n", msg, __LINE__); failed = 1; }
#define EXPECT_EQUAL(a, b, msg) if (a != b) { printf("[  FAILED  ] %s (Line %d)\n", msg, __LINE__); failed = 1; }
#define EXPECT_NEAR(a, b, tol, msg) if (fabs((a) - (b)) > (tol)) { printf("[  FAILED  ] %s (Line %d: %f != %f)\n", msg, __LINE__, a, b); failed = 1; }
#define EXPECT_VECTOR3_NEAR(a, b, tol, msg) \
    do { \
        if (fabs((a).x - (b).x) > (tol) || \
            fabs((a).y - (b).y) > (tol) || \
            fabs((a).z - (b).z) > (tol)) { \
            printf("[  FAILED  ] %s (Line %d)\n", msg, __LINE__); \
            printf("             Expected: [%f, %f, %f]\n", (b).x, (b).y, (b).z); \
            printf("             Actual:   [%f, %f, %f]\n", (a).x, (a).y, (a).z); \
            failed = 1; \
        } \
    } while(0)
#define TEST_END(name) if (!failed) { printf("[    OK    ] %s\n", name); } else { printf("[  FAILED  ] %s\n", name); }

int run_vector_tests(void);
int run_orbit_tests(void);

#endif