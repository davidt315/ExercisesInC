#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "minunit.h"
#include "util.h"

// Tests the util.c function: 
int tests_run = 0;

static char *test1_icmpcode_v4() {
    char *res = icmpcode_v4(1);
    char *message = "case 1 for icmpcode_v4 failed: icmpcode_v4(1) should return \"host unreachable\""; 
    mu_assert(message, res == "host unreachable");
}

static char *test2_icmpcode_v4() {
    char *res = icmpcode_v4(5);
    char *message = "case 5 for icmpcode_v4 failed: icmpcode_v4(5) should return \"source route failed\""; 
    mu_assert(message, res == "source route failed");
}

static char *test3_icmpcode_v4() {
    char *res = icmpcode_v4(12);
    char *message = "case 12 for icmpcode_v4 failed: icmpcode_v4(12) should return \"host unreachable for TOS\""; 
    mu_assert(message, res == "host unreachable for TOS");
}

static char * all_tests() {
    mu_run_test(test1_icmpcode_v4);
    mu_run_test(test2_icmpcode_v4);
    mu_run_test(test3_icmpcode_v4);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}