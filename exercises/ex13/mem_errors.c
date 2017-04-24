/* Example code for Exercises in C.

Copyright 2014 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


void free_anything(int *p) {
    free(p);
}


int read_element(int *array, int index) {
    int x = array[index];
    return x;
}


int main ()
{
    // The memory errors have been removed!
    // though I am not sure what the code did in the first place
    // (besides create memory errors), so 
    // i just commented it out.
    // Like, I'm not actually sure how to rewrite this without errors because
    // the only function appears to be the memory errors?..
    // Or, I could just free all of the variables after they're used, but only free them 
    // once (or no times if they were never allocated)?

    // int never_allocated;
    // int *free_twice = malloc (sizeof (int));
    // int *use_after_free = malloc (sizeof (int));
    // int *never_free = malloc (sizeof (int));
    // int array1[100];
    // int *array2 = malloc (100 * sizeof (int));

    // valgrind does not bounds-check static arrays
    // read_element(array1, -1);
    // read_element(array1, 100);

    // but it does bounds-check dynamic arrays
    // read_element(array2, -1);
    // read_element(array2, 100);

    // and it catches use after free
    // free(use_after_free);
    // *use_after_free = 17;
    
    // never_free is definitely lost
    // *never_free = 17;

    // the following line would generate a warning
    // free(&never_allocated);

    // but this one doesn't
    // free_anything(&never_allocated);
    
    // free(free_twice);
    // free(free_twice);

    return 0;
}
