#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int *arr;
int top=-1;
int initialize()
{
 int n;
 printf("ENTER THE NO OF ELEMNTS IN THE STACK\n");
 scanf("%d",&n);
 arr=(int *)malloc(n*sizeof(int));
 return n;
}
bool isEmpty()
{
    return top==-1;
}
void Peek()
{
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        return;
    }
    printf("%d\n",arr[top]);
}

void Push(int data,int n)
{
    if(top==n-1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    arr[++top]=data;
    printf("%d IS STORED IN STACK........\n",data);
}

void Pop()
{
    int del;
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        return;
    }
del=arr[top--];
printf("DELETED ELEEMENT=%d\n",del);
}
int main()
{
    int max=initialize();
    int choice,item;
    do
    {
    printf("PRESS '1' TO PEEK\n");
    printf("PRESS '2' TO PUSH\n");
    printf("PRESS '3' TO POP\n");
    printf("PRESS '4' TO EXIT\n");
    printf("ENTER CHOICE:\t");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        Peek();
        break;
        case 2:
        printf("ENTER THE VALUE TO PUSH\n");
        scanf("%d",&item);
        Push(item,max);
        break;
        case 3:
        Pop();
        break;
        case 4:
        printf("BYE\n");
        break;
        default:
        printf("ENTER A VALID CHOICE\n");

    }
}while(choice!=4);
return 0;
}