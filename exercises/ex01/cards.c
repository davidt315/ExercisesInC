/* David Tarazi - Exercise 1
   
   Works with card counting problem from page 37 of Head First C
   First commented out chunk is original solution, then my broken down solution

*/

#include <stdio.h>
#include <stdlib.h>

/*
int main()
{
    char card_name[3];
    int count = 0;
    do{
        puts("enter the card name: ");
        scanf("%2s", card_name);
        int val = 0;
        switch(card_name[0]){
            case 'K':
            case 'Q':
            case 'J': val = 10; break;
            case 'A': val = 11; break;
            case 'X': continue;
            default:
                val = atoi(card_name);
                if ((val < 1) || (val > 10)){
                    puts("I don't understand that value!");
                    continue;
                }
        }
        if ((val > 2) && (val < 7)){
            count++;
        }
        else if (val == 10){
            count--;
        }
        printf("Current count: %i\n", count);
    } while (card_name[0] != "X");
    return 0;
}
*/



void get_val(char * name, int * val);
char * get_input();
void update_count(int * count, int * val);

int main()
{
    int count = 0; 
    while (1) {
        char * card_name = get_input();
        int val = 0;

        /* Breaks if input is 'X' */
        if (card_name[0] == 'X'){
            break;
        } 
        else 
        {
            /* updates value with card_name */
            get_val(card_name, &val);
            /* checks the value to make sure it's understood and prompts for another input if not */
            if ((val < 2) || (val > 11))
            {
                puts("I don't understand that value!");
                continue;
            }
        }
    /* updates and prints the count */
    update_count(&count, &val);
    printf("Current count: %i\n", count);
    }
    return 0;
}


char * get_input() 
{
    /* Prompts the user for input and returns the reply.

       User input is truncated to the first two characters.

       card_name: buffer where result is stored and then returned
    */

    static char card_name[3];
    puts("enter the card name: ");
    scanf("%2s", card_name);
    return card_name;
}

void get_val(char * name, int * val)
{
    /* Converts the string holding the user input into a value

       name: buffer taking in the user input
       val: overwritten int variable storing the value of the input
    */
    switch(name[0]){
            case 'K':
            case 'Q':
            case 'J': *val = 10; break;
            case 'A': *val = 11; break;
            default:
                *val = atoi(name);
        }
}

void update_count(int * count, int * val)
{
    /* Updates the count given current count and current value input
       
       Count increases by 1 if val is between 2 and 7 exclusive.
       Count decreses by 1 if val is 10.

       count: buffer where accumulating count is stored
       val: current value to update the count
    */
    if ((*val > 2) && (*val < 7))
    {
        *count = *count + 1;
    }
    else if (*val == 10)
    {
        *count = *count - 1;
    }
}


/* Running with optimization
   
   $ gcc -ansi -pedantic -Wall cards.c

   * caused code to break due to // style commenting
   * -ansi enables the support of ISO C89 programs
   * -pedantic causes non-ansi programs to be rejected
   * -Wall enables all warnings
*/

/*

*/