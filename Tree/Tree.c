// Create The Tree 
#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node* lchild;
    int data;
    struct node* rchild;
};
struct Queue{ //struct a Queue to store the address of root node;
    int size;
    int front;
    int rear;
    struct node **Q; //pointer to node
};
struct node *root=NULL;
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct node **)malloc(q->size*sizeof(struct node *));
}
void enqueue(struct Queue *q,struct node *x)
{
    if((q->rear+1)%q->size == q->front)
             printf("\nQueue is full");
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct node *dequeue(struct Queue *q)
{
    struct node *x=NULL;
    if(q->front==q->rear)
        printf("\nqueue is empty");
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}
void Createtree() //Creating a tree 
{
    struct node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("\nEnter the data of root Value ::");
    scanf("%d",&x);//root node data
    root = (struct node*)malloc(sizeof(struct node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);//store root address in queue
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("\nEnter the Value Of Left Child %d :: ",p->data);//if left child is there or not
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("\nEnter the Value Of right Child %d :: ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct node*)malloc(sizeof(struct node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void preoder(struct node *p)
{
    if(p)
    {
        printf("%d->",p->data);
        preoder(p->lchild);
        preoder(p->rchild);
    }
}
void inorder(struct node *p)
{
    if(p)
    {
        preoder(p->lchild);
        printf("%d->",p->data);
        preoder(p->rchild);
    }
}
void postorder(struct node *p)
{
    if(p)
    {
        preoder(p->lchild);
        preoder(p->rchild);
        printf("%d->",p->data);
    }
}
int count(struct node *root)
{
    if(root)
    {
        return count(root->lchild)+count(root->rchild)+1;
    }
    return 0;
}
int height(struct node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else 
        return y+1;
}
int main()
{
    int ch;
    while(1)
    {
      printf("\n1.Create\n2.preorder\n3.postorder\n4.inorder\n5.Height\n6.count\n7.exit.");
      printf("\nEnter your choice ::");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
            Createtree();
            break;      
        case 2:
            printf("preorder ::");
            preoder(root);
            break;
        case 3:
            printf("\npostorder ::");
            postorder(root);
            break;
        case 4: 
            printf("\nInorder ::");
            inorder(root);
            break;
        case 5:
            printf("Height :: %d ",height(root));
            break;
        case 6:
            printf("Count :: %d",count(root));
            break;
        case 7:
            exit(1);
        default:
            printf("\nWorng Choice\n");
      }
      
    }
    return 0;
}