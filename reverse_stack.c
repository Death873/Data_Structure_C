#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define max 100

int arr[max];
int top=-1;

bool isEmpty()
{
    return top==-1;
}
void Push(int data)
{
    if(top==max-1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    arr[++top]=data;
}

int Pop()
{
    int del;
    if(isEmpty())
    {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
del=arr[top--];
return del;
}

void reverse(int arr[],int n)
{
int i;
for(i=0;i<n;i++)
{
    Push(arr[i]);
}
for(i=0;i<n;i++)
{
    arr[i]=Pop();
}
printf("REVERSED ARRAY\n");
for(i=0;i<n;i++)
{
    printf("ELEMENT %d:-%d\n",(i+1),arr[i]);
}
}

void main()
{
    int n,i;
    printf("ENTER THE NO OF ELEMENTS IN THE ARRAY\n");
    scanf("%d",&n);
    int *array;
    array=(int *)malloc(n*sizeof(int));
    printf("NOW ENTER THE DATA\n");
    for( i=0;i<n;i++)
    {
        printf("ELEMENT %d:- ",i+1);
        scanf("%d",&array[i]);
    }
    printf("ORIGINAL ARRAY\n");
    for(i=0;i<n;i++)
    {
        printf("ELEMENT %d:-%d\n",(i+1),array[i]);
    }
    reverse(array,n);
    free(array);
}