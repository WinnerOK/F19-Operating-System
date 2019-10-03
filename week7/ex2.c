#include <stdio.h>
#include <stdlib.h>

int main() {

    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int *arr;
    arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        arr[i] = i;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    free(arr);
    puts("");
    return 0;
}