#include<stdio.h>
#include <stdlib.h>
int n,visited[10];
struct Node
{
 int data;
 struct Node *next;
 
}*front=NULL,*rear=NULL;
void enqueue(int x)
{
  struct Node *t;
  t=(struct Node*)malloc(sizeof(struct Node));
  if(t==NULL)
  printf("Queue is FUll\n");
  else
  {
    t->data=x;
    t->next=NULL;
   if(front==NULL)
      front=rear=t;
  else
  {
     rear->next=t;
     rear=t;
  }
 }
 
}
int dequeue()
{
   int x=-1;
   struct Node* t;
 
   if(front==NULL)
       printf("Queue is Empty\n");
   else
   {
      x=front->data;
      t=front;
      front=front->next;
      free(t);
    }
   return x;
}
int isEmpty()
{
     return front==NULL;
}
void BFS(int G[][n],int start,int n)
{
    int i=start,j;
    // int visited[n]={0};
    
 
    printf("%d ",i);
    visited[i]=1;
    enqueue(i);
 
    while(!isEmpty())
    {
       i=dequeue();
       for(j=1;j<n;j++)
       {
            if(G[i][j]==1 && visited[j]==0)
            {
               printf("%d ",j);
               visited[j]=1;
                enqueue(j);
            }
        }
    }
 
 
}

int main()
{
    int v,n,i,j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        // queue[i] = 0;
        visited[i] = 0;
    }
    int G[n][n];
    printf("Enter graph data in matrix form:    \n");
    for (i = 0; i <n; i++)
        for (j = 0; j <n; j++)
            scanf("%d", &G[i][j]);
    printf("Enter the starting vertex: ");
    scanf("%d", &v);
    // BFS(G,v,n);
    // printf("The node which are reachable are:    \n");
    // for (i = 1; i <= n; i++)
    //     if (visited[i])
    //         printf("%d\t", i);
    //     else
    //         printf("BFS is not possible. Not all nodes are reachable");
    
//  int G[7][7]={
// 0 0 0 0 0 0 0 
// 0 0 1 1 0 0 0 
// 0 1 0 0 1 0 0 
// 0 1 0 0 1 0 0 
// 0 0 1 1 0 1 1 
// 0 0 0 0 1 0 0 
// 0 0 0 0 1 0 0
    BFS(G,v,n);
  return 0;
}
 
//  0 1 1 1 0
//  1 0 1 0 0 
//  1 1 0 1 1 
//  1 0 1 0 1 
//  0 0 1 1 0