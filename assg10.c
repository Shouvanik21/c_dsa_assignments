#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node *next;
};
struct node *ptr,*stack,*top=NULL;

int val,k;
void push(char val)
{
    	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	ptr->next=top;
	top=ptr;
}

int pop()
{
 	ptr=top;
 	val=ptr->data;
 	top=ptr->next;
 	free(ptr);
 	return val;
}

int precedence(char x)
{
 	switch(x)
	{
	
 	case '^':return(3);break;
 	case '/':
 	case '*':
 	case '%':return(2);break;
 	case '+':
 	case '-':return(1);break;
 	default: return 0;
    }
}

int main()
{
 	char infix[20],postfix[20];
 	printf("Enter infix expression: ");
 	gets(infix);
 	int i=0,j=0;
 	while(infix[i]!='\0')
 	{ 
 	  switch(infix[i])
 	  {
 	  
 		case '(':
 			push(infix[i]);
 			break;
 		case ')':
 			while(top->data!='(')
 			{
 				postfix[j]=pop();
 				j++;
 			}
 			pop();
 			break;
 		case '^':
 	    case '/':
 	    case '*':
 	    case '%':
 	    case '+':
 	    case '-':
 	    	if(top!=NULL)
 	    	while(precedence(top->data)>=precedence(infix[i]))
 	    	{
 	    		postfix[j++]=pop();
 	    	}
 	    	push(infix[i]);
 	    	break;
 	    default:
 	    		postfix[j++]=infix[i];
 	    		break;
 	    }
 	    i++;
 	}
 	while(top!=NULL)
 		postfix[j++]=pop();
 	postfix[j]='\0';
 	puts(postfix);
}
