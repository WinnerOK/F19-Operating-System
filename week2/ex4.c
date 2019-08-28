#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int main() {
    int a, b;
    printf("Enter 2 integers: ");
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("Swapped: %d %d\n", a, b);
    return 0;
}
