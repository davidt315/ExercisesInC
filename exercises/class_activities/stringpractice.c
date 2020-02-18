#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void separate(char *str, char sep, char *first, char *second);

int main() {
    char *first = malloc(20);
    char *second = malloc(20);
    char sep = ' ';
    char *string = "Hello World";

    separate(string, sep, first, second);
    printf("first: %s\n", first);
    printf("second: %s\n", second);
    return 0;
}

void separate(char *str, char sep, char *first, char *second) {
    char first_buffer[strlen(str)];
    char second_buffer[strlen(str)];
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == sep) {
            int j = i;
            while (j < strlen(str)-1) {
                second_buffer[j-i] = str[j+1];
                j++;
            }
            break;
        } else {
            first_buffer[i] = str[i];
            printf("buff: %s\n", first_buffer);
        }
    }
    strcpy(first, first_buffer);
    strcpy(second, second_buffer);
}