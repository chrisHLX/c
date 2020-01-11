#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Self referential struct doubly linked list node
typedef struct node
{
    int number;
    struct node* prev;
    struct node* next;
}
node;

// Start of doubly linked list
// node* head = NULL;

//
node* newNode(int x);
node* insertHead(node* head, int x);
node* insertTail(node* head, int x);
void delNode(node* head, int x);

int main(void)
{
    node* list = NULL;
    list = insertHead(list, 87);
    list = insertHead(list, 5);
    list = insertHead(list, 8);
    list = insertHead(list, 90);

    insertTail(list, 99);

    for (node* n = list; n != NULL; n = n->next)
    {
        printf("%p \n", n);
        printf("%i \n", n->number);
    }

    delNode(list, 5);
    printf("%i\n", list->next->prev->number);

    for (node* n = list; n != NULL; n = n->next)
    {
        printf("%p \n", n);
        printf("%i \n", n->number);
    }

    while (list != NULL)
    {
        node* tmp = list->next;
        free(list);
        list = tmp;
        // for some reasong freeing tmp causes a fasttop
        //free(tmp);
    }



}

// Create a new node
node* newNode(int x)
{
    node* n = malloc(sizeof(node));
    if (n == NULL)
    {
        printf("Not enough memory to create a new node\n");
    }

    n->number = x;
    n->prev = NULL;
    n->next= NULL;

    // Return the new node
    return n;
}

// Insert at head
node* insertHead(node* head, int x)
{
    node* n = newNode(x);

    // If head is null return the new node
    if (head == NULL)
    {
        head = n;
        return n;
    }

    // Otherwise set heads prev pointer to the new node
    // Then set the new nodes next pointer to head
    // And finaly set the head to the new node
    head->prev = n;
    n->next = head;
    head = n;
    return n;
}

// Insert at tail
node* insertTail(node* head, int x)
{
    node* n = newNode(x);
    node* last = NULL;

    // Find the last node
    for (node* tmp = head; tmp != NULL; tmp = tmp->next)
    {
        if (tmp->next == NULL)
        {
            // Last node in the list
            last = tmp;
        }
    }

    n->prev = last;
    n->next = NULL;
    last->next = n;

    return n;
    free(last);
}

void delNode(node* head, int x)
{
    node* del = NULL;
    for (node* n = head; n != NULL; n = n->next)
    {
        if (n->number == x)
        {
            // Assign dell to n so we can free it.
            del = n;
            // Last node in the list
            printf("found %i in %p \n", n->number, n);

            node* nPrev = NULL;
            node* nNext = NULL;

            // Find prev node and set temp pointer to it
            if (n->prev != NULL)
            {
                nPrev = n->prev;
                nPrev->next = n->next;
            }
            else
            {
                nPrev = NULL;
            }

            // Find next node and set next pointer to it
            if (n->next != NULL)
            {
                nNext = n->next;
                nNext->prev = n->prev;
            }
            else
            {
                nNext = NULL;
            }

            // Set prev node to current nodes next
            // Set next node prev to current nodes prev
            // TODO FIX SEG FAULT FOR TAIL AND HEAD NODE DELETION


            break;
            free(del);
        }
    }


    free(del);
    printf("deleted\n");
}