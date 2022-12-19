#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *s;
};
void Create(struct stack *st)
{
    printf("ENTER THE SIZE == ");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));

}
void display(struct stack *st)
{
    int i;
    printf("\nSTACK ARE == ");
    for(i=st->top;i>=0;i--)
       printf(" %2d ",st->s[i]);
    printf("\n");   

}
void push(struct stack *st,int x)
{
    if(st->top==st->size-1)
       printf("\nSTACK OVERFLOW");
    else
    {
        st->top++;
        st->s[st->top]=x;
    }   
}
int pop(struct stack *st)
{
    int x=-1;
    if(st->top==-1)
       printf("\nSTACK UNDERFLOW.");
    else
    {
        x=st->s[st->top--];
    }
    return x;
}
int is_top(struct stack *st)
{
    if(st->top==-1)
      return -1;
    else
      printf("TOP ELEMENT ARE :: %d",st->s[st->top]);
}



int main()
{
    struct stack *st;
    Create(st);
    int opt,n;
    do
    {
        printf("\n 1.PUSH.");
        printf("\n 2.POP.");
        printf("\n 3.DISPLAY.");
        printf("\n 4.DISPLAY THE TOP ELEMENT.");
        printf("\n 5.EXIT.");
        printf("\nENTER YOUR CHOICE :: ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                printf("ENTER ELEMENT TO INSERT :: ");
                scanf("%d",&n);
                push(st,n);
                break;
            case 2:
                pop(st);
                break;
            case 3:
                display(st);
                break;
            case 4:
                is_top(st);
                break;
            case 5:
                exit(0);
                break;

        }
        
    } while (1);
    

}