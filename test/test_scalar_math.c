#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#include "scalar_math.h"

Size num_passed = 0;
Size num_failed = 0;

void log_test(bool passed) {
    if (passed) {
        printf(".");
        num_passed++;
    } else {
        printf("F");
        num_failed++;
    }
}

void log_end() {
    if (num_failed == 0) {
        printf(" OK (%zu)", num_passed);
    } else {
        printf(" F (%zu)", num_failed);
    }
    printf("\n");
}

void test_scalar_log_isnan(Scalar x) {
    log_test( isnan(scalar_log(x)) );
}

void test_scalar_log_exact(Scalar x, Scalar expected) {
    log_test( scalar_log(x) == expected );
}

void test_scalar_log_approx(Scalar x, Scalar expected) {
    log_test( fabs(scalar_log(x) - expected) <= 1e-12 );
}

void test_scalar_log_nan()    { test_scalar_log_isnan(NAN);                        }
void test_scalar_log_minf()   { test_scalar_log_isnan(-INFINITY);                  }
void test_scalar_log_m1()     { test_scalar_log_isnan(-1.0);                       }
void test_scalar_log_0()      { test_scalar_log_isnan( 0.0);                       }
void test_scalar_log_e()      { test_scalar_log_approx(E, 1.0);                    }
void test_scalar_log_1()      { test_scalar_log_exact(1.0, 0.0);                   }
void test_scalar_log_inf()    { test_scalar_log_exact(INFINITY, INFINITY);         }
void test_scalar_log_1em312() { test_scalar_log_approx(1e-312, log(1e-312));       }
void test_scalar_log_2m1074() { test_scalar_log_approx(0x1p-1074, log(0x1p-1074)); }

int main(void) {
    test_scalar_log_nan();
    test_scalar_log_minf();
    test_scalar_log_m1();
    test_scalar_log_0();
    test_scalar_log_e();
    test_scalar_log_1();
    test_scalar_log_inf();
    test_scalar_log_1em312();
    test_scalar_log_2m1074();
    log_end();

    return (num_failed > 0);
}
