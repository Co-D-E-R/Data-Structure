#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
void push(struct node **top)
{
    struct node*Newnode;
    Newnode=(struct node*)malloc(sizeof(struct node));
    int Newdata;
    printf("Enter The Value :: ");
    scanf("%d",&Newdata);
    Newnode->data=Newdata;
    if(*top ==NULL)
        Newnode->next=NULL;
    else
        Newnode->next=*top;
    *top=Newnode;
    printf("ELEMENT IS INSERTED");
}
void pop(struct node **top)
{
    struct node* ptr;
    if(*top == NULL)
          printf("\nUNDER FLOW. Stack is empty");
    else
          ptr=*top;
          printf("DELETED ELEMENT :-%d",ptr->data);
          *top=ptr->next;
          free(ptr);
}
void display(struct node** top)
{
    if(*top==NULL)
         printf("Stack is empty");
    else{
        struct node* ptr = *top;
        printf("\nSTACK DATA-->");
        while(ptr->next!=NULL)
        {
            printf("%d-->",ptr->data);
            ptr=ptr->next;
        }
        printf("%d-->NULL",ptr->data);
    }
}
void main()
{
    struct node* t=NULL;
    int ch;
    do
    {
       printf("\n\t!!!!MENU!!!!\t\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n5.ENTER YOUR CHOICE ::");
       scanf("%d",&ch);
       switch(ch)
       {
            case 1:
               push(&t);
               break;
            case 2:
               pop(&t);
               break;
            case 3:
               display(&t);
               break;
            case 4:
                printf("\nPROGRAM IS ENDED");
                exit(0);
                break;
            default:
                printf("INVALID NUMBER");


       }
   }while(ch!=4);
}