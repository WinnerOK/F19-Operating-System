#include <stdio.h>

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void bubble_sort(int *a, int n) {
    int correct;
    do {
        correct = 0;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] > a[i]) {
                swap(&a[i - 1], &a[i]);
                correct = i;
            }
        }
        n = correct;
    } while (n > 1);
}

int main() {
    const int N = 4;
    int a[]= {1,6,3,4, -5};
    bubble_sort(a, N);
    for (int i = 0; i < N; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}