#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
int isoperand(char x)
{
    if(x == '+'|| x == '-'|| x == '*'|| x == '/'){
            return 0;
    }
    else{
        return 1;
     }   
}
int pre(char x)
{
    if(x=='+'||x=='-')
        return 1;
    else if(x=='*'||x=='/')
        return 2;
    return 0;
}

 char * intopost(char *in)
 {
    int i=0,j=0;
    long long len=strlen(in);
    char *post;
    post=(char *)malloc((len+2)*sizeof(char));
    while(in[i]!='\0')
    {
        if(isoperand(in[i]))
        {
            post[j++]=in[i++];
        }
        else{
            if(pre(in[i])>pre(top->data))
            {
                push(in[i++]);
            }
            else{
                post[j++]=pop();
            }
        }
    }
    while(top!=NULL)
    {
        post[j++]=pop();

    }
    post[j]='\0';
    return post;
 }      




int main()
{
     int n,i;char *in;
     printf("\nEnter the maximum number of characters in the expression:: ");
     scanf("%d", &n);
     in = (char*)malloc((n+2)*sizeof(char));
     char c=getchar();
     printf("\nEnter The Expression ::");
     scanf("%s",in);
  
    push('#');

    char *post=intopost(in);
    printf("Postflix :: %s",post);
    
    return 0;

}