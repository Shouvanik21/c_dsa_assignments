#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, data, pos, n;

    // Input linked list from user
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &data);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = head;
        head = newNode; // Insert at the beginning for simplicity
    }

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert After a Position\n");
        printf("4. Insert Before a Position\n");
        printf("5. Delete at Start\n");
        printf("6. Delete at End\n");
        printf("7. Delete After a Position\n");
        printf("8. Delete Before a Position\n");
        printf("9. Display List\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Insert at Start
                printf("Enter data: ");
                scanf("%d", &data);
                {
                    Node* newNode = (Node*)malloc(sizeof(Node));
                    newNode->data = data;
                    newNode->next = head;
                    head = newNode;
                }
                break;

            case 2: // Insert at End
                printf("Enter data: ");
                scanf("%d", &data);
                {
                    Node* newNode = (Node*)malloc(sizeof(Node));
                    newNode->data = data;
                    newNode->next = NULL;
                    if (head == NULL) {
                        head = newNode;
                    } else {
                        Node* temp = head;
                        while (temp->next != NULL) {
                            temp = temp->next;
                        }
                        temp->next = newNode;
                    }
                }
                break;

            case 3: // Insert After a Position                
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                {
                    Node* newNode = (Node*)malloc(sizeof(Node));
                    newNode->data = data;

                    Node* temp = head;
                    for (int i = 1; i < pos && temp != NULL; i++) {
                        temp = temp->next;
                    }
                    if (temp == NULL) {
                        printf("Position does not exist.\n");
                    } else {
                        newNode->next = temp->next;
                        temp->next = newNode;
                    }
                }
                break;

            case 4: // Insert Before a Position
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter data: ");
                scanf("%d", &data);
                {
                    Node* newNode = (Node*)malloc(sizeof(Node));
                    newNode->data = data;

                    if (pos == 1) {
                        newNode->next = head;
                        head = newNode;
                    } else {
                        Node* temp = head;
                        for (int i = 1; i < pos - 1 && temp != NULL; i++) {
                            temp = temp->next;
                        }
                        if (temp == NULL) {
                            printf("Position does not exist.\n");
                        } else {
                            newNode->next = temp->next;
                            temp->next = newNode;
                        }
                    }
                }
                break;

            case 5: // Delete at Start
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                break;

            case 6: // Delete at End
                if (head == NULL) {
                    printf("List is empty.\n");
                } else {
                    if (head->next == NULL) {
                        free(head);
                        head = NULL;
                    } else {
                        Node* temp = head;
                        while (temp->next->next != NULL) {
                            temp = temp->next;
                        }
                        free(temp->next);
                        temp->next = NULL;
                    }
                }
                break;

            case 7: // Delete After a Position                
                printf("Enter position: ");
                scanf("%d", &pos);
                Node* temp = head;
                for (int i = 1; i < pos && temp != NULL; i++) {
                    temp = temp->next;
                }
                if (temp == NULL || temp->next == NULL) {
                    printf("Cannot delete after this position.\n");
                } else {
                    Node* toDelete = temp->next;
                    temp->next = toDelete->next;
                    free(toDelete);
                }
                break;

            case 8: // Delete Before a Position
                printf("Enter position: ");
                scanf("%d", &pos);
                if (pos <= 1 || head == NULL) {
                    printf("Cannot delete before this position.\n");
                } else if (pos == 2) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                } else {
                    Node* temp = head;
                    for (int i = 1; i < pos - 2 && temp->next != NULL; i++) {
                        temp = temp->next;
                    }
                    if (temp->next == NULL) {
                        printf("Position does not exist.\n");
                    } else {
                        Node* toDelete = temp->next;
                        temp->next = toDelete->next;
                        free(toDelete);
                    }
                }
                break;

            case 9: // Display List
                printList(head);
                break;

            case 10: // Exit
                while (head != NULL) {
                    Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}