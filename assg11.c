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

int evaluate(char *exp){
    struct Node *stack=NULL;
    for(int i=0;exp[i]!='\0';i++){
        if(isdigit(exp[i])){
            stack=push(stack,exp[i]-'0');
        }
        else{
            int op1,op2;
            stack=pop(stack,&op2);
            stack=pop(stack,&op1);
            switch(exp[i]){
                case '+':
                    stack=push(stack,op1+op2);
                    break;
                case '-':
                    stack=push(stack,op1-op2);
                    break;
                case '*':
                    stack=push(stack,op1*op2);
                    break;
                case '/':
                    stack=push(stack,op1/op2);
                    break;
                case '%':
                    stack=push(stack,op1%op2);
                    break;
                case '^':
                    stack=push(stack,op1^op2);
                    break;
                default:
                    printf("Invalid Operation: %c\n",exp[i]);
                    return -1;                        
            }
        }
    }
    int res;
    stack=pop(stack,&res);
    return res;
}
