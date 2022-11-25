#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insert(struct node **head)
{
    int x,i,pos;
    struct node *newnode,*p;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter the position to enter :: ");
    scanf("%d",&pos);
    printf("Enter the Element ::");
    scanf("%d",&x);   
    newnode->data=x; 
    if(pos==0)
    {
        if((*head)==NULL)
        {
            *head=newnode;
            (*head)->next=(*head);
        }
        else{
            p=(*head);
            while(p->next!=(*head))
                 p=p->next;
            p->next=newnode;
            newnode->next=(*head);
            *head=newnode;
        }
    }
    else{
        p=(*head);
        for(i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        newnode->next= p->next;
        p->next=newnode;
    }

}

void display(struct node **head)
{
    struct node* pre;
    pre=*head;
    if(pre == NULL)
    {
        printf("\nLIST IS EMPTY");
    }
    else
    {
        printf("HEAD ->");
       do
        {
            printf("%d ->",pre->data);
            pre=pre->next;
        } while(pre!=(*head));
        printf("NULL");
    }
}
void delete(struct node **head)
{
    int i,pos,x;
    struct node *p,*q;
    printf("Enter the position to delete element ::");
    scanf("%d",&pos);
    if(pos==1)
    {
        p=(*head);
        while(p->next!=(*head)){
            p=p->next;
        }
        x=(*head)->data;
        if((*head)==NULL)
        {
            free(*head);
            *head=NULL;
        }
        else{
            p->next=(*head)->next;
            free(*head);
            (*head)=p->next;
        }
    }
    else{
        p=(*head);
        for(int i=0;i<pos-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    printf("\nDELETED ELEMENT :: ",x);

}

void main()
{
    struct node* h=NULL;
    int ch;
    do
    {
        printf("\n!!!!!!\t\tMENU\t\t!!!!!!\n");
        printf("\n1.Insert At First.\n2.DISPLAY \n3.DELETE ELEMENT\n4.EXIT\n");
        printf("ENTER YOUR CHOICE ::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert(&h);
                break;
            case 2:
                display(&h);
                break;
            case 3:
                delete(&h);
                break;
            case 4:
                printf("PROGRAM IS ENDED");
                exit(0);
                break;
            default:
				printf("\nInvalid choice");
        }
        
    } while (ch!=4);
    
}