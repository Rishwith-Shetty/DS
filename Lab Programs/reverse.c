#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Concatenate two lists
struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    struct Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
    return list1;
}

// Main function with menu
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* finalList = NULL;
    int choice, data;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Concatenate Lists\n");
        printf("4. Display List 1\n");
        printf("5. Display List 2\n");
        printf("6. Display Final Concatenated List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert into List 1: ");
                scanf("%d", &data);
                insertEnd(&list1, data);
                break;
            case 2:
                printf("Enter value to insert into List 2: ");
                scanf("%d", &data);
                insertEnd(&list2, data);
                break;
            case 3:
                finalList = concatenate(list1, list2);
                printf("Lists concatenated.\n");
                break;
            case 4:
                printf("List 1: ");
                printList(list1);
                break;
            case 5:
                printf("List 2: ");
                printList(list2);
                break;
            case 6:
                printf("Final Concatenated List: ");
                printList(finalList);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}
