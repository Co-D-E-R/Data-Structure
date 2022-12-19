#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* lchild;
    struct node* rchild;
    int data;
    int height;
}*root=NULL;
int Nheight(struct node* p)
{
    int hl,hr;
    hl=p && p->lchild ? p->lchild->height:0;
    hr=p&& p->rchild ? p->rchild->height:0;
    return hl>hr?hl+1:hr+1;
}
int balancefac(struct node*p)
{
    int hl,hr;
    hl=p && p->lchild ? p->lchild->height:0;
    hr=p&& p->rchild ? p->rchild->height:0;
    return hl-hr;
}
struct node* llrotation(struct node* p)
{
    struct node* pl=p->lchild;
    struct node* plr=pl->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=Nheight(p);
    pl->height=Nheight(pl);

    if(root==p)
        root=pl;
    return pl;
} 
struct node *lrrotation(struct node*p)
{
    struct node* pl=p->lchild;
    struct node* plr=pl->rchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->rchild=p;
    plr->lchild=pl;
    pl->height=Nheight(pl);
    p->height=Nheight(p);
    plr->height=Nheight(plr);

    if(root==p)
        root=plr;
    return plr;
}

struct node* insert(struct node* p,int key)
{
    struct node* t=NULL;
    if(p==NULL)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=key;
        t->lchild=t->rchild=NULL;
        t->height=1;
        return t;
    }
    if(key<p->data)
        p->lchild=insert(p->lchild,key);
    else if(key>p->data)
        p->rchild=insert(p->rchild,key);
    
    p->height=Nheight(p);
    
    if(balancefac(p)==2 && balancefac(p->lchild)==1)
         return llrotation(p);
    else if(balancefac(p)==2 && balancefac(p->lchild)==-1)
         return lrrotation(p);
    
    return p;
}
void preorder(struct node* p)
{
    if(p)
    {
        printf("%d->",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}
void display(struct node *root)
{
    
    if(root!=NULL)
    {
        printf("%d ",root->data);
        display(root->lchild);
        display(root->rchild);
    }
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
                root=insert(root,x);
                break;
            case 2:
                printf("\npreorder ->");
                preorder(root);
                break;
            // case 3:
            //     printf("\nDATA :: ");
            //     scanf("%d",&key);
            //     temp=search(key);
            //     if(temp!=NULL)
            //     {
            //         printf("\nElement %d Found",temp->data);
            //     }
            //     else{
            //         printf("\nElement not found");
            //     }
            case 3:
                exit(1);
            default:
                printf("\nInvalid Input"); 
        }

    }
    return 0;
}