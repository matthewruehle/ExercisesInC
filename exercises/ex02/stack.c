/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    /* Returns a pointer to an array. However, the array can be overwritten -
       don't use this to pass an internal variable out, it's unreliable! */
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = 42;
    }
    return array;
}

void stable_foo(int * target_array) {
    /* Modifies target_array in-place. Could make better by using 
       target_array size parameter, instead of just relying on SIZE. */
    int i;
    for (i=0; i<SIZE; i++) {
        target_array[i] = 42;
    }
}

void bar() {
    /* Makes an array and prints its location. Note that, when run after foo(),
       the location winds up being the same as foo() had previously used. */
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
	array[i] = i;
    }
}

int main()
{
    int i;
    int *array = foo();
    // int array[5]; /* un-comment out for stable version. */
    // stable_foo(array);
    bar();

    for (i=0; i<SIZE; i++) {
	printf("%d\n", array[i]);
    }

    return 0;
}
