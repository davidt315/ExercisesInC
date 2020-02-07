/* Example code for Think OS.

Copyright 2014 Allen Downey
License: GNU GPLv3

*/

#include <stdio.h>
#include <stdlib.h>

int var1;
void print_local(int local);

int main ()
{
    int var2 = 5;
    void *p = malloc(128);
    void *secondp = malloc(200);
    char *s = "Hello, World";

    printf ("Address of main is %p\n", main);
    printf ("Address of var1 is %p\n", &var1);
    // printf ("Address of var2 is %p\n", &var2);
    printf ("p points to %p\n", p);
    printf ("second p points to %p\n", secondp);
    printf ("s points to %p\n", s);
    print_local(var2);

    void *first = malloc(24);
    void *second = malloc(24);

    printf ("first address: %p\n", first);
    printf ("second address: %p\n", second);

    return 0;
}

void print_local(int local){
    printf ("Address of the local variable is %p\n\n", &local);
}

/* Notes
 * 3. Stack > Heap > Global
 *    Stack has var2, all the pointers and globals are located in the heap 
 * 4. Calling malloc() a second time did increase the heap by a little bit
 * 5. Adding a function to priint the address of the local variable actually
 *    made the stack address slightly increase, but it was very small
 * 6. I put two chunks of 24 bytes and there were 32 bytes between them 
*/