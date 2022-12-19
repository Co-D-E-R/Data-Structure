#include<stdio.h>
#include<stdlib.h>
#define size 10
int hash(int key)
{
    return key%size;
}
int probe(int h[],int key)
{
    int index=hash(key);
    int i=0;
    while(h[(index+i)%size]!=0)
           i++;
    return (index+i)%size;
}
int insert(int h[],int key)
{
    int index=hash(key);
    if(h[index]!=0)
    {
        index=probe(h,key);
    }
    h[index]=key;
}
int search(int h[],int key)
{
    int index=hash(key);
    int i=0;
    while(h[(index+i)%size]!=key)
          i++;
    return(index+i)%size;
}
void display(int h[])
{
    int i;
    printf("\nElement in the hash table are:--");
    for(i=0;i<size;i++)
    {
        printf("\n Index :-%d \tValue :-%d",i,h[i]);
    }
}
int main()
{
    int i,ch,key;
    int h[size];
   
    while(1)
    {
        printf("\n1.insert\t2.Display\t3.Search\t4.Exit\n");
        scanf("\n%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter a value to insert into hash table:: ");
                scanf("%d",&key);
                insert(h,key);
                break;
            case 2:
                display(h);
                break;
            case 3:
                printf("\nEnter the value you want to search :: ");
                scanf("%d",&key);
                printf("\nSearching element at index :- %d",search(h,key));
                break; 
            case 4:
                exit(0);
                 
        }

    }
}