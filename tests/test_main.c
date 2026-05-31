#include "test.h"
#include <stdio.h>

int main()
{
    printf("[==========] Running SDynamix Test Suite...\n");
    int total_failures = 0;

    printf("\n");
    printf("[==========] Running Vector Tests...\n");
    total_failures += run_vector_tests();
    printf("[==========] Completed Vector Tests...\n");
    printf("\n");
    printf("[==========] Running Orbit Tests...\n");
    total_failures += run_orbit_tests();
    printf("[==========] Completed Orbit Tests...\n");
    printf("\n");

    printf("[==========] Test Suite Finished.\n");
    if (total_failures == 0) 
    {
        printf("[  PASSED  ] All math properties validated.\n");
        return 0;
    }
    else 
    {
        printf("[  FAILED  ] Test blocks broke constraints.\n");
        return 1;
    }
}