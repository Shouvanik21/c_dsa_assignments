#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *top,int value){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=top;
    top=newNode;
    return top;
}

struct Node *pop(struct Node *top,int *pvalue){
    *pvalue=top->data;
    struct Node *temp=top;
    top=top->next;
    free(temp);
    return top;    
}
