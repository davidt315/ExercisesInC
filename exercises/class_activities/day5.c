#include <stdio.h>
#include <stdlib.h>

int operate(int x, int y, char operator, int *result);

int main() {
    int result = 0;
    int check = operate(3, 4, '*', &result);
    if (check == -1){
        printf("Error occurred in operate\n");
    }
    else {
        printf("result = %d\n", result);
    }

    return 0;
}

int operate(int x, int y, char operator, int *result) {
    if (operator == '+') {
        *result = x + y;
        return 0;
    }
    else if (operator == '*') {
        *result = x * y;
        return 0;
    }
    return -1;
}