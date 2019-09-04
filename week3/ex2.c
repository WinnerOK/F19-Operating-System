#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int *a, int n, int (*cmp)(int, int)) {
    int correct;
    do {
        correct = 0;
        for (int i = 1; i < n; ++i) {
            if (cmp(a[i - 1], a[i])) {
                swap(&a[i - 1], &a[i]);
                correct = i;
            }
        }
        n = correct;
    } while (n > 1);
}

int cmp(int a, int b) {
    // a > b - ascending order
    // a < b - descending order
    return a > b;
}

int main() {
    const int N = 4;
    int a[] = {1, 6, 3, 4, -5};
    bubble_sort(a, N, cmp);
    for (int i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}