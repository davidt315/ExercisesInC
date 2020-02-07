/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int *foo() {
    // creates an array of size 5 and prints the address of the array
    // Then populates the array with a bunch of 42: [42, 42, 42, 42, 42]
    int i;
    int array[SIZE];

    // printf("%p\n", array);

    for (i=0; i<SIZE; i++) {
        array[i] = 42;
    }
    return array;
}

void bar() {
    // Creates an array of size 5 and prints the address of the array
    // Fills the array with numbers from 0-4: [0, 1, 2, 3, 4]
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
    bar();

    for (i=0; i<SIZE; i++) {
        printf("%d\n", array[i]);
    }

    return 0;
}

/* Notes
 * 1. The program is supposed to initialize and fill an array with 
 *    [42, 42, 42, 42, 42], then create new one in bar(). Lastly, it is 
 *    supposed to traverse and print the array pointer created by 
 *    calling foo().
 * 2. warning: function returns address of local variable 
 * 3. Core dumped segmentation fault. In the stack, the local variable
 *    array has memory allocated to it only during the duration of the
 *    function. When you return it, the pointer points to a destroyed
 *    local variable.
 * 4. Commenting out the print statements didn't change anything other
 *    than not show the address of the destroyed stack variable
*/