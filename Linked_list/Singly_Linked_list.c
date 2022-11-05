#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
//Insert_1=AT FIRST
//Insert_2=AT LAST
//Insert_3=RANDOM
//NEW NODE = N
void Insert_1(struct node **head)
{
    struct node *Newnode=(struct node*)malloc(sizeof(struct node));
    int Newdata;
    printf("Enter the data ::");
    scanf("%d",&Newdata);
    Newnode->data=Newdata;
    Newnode->next=*head;
    *head=Newnode;
    printf("!!!NODE INSERTED!!!");
}
void Insert_2(struct node **head)
{
    struct node*Newnode ,*pre;
    Newnode=(struct node*)malloc(sizeof(struct node));
    int D;
    printf("Enter The data ::");
    scanf("%d",&D);
    Newnode->data=D;
    if(*head==NULL)
    {
        Newnode->next=NULL;
        *head==Newnode;
        printf("\nNode inserted");
    }
    else
    {
        pre = *head;
        while(pre->next!=NULL)
        {
            pre=pre->next;
        }
        Newnode->next=pre->next;
        pre->next=Newnode;
        printf("\nNode inserted");

    }

}
void Insert_3(struct node **head)
{
    struct node*Newnode,*pre;
    Newnode=(struct node*)malloc(sizeof(struct node));
    int D,pos,i;
    printf("Enter The Data ::");
    scanf("%d",&D);
    printf("Enter The Location you want to Enter ::");
    scanf("%d",&pos);
    if(pos==0)
    {
        Newnode->data=D;
        Newnode->next=*head;
        *head=Newnode;
        printf("\nNode inserted");
    }
    else if(pos>0)
    {
        pre=*head;
        for(i=0;i<pos-1;i++)
        {
            pre=pre->next;
        }
        Newnode->data=D;
        Newnode->next=pre->next;
        pre->next=Newnode;
        printf("\nNode inserted");
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
        while(pre!=NULL)
        {
            printf("%d ->",pre->data);
            pre=pre->next;
        }
        printf("NULL");
    }
}
void delete_1(struct node **head)//delete from first
{
    int x=-1,pos,i;
    struct node *pre,*de;//Here we need two pointer one for modifing(de) and another for delete form heap(pre) both are pointer
    printf("\nEnter The Index You Want To Delete ::");
    scanf("%d",&pos);
    pre=*head;
    de=NULL;
    if(pos==1)
    {
       *head=(*head) -> next;
       x=pre->data;
       printf("NODE DELETED:- %d",x);
       free(pre);
    }
    else
    {
        for(i=0;i<pos-1 && pre;i++)
        {
            de=pre;
            pre=pre->next;
        }
        if(pre)
        {
            de->next=pre->next;
            x=pre->data;
            printf("NODE DELETED:- %d",x);
            free(pre);

        }

    }

}
void reverse(struct node **head)//Reverse using sliding pointer we need three pointer lets name it as r,q,p;
{
    struct node *r,*q,*p;
    p=(*head);
    q=NULL;
    r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *head=q;
}  
void recursive_reverse(struct node **head,struct node*q,struct node*p )//While using a recursive function in this case argument pass by q is NULL 
{                                                                   //in head (&h) and in p h(head pointer in main);
    if(p!=NULL)
    {
        recursive_reverse(head,p,p->next);
        p->next=q;  //while returning it will change the links
    }
    else
    {
        *head=q;
    }

}
void sorted_list(struct node **head)
{
    struct node* ptr;
    ptr=(*head);
    int i,j,temp,size=0;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        size++;
    }
    ptr=(*head);
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            if(ptr->data > ptr->next->data)
            {
                temp=ptr->data;
                ptr->data=ptr->next->data;
                ptr->next->data=temp;
            }
            ptr=ptr->next;
        }
        ptr=(*head);
    }
    printf(" :: LIST IS SORTED :: ");
}


void main()
{
    struct node* h=NULL;
    int ch;
    do
    {
        printf("\n!!!!!!\t\tMENU\t\t!!!!!!\n");
        printf("\n1.Insert At First.\n2.Insert At Last \n3.Insert At Any Location\n4.Display\n5.Delete\n6.REVERSE THE LIST\n7.RECURSIVE REVERSE\n8.Sorted List\n9.Exit\n");
        printf("ENTER YOUR CHOICE ::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                Insert_1(&h);
                break;
            case 2:
                Insert_2(&h);
                break;
            case 3:
                Insert_3(&h);
                break;
            case 4:
                display(&h);
                break;
            case 5:
                delete_1(&h);
				break;
            case 6:
                reverse(&h);
				break;
            case 7:
                recursive_reverse(&h,NULL,h);
                break;
            case 8:
                sorted_list(&h);
                break;
            case 9:
                printf("PROGRAM IS ENDED");
                exit(0);
                break;
            default:
				printf("\nInvalid choice");
        }
        
    } while (ch!=9);
    
}