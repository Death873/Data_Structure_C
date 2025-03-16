#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}node;

node *top=NULL;
void peek()
{
    if(top==NULL)
    printf("STACK NOT AVAILABLE\n");
    else
    {
        printf("%d\n",top->data);
    }
}
node *PUSH(int data)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    if(top==NULL)
    {
        temp->link=NULL;
        top=temp;
    }
    else
    {
        temp->link=top;
        top=temp;
        
    }
    return top;
}
void POP()
{
    node *temp;
    if(top==NULL)
    {
       printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED\n");
       return ;
    }
    else if(top->link==NULL)
    {   
       printf("DELETED VALUE=%d\n",top->data);
       free(top);
       top=NULL;
    }
    else
    {
       temp=top;
       top=top->link;
       printf("DELETED VALUE=%d\n",temp->data);
       free(temp);
    }
}
void fmem()
{
    node *prev;
    while(top->link!=NULL)
    {
        prev=top;
        top=top->link;
        free(prev);
    }
    free(top);
}
int main()
{
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
        peek();
        break;
        case 2:
        printf("ENTER THE VALUE TO PUSH\n");
        scanf("%d",&item);
        PUSH(item);
        break;
        case 3:
        POP();
        break;
        case 4:
        printf("BYE\n");
        break;
        default:
        printf("ENTER A VALID CHOICE\n");

    }
}while(choice!=4);
fmem();
return 0;
}