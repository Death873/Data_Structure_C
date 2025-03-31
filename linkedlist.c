#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct queue
{
    int data;
    struct queue *link;
}qu;
qu *front=NULL,*rear=NULL; 
bool isempty()
{
    return front==NULL;
} 
void display()
{
qu *temp;

    if(isempty())
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    temp=front;
    while(temp->link!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("%d\n",temp->data);
}

qu *enqueue(int data)
{
    qu *newnode,*temp;
    newnode=(qu *)malloc(sizeof(qu));
    newnode->data=data;
    printf("%d ENTERED IN QUEUE....\n",data);
    if(front==NULL)
    {
        newnode->link=NULL;
        front=newnode;
        rear=newnode;
        return front;
    }
    temp=front;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=newnode;
    newnode->link=NULL;
    rear=newnode;
    return rear;
}

void dequeue()
{
    if(isempty())
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    qu *del;
    del=front;
    front=front->link;
    printf("%d DEQUEUED FROM QUEUE\n",del->data);
    free(del);
}

void fmem()
{
    qu *prev;
    while(front->link!=NULL)
    {
        prev=front;
        front=front->link;
        free(prev);
    }
    free(front);
}

void main()
{
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
            enqueue(item);
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