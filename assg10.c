#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    char data;
    struct node *next;
};
struct node *ptr,*stack,*top=NULL;

int val,k;
void push(char val){
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=val;
    ptr->next=top;
    top=ptr;
}

int pop(){
    ptr=top;
    val=ptr->data;
    top=ptr->next;
    free(ptr);
    return val;
}

int precedence(char x){
    switch(x){
        case '^':
            return (3);
            break;

        case '/':
            return (2);
            break;

        case '*':
            return (2);
            break;

        case '+':
            return (1);
            break;

        case '-':
            return (1);
            break;

        default:
            return 0;  
    }
}
