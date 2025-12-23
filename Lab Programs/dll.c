#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} NODE;

NODE *head = NULL;

void insert(int value, int pos) {
    if (pos < 2) {
        printf("\nInvalid position");
        return;
    }
    NODE *newNode = (NODE*)malloc(sizeof(NODE));
    newNode->data = value;
    if (pos == 2) {
        newNode->prev = NULL;
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        printf("\nInserted %d at position %d", value, pos);
        return;
    }
    NODE *temp = head;
    for (int i = 1; i < pos - 2 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nInvalid position");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("\nInserted %d at position %d", value, pos - 1);
}

void delete(int value) {
    if (head == NULL) {
        printf("\nEmpty list");
        return;
    }
    NODE *temp = head;
    while (temp != NULL) {
        if (temp->data == value) {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\n%d not found", value);
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    printf("\n%d deleted", value);
    free(temp);
}

void display() {
    if (head == NULL) {
        printf("\nEmpty list");
        return;
    }
    NODE *temp = head;
    printf("\nList:\n");
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, pos;
    printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value : ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &pos);
                insert(value, pos);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.");
        }
    }
    return 0;
}
