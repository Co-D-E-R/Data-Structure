#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* lchild;
    int data;
    struct node* rchild;
}*root=NULL;

void insert(struct node *t,int x)
{
    struct node *r,*p;
    if(root== NULL)
    {
        p=(struct node*)malloc(sizeof(struct node));
        p->data=x;
        p->lchild=p->rchild=NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(x<t->data)
              t=t->lchild;
        else if(x>t->data)
              t=t->rchild;
        else
            return;
    }
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->lchild=p->rchild=NULL;
    if(x<r->data)
    {
        r->lchild=p;
    }
    else{
        r->rchild=p;
    }
}
void inorder(struct node* p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d->",p->data);
        inorder(p->rchild);
    }
}
struct node * search(int x)
{
    struct node*t=root;
    while(t!=NULL)
    {
        if(x==t->data)
            return t;
        else if(x<t->data)
            t=t->lchild;
        else 
            t=t->rchild;
    }
    return NULL;
}
int main()
{
    int ch,x,key;
    struct node *temp;
    while(1)
    {
        printf("\n1.Insert The Data\n2.Display Inorder\n3.Search the Data\n4.Exit");
        printf("\nEnter Your Choice ::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nDATA ::");
                scanf("%d",&x);
                insert(root,x);
                break;
            case 2:
                printf("\nInorder ->");
                inorder(root);
                break;
            case 3:
                printf("\nDATA :: ");
                scanf("%d",&key);
                temp=search(key);
                if(temp!=NULL)
                {
                    printf("\nElement %d Found",temp->data);
                }
                else{
                    printf("\nElement not found");
                }
            case 4:
                exit(1);
            default:
                printf("\nInvalid Input"); 
        }

    }
    return 0;
}