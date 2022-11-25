//Implementing Queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
void enqueue(struct node** front,struct node** rear)
{
    struct node* temp;
    int value;
    printf("\nEnter the value ::");
    scanf("%d",&value);
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->next=NULL;
    if(((*front)==NULL) && ((*rear)==NULL))
    {
        (*front) = (*rear) = temp;
    }
    else
    {
        (*rear)->next = temp;
        (*rear) = temp;
    }
    printf("NODE IS INSERTED");
}
void dequeue(struct node** front)
{
    struct node* temp;
    if(*front == NULL)
           printf("\nQUEUE IS EMPTY >> UNDERFLOW");
    else
    {
        temp= *front;
        *front=(*front)->next;
        printf("\nELEMENT DELETED -- >%d",temp->data);
        free(temp);
    }
}
void display(struct node** front)
{
    struct node* temp;
    if(*front == NULL)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        temp=*front;
        printf("\nHEAD-->");
        while(temp->next != NULL)
        {
            printf("%d -->",temp->data);
            temp=temp->next;
        }
        printf("%d -->NULL\n",temp->data);
    }
}
void main()
{
    struct node* f=NULL,*r=NULL;
    int ch;
    do
    {
       printf("\n\t!!!!MENU!!!!\t\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n5.ENTER YOUR CHOICE ::");
       scanf("%d",&ch);
       switch(ch)
       {
            case 1:
               enqueue(&f,&r);
               break;
            case 2:
               dequeue(&f);
               break;
            case 3:
               display(&f);
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