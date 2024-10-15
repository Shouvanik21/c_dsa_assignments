#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

node*start=NULL;

void push(int val){
    node*ptr=(node*)malloc(sizeof(node));
    ptr->data=val;
    ptr->next=start;
    start=ptr;
}

int pop(){
    int v;
    if(start==NULL){
        printf("stack underflow");
    }
    else{
        node *temp=start;
        v=temp->data;
        start=start->next;
        free(temp);
        return v;
    }
}

int main(){
    while(1){
        int ch,d,num,value;
        printf("\n1.For PUSH");
        printf("\n2.For POP");
        printf("\n3.Display the STACK");
        printf("\n4.EXIT");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("enter the data:");
                scanf("%d",&num);
                push(num);
                break;

            case 2:
                value=pop();
                if(start!=NULL){
                    printf("the popped value is: %d\n",value);
                }
                break;

            case 3:
                printf("the linked list is:");
                node *temp=start;
                while(temp!=NULL){
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("wrong choice input");
                printf("\n");           
        }
    }

    return 0;
}