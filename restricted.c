#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *arr;
int front=0,rear=0;
int initialize()
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
bool isFull(n)
{
    return (rear+1)%n==front;
}
void EnqueueRear(int data,int n)
{
    if(isFull(n))
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    if(isempty())
    {
        front++;
        rear++;
    }
    else
    {
        rear=(rear+1)%n;
    }
    arr[rear]=data;
    printf("%d ENTERED IN QUEUE AT REAR\n",data);
}
void EnqueueFront (int data,int n)
{
    if(isFull(n))
    {
        
        printf("QUEUE OVERFLOW\n");
        return;
    }
    if(isempty())
    {
        front++;
        rear++;
    }
    else
    {
        front=((front-1)+n)%n;
    }
    arr[front]=data;
    printf("%d ENTERED IN QUEUE AT FRONT\n",data);
    
}
void DequeueFront(int n)
{
    int del;
    if(isempty())
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    del=arr[front];
    printf("%d DEQUEUED FROM QUEUE FROM FRONT\n",del);
    if(front==rear)
    {
    front=-1;
    rear=-1;
    }
    else
    {
        front=(front+1)%n;
    }
}
void DequeueRear(int n)
{
    int del;
    if(isempty())
    {
        printf("QUEUE UNDERFLOW\n");
        return; 
    }
    del=arr[rear];
    printf("%d DEQUEUED FROM QUEUE FROM FRONT\n",del);
    if(front==rear)
    {
    front=-1;
    rear=-1;
    }
    else
    {
        rear=((rear-1)+n)%n;
    }
}
void display(int n)
{
    if(isempty())
    {
        printf("QUEUE UNDERFLOW\n");
        return; 
    }
    printf("\n QUEUE ELEMENTS:  ");
    for(int i=front;i!=rear;i=(i+1)%n)
    {
        printf("%d\t",arr[i]);
    }
    printf("%d\n",arr[rear]);
}


void fain(int choice)
{
    int max=initialize();
    int a,item;
   if(choice==1)
   {
    do
    {
        printf("PRESS '1' TO DISPLAY\n");
        printf("PRESS '2' TO ENQUEUE AT REAR\n");
        printf("PRESS '3' TO DEQUEUE FROM FRONT\n");
        printf("PRESS '4' TO DEQUEUE FROM REAR\n");
        printf("PRESS '5' TO EXIT\n");
        printf("ENTER CHOICE\n"); 
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            display(max);
            break;
            case 2:
            printf("ENTER THE NUMBER TO BE STORED:\t");
            scanf("%d",&item);
            EnqueueRear(item,max);
            break;
            case 3:
            DequeueFront(max);
            break;
            case 4:
            DequeueRear(max);
            break;
            case 5:
            printf("BYE\n");
            break;
            default:
            printf("WRONG CHOICE PLEASE REENTER\n");
        }
    } while (a!=5);
   }
   else
   {
    do
    {
        printf("PRESS '1' TO DISPLAY\n");
        printf("PRESS '2' TO ENQUEUE AT REAR\n");
        printf("PRESS '3' TO ENQUEUE AT FRONT\n");
        printf("PRESS '4' TO DEQUEUE FROM FRONT\n");
        printf("PRESS '5' TO EXIT\n");
        printf("ENTER CHOICE\n"); 
        scanf("%d",&a);
        switch(a)
        {
            case 1:
            display(max);
            break;
            case 2:
            printf("ENTER THE NUMBER TO BE STORED:\t");
            scanf("%d",&item);
            EnqueueRear(item,max);
            break;
            case 3:
            printf("ENTER THE NUMBER TO BE STORED:\t");
            scanf("%d",&item);
            EnqueueFront(item,max);
            break;
            case 4:
            DequeueFront(max);
            break;
            case 5:
            printf("BYE\n");
            break;
            default:
            printf("WRONG CHOICE PLEASE REENTER\n");
        }
    } while (a!=5);
   }
}

int main()
{
int choice;
printf("PRESS '1' FOR INPUT RESTRICTED QUEUE\n");
printf("PRESS '2' FOR OUTPUT RESTRICTED QUEUE\n");
printf("ENTER CHOICE\n"); 
scanf("%d",&choice);
if(choice==1 || choice==2)
{
    fain(choice);
}
else
{
    printf("WRONG CHOICE\n");
}
return 0;
}