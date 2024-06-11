/* Create by Oksa Bayu Widrian
    23343080 Padang State University */
#include <stdio.h>
#include <stdlib.h>

// Structure of the node
struct Node
{
    int data;
    struct Node *next; // Pointer to next node
    struct Node *prev; // Pointer to previous node
};

// Function to add a node at the beginning of the list
void push(struct Node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for the new node

    /* 2. put in the data */
    new_node->data = new_data; // Set the data of the new node

    /* 3. Make next of new node as head and previous as NULL */
    new_node->next = (*head_ref); // Set the next of the new node to the current head of the list
    new_node->prev = NULL; // Set the previous of the new node to NULL

    /* 4. change prev of head node to new node */
    if ((*head_ref) != NULL) // If the list is not empty
        (*head_ref)->prev = new_node; // Set the previous of the current head to the new node

    /* 5. move the head to point to the new node */
    (*head_ref) = new_node; // Set the head of the list to the new node
}

// Function to print the doubly linked list
void printList(struct Node* node)
{
    struct Node* last;

    printf("\nTraversal in forward direction \n");
    while (node != NULL) {
        printf(" %d ", node->data); // Print the data of the current node
        last = node; // Store the current node as the last visited node
        node = node->next; // Move to the next node
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL) {
        printf(" %d ", last->data); // Print the data of the current node in reverse order
        last = last->prev; // Move to the previous node
    }
}

// Main function
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    // Add nodes to the beginning of the list
    push(&head, 6);
    push(&head, 5);
    push(&head, 2);

    printf("Created DLL is: ");
    printList(head); // Print the doubly linked list

    getchar();
    return 0;
}

