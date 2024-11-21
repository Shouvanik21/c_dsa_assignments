#include <stdio.h>
#include <stdlib.h>

//node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL; //start of the list

//Function
void create_list(){
    int n;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    printf("enter the elements: \n");
    struct Node *ptr;
    for(int i=0;i<n;i++){
        ptr=(Node *)malloc(sizeof(Node));
        scanf("%d",&ptr->data);
        ptr->next=head;
        ptr->prev=NULL;
        if(head!=NULL)
            head->prev=ptr;
        head=ptr;
    }
}
void insertAtBeginning(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    printf("Node inserted at the beginning.\n");
}

void insertAtEnd(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        printf("Node inserted at the end.\n");
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node inserted at the end.\n");
}

void insertAfterValue(int value, int data) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Node inserted after %d.\n", value);
}

void insertBeforeValue(int value, int data) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = temp->prev;
    newNode->next = temp;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    printf("Node inserted before %d.\n", value);
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("Node deleted at the beginning.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    printf("Node deleted at the end.\n");
}

void deleteAfterValue(int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Value not found or no node after the given value.\n");
        return;
    }

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }
    free(nodeToDelete);
    printf("Node deleted after %d.\n", value);
}

void deleteBeforeValue(int value) {
    Node* temp = head;
    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL || temp->prev == NULL) {
        printf("Value not found or no node before the given value.\n");
        return;
    }

    Node* nodeToDelete = temp->prev;
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = temp;
    } else {
        head = temp;
    }
    temp->prev = nodeToDelete->prev;
    free(nodeToDelete);
    printf("Node deleted before %d.\n", value);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
