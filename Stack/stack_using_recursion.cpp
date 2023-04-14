//Sort the Stack using recusion
#include<iostream>
using namespace std;
//defining the stack using linked list
struct stack{
    int data;
    struct stack *next;    
};
//Intitialise the stack
void initiStack(struct stack **s)
{
    *s=NULL;
}
//Checking empty condition
int isempty(struct stack *s)
{
    if(s==NULL)
        return 1;
    return 0;
}
//push the element
void push(struct stack **s,int x)
{
    struct stack *p=(struct stack *)malloc(sizeof(*p));
    if(p==NULL)
    {
        cout<<"\nMEMORY ALLOCATION IS FAILED";
        return;
    }
    p->data=x;
    p->next=(*s);
    (*s)=p;

}
//return the deleted element
int pop(struct stack **s)
{
    int x;
    struct stack *temp;

    x=(*s)->data;
    temp=(*s);
    (*s)=(*s)->next;
    free(temp);

    return x;
}
int top(struct stack *s)
{
    return (s)->data;
}
//Function to sort the stack recursivly
void Sorted_Insert(struct stack **s,int x)
{
    if(isempty(*s) || x > top(*s))
    {
        push(s,x);
        return;
    }
    int temp=pop(s);
    Sorted_Insert(s,x);

    push(s,temp);

}

void Sort_stack(struct stack **s)
{
    if(!isempty(*s))
    {
        int x=pop(s);
        Sort_stack(s);
        Sorted_Insert(s,x);
    }
}

//Print Function
void print(struct stack *s)
{
    while(s)
    {
        cout<<" "<<(s)->data<<" ";
        s=s->next;
    }
    cout<<"\n";
}
int main()
{
    struct stack *st;
    initiStack(&st);
    push(&st,10);
    push(&st,12);
    push(&st,18);
    push(&st,-9);
    push(&st,4);
    push(&st,8);
    push(&st,-2);
    
    cout<<"\nBefore Sorting :: ";
    print(st);

    Sort_stack(&st);

    cout<<"\nAfter Sorting :: ";
    print(st);

    return 0;

}