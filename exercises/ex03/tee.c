/*
 * David Tarazi
 * Implementing the 'tee' linux operation in C
 * Exercise 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

#define buffer_size 512

// default not appending, just writing
int append_mode = 0;

int main(int argc, char *argv[]) {
    // takes in the command line arguments and passes them to parse, then tees
    // read character by character and place from one file to the next
    // call parses the arguments and checks for error or changes to append mode
    

    // ******************* GET OPTIONS ************************
    // changes to append mode if '-a' is inserted as an option and stores the filename
    char opt;
    // look through all the arguments and only recognize -a
    while((opt = getopt(argc, argv, "a")) != -1) {
        // parse through the command line and store the arguments in opt as they come
        switch (opt) {
            // in the case of -a, change to append mode
            case 'a':
                append_mode = 1;
                break;
            // getopt returns '?' when unknown option entered and error handle here
            case '?':
                printf("Usage: %s |-a| filename data_to_write\n", argv[0]);
                return 1;
        }
	}
    // if append_mode is 1, made the file_mode = "a", else: file_mode = "w"
    char *file_mode = (append_mode ? "a" : "w");

    // ************* GET FILENAME AND WRITE DATA *************
    char buffer[buffer_size];
    // aligns argc and argv to non-option values
    argc-= optind;
    argv+= optind;
    // optind selects the first non-argument input to the command line
    // only assign the filename if there is one that actually exists
    if (argc > 1) {
        // writes to stdout and file
        while (fgets(buffer, buffer_size, stdin)){
            for (int i = 0; i<argc; i++){
                FILE *f_to_write = fopen(argv[i], file_mode);
                // if unable to open the file:
                if (f_to_write == NULL) {
                    printf("Unable to open this file!\n");
                    printf("Usage: %s |-a| filename data_to_write\n", argv[0]);
                    return 1;
                }
                else {
                    fputs(buffer, stdout);
                    fputs(buffer, f_to_write);
                }
                fclose(f_to_write);
            }
        }
    }
    // if there wasn't enough inputs, throw error
    else {
        // prints how to use the program
        printf("Usage: %s |-a| filename data_to_write\n", argv[0]);
        return 1;
    }
    
    return 0;
}