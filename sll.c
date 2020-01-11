#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Singly linked list
// Self referencial data type

// Formal name of struct node
typedef struct node
{
    int number;

    // Pointer to next node
    struct node *nxt_ptr;
}
// Nickname of struck
node;

node* create(int x);
bool search(node*, int x);

int main(void)
{
    // Create a list of nodes
    node *list = NULL;

    // list now points to n
    list = create(5);

    list->nxt_ptr = create(7);
    list->nxt_ptr->nxt_ptr = create(9);


    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->nxt_ptr)
    {
        printf("%i\n", tmp->number);
    }

    if (search(list, 5))
    {
        printf("found %i\n", 5);
    }
    // Free list
    while (list != NULL)
    {
        printf("freeing %i\n", list->number);

        // Create tmp list to store the address of the next pointer
        node *tmp = list->nxt_ptr;
        free(list);
        list = tmp;
    }

}

// Creating a new node
node* create(int x)
{
    // Temp var n
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("something went wrong\n");
        return NULL;
    }
    else
    {
        // Arrow means go to number in address of n. Equivelant to (*n).number
        n->number = x;
        n->nxt_ptr = NULL;
    }
    return n;
    free(n);
}


// Returns true if the int exists in the node
bool search(node* n, int x)
{
    for (node *tmp = n; tmp->nxt_ptr != NULL; tmp = tmp->nxt_ptr)
    {
        if (tmp->number == x)
        {
            return true;
            free(tmp);
            break;
        }
    }
    return false;
}

