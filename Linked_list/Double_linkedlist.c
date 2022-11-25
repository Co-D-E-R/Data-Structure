#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* pre;
    int data;
    struct node* next;
};
void insert(struct node **head)//Insert the element index 0-any index in serial. 
{
    int pos,x,i;
    struct node *newnode,*p;
    printf("\nEnter the position you want to enter the node ::");
    scanf("%d",&pos);
    printf("\nEnter the element :: ");
    scanf("%d",&x);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    if((*head)==NULL){
        (*head)=newnode;
        newnode->pre=NULL;
        newnode->next=NULL;
    }
    else if(pos == 0){
        newnode->pre=NULL;
        newnode->next=(*head);
        (*head)->pre=newnode;
        (*head)=newnode;
    }
    else{
        p=(*head);
        for(i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        newnode->pre=p;
        newnode->next=p->next;
        if(p->next)
            p->next->pre=newnode;
        p->next=newnode;
    }
}
void delete(struct node **head)
{
    int i,x=-1,pos;
    struct node *p;
    printf("Enter the position to delete ::");
    scanf("%d",&pos);
    if(pos==1)
    {
        p=(*head);
        (*head)=(*head)->next;
        if((*head)){
            (*head)->pre=NULL;
        }
        x=p->data;
        free(p);
    }
    else{
        p=(*head);
        {
            for(i=0;i<pos-1;i++){
                p=p->next;
            }
            p->pre->next=p->next;
            if(p->next){
                p->next->pre=p->pre;
            }
            x=p->data;
            free(p);
        }
    }
    printf("ELEMENT DELETED IS :: %d",x);
}
void display(struct node **head)
{
    struct node *p;
    p=(*head);
    if(p==NULL){
        printf("LIST IS EMPTY ::");
    }
    else{
        printf("head->");
        while(p!=NULL){
            printf("%d->",p->data);
            p=p->next;
        }
        printf("NULL");
    }
}
struct node *reverse(struct node **head)
{   
    if((*head)==NULL)
         return NULL;
            
    struct node *q=(*head)->next;
    (*head)->next=(*head)->pre;
    (*head)->pre=q;
    if((*head)->pre == NULL)
         return (*head);
    
    return reverse(&(*head)->pre);
    
}
void main()
{
    struct node* h=NULL;
    int ch;
    do
    {
        printf("\n!!!!!!\t\tMENU\t\t!!!!!!\n");
        printf("\n1.Insert.\n2.DISPLAY \n3.DELETE ELEMENT\n4.REVERSE\n5.EXIT\n");
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
                h=reverse(&h);
                printf("\nList Reversed");
                break;
            case 5:
                printf("PROGRAM IS ENDED");
                exit(0);
                break;
            default:
				printf("\nInvalid choice");
        }
        
    } while (ch!=5);
    
}