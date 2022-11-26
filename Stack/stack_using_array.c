#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *s;
};
void create(struct stack *st)
{
    printf("\nEnter the Size of Array::");
    scanf("%d",&st->size);
    st->top=-1;
    st->s=(int *)malloc(st->size*sizeof(int));
}
void push(struct stack *st)
{
    int x;
    printf("\nEnter the element::");
    scanf("%d",&x);
    if(st->top==st->size-1)
    {
        printf("\nStack is overflow ::");
    }
    st->top++;
    st->s[st->top]=x;
}
void pop(struct stack *st)
{
    int x;
    if(st->top==-1)
    {
        printf("\nstack is underflow");
    }
    x=st->s[st->top];
    printf("\nDeleted Element :: %d",x);
    st->top--;
}
void display(struct stack *st)
{
    int i;
    if(st->top==-1)
    {
        printf("\nStack is underflow");
    }
    printf("Stack->");
    for(i=st->top;i>=0;i--)
    {
        printf("%d->",st->s[i]);
    }
    printf("Last\n\n");

}
void main()
{
    struct stack st;
    int n,choice;
    create(&st);
    do
    {
        printf("\n1. push\n");
        printf("2. pop\n");
        printf("3. display\n");
        printf("4. exit\n\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&st);
            break;
        case 2:
            pop(&st);
            break;
        case 3:
            display(&st);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid input\n");
        }
    } while (choice != 4);
}