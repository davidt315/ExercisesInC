/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
// Prints track number and title for every match
void find_track_regex(char pattern[])
{
    regex_t rex;
    int return_value;
    // compiles with the given pattern to check in the future
    return_value = regcomp(&rex, pattern, 0);
    // compilation error from input pattern
    if (return_value) {
        printf("A compilation error occured :(\n");
        exit(1);
    }
    // loops through the songs and checks for matches while printing as matches are found
    for (int i = 0; i < NUM_TRACKS; i++){
        return_value = regexec(&rex, tracks[i], 0, NULL, 0);
        // If a match is found:
        if (return_value == 0) {
           printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
    // free the memory allocated for the pattern finding
    regfree(&rex);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    // find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
