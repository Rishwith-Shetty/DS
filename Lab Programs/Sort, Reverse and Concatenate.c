#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

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
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
void sortList(struct Node* head) {
    if (head == NULL) return;
    struct Node* i, *j;
    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL, *curr = head, *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct Node* concatenate(struct Node* list1, struct Node* list2) {
    if (list1 == NULL) return list2;
    struct Node* temp = list1;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = list2;
    return list1;
}
int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* finalList = NULL;
    int choice, data;


        printf("\n--- Linked list ---\n");
        printf("1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Sort list\n");
        printf("4. Reverse list\n");
        printf("5. Concatenate lists\n");
        printf("6. Display List 1\n");
        printf("7. Display List 2\n");
        printf("8. Display Final List\n");
        printf("0. Exit\n");
    do {
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
                sortList(list1);
                sortList(list2);
                printf("                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              lists sorted.\n");
                break;
            case 4:
                list1 = reverseList(list1);
                list2 = reverseList(list2);
                printf("lists reversed.\n");
                break;
            case 5:
                finalList = concatenate(list1, list2);
                printf("Lists concatenated.\n");
                break;
            case 6:
                printf("List 1: ");
                printList(list1);
                break;
            case 7:
                printf("List 2: ");
                printList(list2);
                break;
            case 8:
                printf("Final List: ");
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
