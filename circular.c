#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *arr;
int rear,front;
int create()
{
    rear=-1;
    front=-1;
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
void enqueue(int data,int n)
{
    if((rear+1)%n==front)
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    if(front==-1)
    {
        front++;
        rear++;
    }
    else{
    rear=(rear+1)%n;
    }
    arr[rear]=data;
    printf("%d ENTERED IN QUEUE.......\n",data);
}

void dequeue(int n)
{
    int del;
 if(isempty())
{
    printf("QUEUE UNDERFLOW\n");
    return;
}
if(front==rear)
{
del=arr[front];
front=-1;
rear=-1;
printf("%d DEQUEUED FROM QUEUE\n",del);
return;
}
del=arr[front];
front=(front+1)%n;
printf("%d DEQUEUED FROM QUEUE\n",del);
}
void display(int n)
{
    if(isempty())
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    for(int i=front;i!=rear;i=(i+1)%n)
    {
        printf("%d\n",arr[i]);
    }
    printf("%d",arr[rear]);
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
            display(max);
            break;
            case 2:
            printf("ENTER THE NUMBER TO BE STORED:\t");
            scanf("%d",&item);
            enqueue(item,max);
            break;
            case 3:
            dequeue(max);
            break;
            case 4:
            printf("BYE\n");
            break;
            default:
            printf("WRONG CHOICE PLEASE REENTER\n");
        }
    } while (choice!=4);
    
}