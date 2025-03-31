#include<stdio.h>
#include<stdlib.h>
typedef struct BINARYTREE
{
int data;
struct BINARYTREE *left;
struct BINARYTREE *right;
}bt;

bt *createnode(data)
{
bt *newnode;
newnode=(bt *)malloc(sizeof(bt));
newnode->data=data;
newnode->left=NULL;
newnode->right=NULL;
return newnode;
}

bt *insert(bt **root,int data)
{
bt *newnode;
newnode=createnode(data);
if(*root==NULL)
{
    *root=newnode;
    return *root;
}
bt *queue[100];
int front=0,rear=0;
queue[rear++]=*root;
while(front<rear)
{
    bt *temp=queue[front++];
    if(temp->left==NULL)
    {
      temp->left=newnode;
      return newnode;
    }
    else
    {
        queue[rear++]=temp->left;
    }

if(temp->right==NULL)
{
 temp->right=newnode;
 return newnode;
}
else
{
queue[rear++]=temp->right;
}
}
}

void preorder(bt *root)
{
    if(root!=NULL)
    {
        printf("%d\n",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void main()
{
    bt *root=NULL;
    int choice;
    int data;
    do{
    printf("PRESS '1' TO INSERT\n");
    printf("PRESS '2' TO DISPLAY IN PREORDER\n");
    printf("PRESS '3' TO EXIT\n");
    printf("ENTER CHOICE\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("ENTER THE DATA INTO TREE\n");
        scanf("%d",&data);
        insert(&root,data);
        break;
        case 2:
        preorder(root);
        break;
        case 3:
        printf("BYE\n");
        break;
        default:
        printf("WRONG CHOICE PLEASE RE-ENTER\n");
        break;
    }
}while(choice!=3);
}