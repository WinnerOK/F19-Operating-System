#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;

    printf("Integer| size: %ld, max_value: %d\n"
           "Float  | size: %ld, max_value: %f\n"
           "Double | size: %ld, max_value: %f\n",
           sizeof(i), i, sizeof(f), f, sizeof(d), d);

    return 0;
}
