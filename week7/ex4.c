#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*
 * To make implementation more universal, I decided to accept old size as an argument,
 * because a way of storing size of allocated memory in memory is system-dependent
 */
void *my_realloc(void *old, size_t old_size, size_t new_size) {
    if (old == NULL) {
        old = (new_size > 0) ? malloc(new_size) : NULL;
        return old;
    } else if (new_size == 0) {
        free(old);
        return NULL;
    } else {

        void *new = malloc(new_size);
        int min_size;
        if (old_size <= new_size){
            min_size = old_size;
        }else{
            min_size = new_size;
        }
        for (size_t i = 0; i < min_size; i++) {
            *((char*)new + i) = *((char*)old + i);
        }
        free(old);
        return new;
    }
}

int main() {
    //Allows you to generate random number
    srand(time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1 = 0;
    scanf("%d", &n1);

    //Create a new array of n1 ints
    int *a1 = (int *) malloc(sizeof(int) * n1);/* Fill in*/
    int i;
    for (i = 0; i < n1; i++) {
        //Set each value in a1 to 100
        /*Fill in*/
        a1[i] = 100;

        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]/*Fill in*/ );
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size: ");
    int n2 = 0;
    scanf("%d", &n2);

    //Dynamically change the array to size n2
    a1 = (int *) my_realloc(a1, sizeof(int) * n1, sizeof(int) * n2);

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

//    if (n2 > n1) {
//        for (i = n1; i < n2; ++i) {
//            a1[i] = 0;
//        }
//    }


    for (i = 0; i < n2; i++) {
        //Print each element out (to make sure things look right)
        printf("%d ", a1[i]);
    }
    printf("\n");

    free(a1);
    //Done with array now, done with program :D

    return 0;
}