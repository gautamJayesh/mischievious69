#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to perform linear search in the linked list
struct Node* linearSearch(struct Node* head, int key) {
    struct Node* current = head;

    while (current != NULL) {
        if (current->data == key) {
            return current; // Node with the key found
        }
        current = current->next;
    }

    return NULL; // Key not found
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    // Creating a sample linked list
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    // Printing the original linked list
    printf("Original Linked List: ");
    printList(head);

    // Performing linear search
    int keyToSearch = 3;
    struct Node* result = linearSearch(head, keyToSearch);

    // Displaying the search result
    if (result != NULL) {
        printf("%d found in the linked list.\n", keyToSearch);
    } else {
        printf("%d not found in the linked list.\n", keyToSearch);
    }

    return 0;
}

