/* David Tarazi
 * adder.c
 * Description: Continuously takes inputs from the user until they enter "Ctrl-D"
 * where the program sums all the inputs and returns the output
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Booleans
#define True 1
#define False 0

int get_sum(int nums[], int count);
int digits_only(char *str);


int main()
{
    // length of the array and actual array
    int arr_length = 20;
    int input_length = 11;
    int array[arr_length]; // int
    
    // counter for the number of elements to index and check limit for error handling
    int count = 0;
    // input buffer
    char input[input_length];

    printf("Enter up to %d integers of up to %d digits to be summed.\n", arr_length, input_length);
    printf("To stop inputting values, enter 'Ctrl-D'\n");

    while (fgets(input, input_length, stdin) != NULL) {
        // Collects data until it is broken or there is an error
        // If the number of inputs exceeds the length of the array 
        if (count >= arr_length) {
            printf("Error: Maximum Integer Input (%d) Reached\n", arr_length);
            break;
        }

        // checks if the input is all digits
        if (strlen(input) == 0 || digits_only(input) == False) { 
            printf("This is an empty or invalid integer value, try again.\n");
        }
        else {
            // fill array and update index
            array[count] = atoi(input);
            count += 1;
        }
        printf("Enter another integer with less than %d digits. You have up to %d more integers to input\n", input_length, arr_length-count);
        printf("To stop inputting values, enter 'Ctrl-D'\n");
    }
    // after collecting data, traverse and sum the array using get_sum
    printf("Finished inputting data\n");
    printf("The sum of the digits you entered is %i\n", get_sum(array, count));

    return 0;
}


int get_sum(int nums[], int count) {
    // traverses the array and finds the sum
    // takes in the array and how many times data was collected
    int sum = 0;
    for (int i = 0; i < count; i++) { 
        sum += nums[i];
    }
    return sum;
}

int digits_only(char *str) { 
    // checks if the string is all digits and valid
    int i = 0;
    // loop through string until you reach end; if any char isn't a digit return False
    while (str[i] != '\0') {
        // printf('%s',*str);
        if (*str < '0' || *str > '9') {
            return False;
        }
        i += 1;
    }
    // if successfully made it through, return True
    return True;
}
