/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    // FILL THIS IN!
    return 0;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    // gets the first node in the list
    Node *first = *list;
    // make a new node for the first value
    Node *new = make_node(val, first);
    // change the head of list to the new element
    *list = new;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    Node *current = *list;
    Node *last = NULL;
    // loop through the linked list
    while (current != NULL) {
        // found val
        if (current->val == val) {
            // case where the first element is removed
            if (last == NULL) {
                *list = current->next;
            }
            // any other case
            else {
                last->next = current->next;
            }
            // free the memory
            free(current);
            return 1;
        }
        // keep track of the last to update the links
        last = current;
        current = current->next;
    }
    // return 0 if val not found
    return 0;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    Node *current = *list;
    Node *next = current->next;
    Node *temp;
    // make the head's next NULL (tail)
    current->next = NULL;
    // reverse the order
    while (next != NULL) {
        temp = next->next;
        next->next = current;
        current = next;
        next = temp;
    }
    // set head to the tail
    *list = current;
    
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = 0; // pop(list);
    // print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
