#include <stdio.h>

int main() {
  int a = 3;
  int b = 4;
  int c = a + b;
  printf("c is %d\n", c);
  return 0;
}

/*
    The optimization didn't seem to do anything; the output was exactly the same
    However, the way it was written in assembly changed the section
    I found the string using the -S flag to look at assembly
    Seems like optimization changes the way that it output the string, but isn't
    very clear to me from the assembly what it is actually doing.
*/
