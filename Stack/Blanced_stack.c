//Implementation of checking a balanced parenthesis  of stack
#include<stdio.h>
#include<stdlib.h>
#define size 100
struct node{
    char data;
    struct node *next;
}*top=NULL;

void push(char x)//push operation
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    
    if(t==NULL)
          printf("Stack is full\n");
    else{
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()//pop operation
{
    struct node *t;
    char x=-1;
    if(top == NULL)
         printf("Stack is empty");
    else{
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}
void display()//display 
{
    struct node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int isbalanced(char *exp)
{
    char x;
    int i;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='{' || exp[i]=='[' || exp[i]=='('){//input a opening parenthesis into a stack 
            push(exp[i]);
        }
        else{
            if(exp[i] == '}'|| exp[i]==']'|| exp[i]==')'){//pop out when  parenthesis found
                if(top==NULL)//stack get empty but you have pop out found then it is false
                    return 0;
                x=pop();
                if(x=='{' && exp[i]!='}'){ // checking if  parenthesis is pop out is same or not 
                    return 0;
                }
                if(x=='[' && exp[i]!=']'){
                    return 0;
                }
                if(x=='(' && exp[i]!=')'){
                    return 0;
                }
            }
        }
    }
    if(top == NULL)//if stack get empty the it is balanced
         return 1;
    else
        return 0;
}
int main()
{
    char exp[size];
    printf("\nEnter the expression ::");
    gets(exp);
    if(isbalanced(exp)==1){
        printf("Balanced");
    }
    else{
        printf("Unbalanced");
    }

    return 0;

}
