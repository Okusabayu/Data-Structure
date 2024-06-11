/* Create by Oksa Bayu Widrian
    23343080 Padang State University */
// A linked list node
#include <stdio.h>
struct Node {
    int data;           // Data stored in the node
    struct Node* next;  // Pointer to the next node
    struct Node* prev;  // Pointer to the previous node
};

// Function to insert a new node with given data at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Set data for the new node
    new_node->data = new_data;
    // Set next of new node to the current head
    new_node->next = (*head_ref);
    // Set previous of new node to NULL as it will be the new head
    new_node->prev = NULL;
    // If the current head is not NULL, set the previous of current head to the new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    // Move the head pointer to the new node
    (*head_ref) = new_node;
}

/* Given a node as next_node, insert a new node before the given node */
void insertBefore(struct Node** head_ref, struct Node* next_node, int new_data) {
    // Check if the given next_node is NULL
    if (next_node == NULL) {
        printf("the given next node cannot be NULL");
        return;
    }
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Set data for the new node
    new_node->data = new_data;
    // Set previous of new node as previous of next_node
    new_node->prev = next_node->prev;
    // Set the previous of next_node to the new node
    next_node->prev = new_node;
    // Set next_node as the next of the new node
    new_node->next = next_node;
    // If the previous of new_node is NULL, it will be the new head
    if (new_node->prev != NULL)
        new_node->prev->next = new_node;
    else
        (*head_ref) = new_node;
}

// Function to print the linked list in both forward and reverse directions
void printList(struct Node* node) {
    struct Node* last;
    // Print the list in forward direction
    printf("\nTraversal in forward direction:\n");
    while (node != NULL) {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
    // Print the list in reverse direction
    printf("\nTraversal in reverse direction:\n");
    while (last != NULL) {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

// Main function to test the above functions
int main() {
    // Start with an empty list
    struct Node* head = NULL;
    // Insert elements into the list
    push(&head, 7);
    push(&head, 1);
    push(&head, 4);
    // Insert a new node before the second node
    insertBefore(&head, head->next, 8);
    // Print the created doubly linked list
    printf("Created DLL is:");
    printList(head);
    getchar();  // Wait for a key press before exiting
    return 0;
}


