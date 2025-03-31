#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *arr;
int rear,front;
rear=-1;
front=-1;

int create()
{
    int n;
    printf("ENTER THE NO OF ELEMENTS IN QUEUE\n");
    scanf("%d",&n);
    arr=(int *)malloc(n*sizeof(int));
    return n;
}

bool isempty()
{
    return front==-1;
}
bool isfull(int n)
{
    return rear==n-1;
}

void enqueue(int data,int n)
{
 if(isfull(n))
{
    printf("QUEUE OVERFLOW\n");
    return;
}
if(front==-1 &&rear==-1)
{
    front++;
}
    arr[++rear]=data;
    printf("%d ENTERED IN QUEUE..........\n",data);
}

void dequeue()
{
    if(isempty())
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    if(front>rear)
{
    printf("DEQUEUE NOT POSSIBLE\n");
    return;
}
    int del;
    del=arr[front];
    front++;
    printf("%d DEQUEUED FROM QUEUE\n",del);
}

void display()
{
    if(isempty())
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",arr[i]);
    }
}

void main()
{
    int max=create();
    int choice,item;
    do
    {
        printf("PRESS '1' TO DISPLAY\n");
        printf("PRESS '2' TO ENQUEUE\n");
        printf("PRESS '3' TO DEQUEUE\n");
        printf("PRESS '4' TO EXIT\n");
        printf("ENTER CHOICE\n");      
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            display();
            break;
            case 2:
            printf("ENTER THE NUMBER TO BE STORED:\t");
            scanf("%d",&item);
            enqueue(item,max);
            break;
            case 3:
            dequeue();
            break;
            case 4:
            printf("BYE\n");
            break;
            default:
            printf("WRONG CHOICE PLEASE REENTER\n");
        }
    } while (choice!=4);
    
}