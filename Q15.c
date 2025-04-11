#include<stdio.h>
#include<stdlib.h>
typedef struct BINARYTREE
{
int data;
struct BINARYTREE *left;
struct BINARYTREE *right;
}bt;

bt *createnode(int data)
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

void bfs( bt*root)
{
    if(root==NULL)
    {
        printf("TREE IS EMPTY, NOTHING TO SHOW\n");
        return ;
    }
    bt *queue[100];
    int f=0,r=0;
    queue[r++]=root;
    while(f<r)
    {
        bt *temp=queue[f++];
        printf("%d  ",temp->data);
        if(temp->left!=NULL)
        queue[r++]=temp->left;
        if(temp->right!=NULL)
        queue[r++]=temp->right;
    }
    printf("\n");
}

void deletedeepest(bt *root,bt *del)
{
bt *queue[100];
int f=0,r=0;
bt *temp;
queue[r++]=root;
while(f<r)
{
   temp=queue[f++];
   if(temp->left)
   {
    if(temp->left==del)
    {
        temp->left=NULL;
        free(del);
        return;
    }
    else
    {
        queue[r++]=temp->left;
    }
   }

   if(temp->right)
   {
    if(temp->right==del)
    {
        temp->right=NULL;
        free(del);
        return;
    }
    else
    {
        queue[r++]=temp->right;
    }
   }
}
}

void deletetree(bt **root,int key)
{
 if(*root==NULL)
 {
    printf("TREE IS EMPTY, NOTHING TO DELETE\n");
    return;
 }
 bt *queue[100];
 int f=0,r=0;
 bt*key_node,*temp;
 key_node=NULL;
 queue[r++]=*root;
 while(f<r)
 {
    temp=queue[f++];
    if(temp->data==key)
    {
        key_node=temp;
    }
    if(temp->left)
    queue[r++]=temp->left;
    if(temp->right)
    queue[r++]=temp->right;

 }
 if (key_node != NULL) {
    if (key_node == *root && temp == *root && temp->left == NULL && temp->right == NULL) {
        free(*root);
        *root = NULL;
        printf("%d DELETED FROM TREE....\n", key);
        return;
    }
 if(key_node!=NULL)
 {
    int x=temp->data;
    deletedeepest(*root,temp);
    key_node->data=x;
    printf("%d DELETED FROM TREE....\n",key);

 }
 else
 {
    printf("%d NOT FOUND IN TREE TRY AGAN!\n",key);
 }
}
}

int main()
{
    int choice;
    bt *root=NULL;
    int data,key;
    do
    {
    printf("PRESS '1' TO DISPLAY(BFS TRAVERSAL)\n");
    printf("PRESS '2' TO INSERT A NEW NODE IN THE BINARY TREE\n");
    printf("PRESS '3' TO DELETE A NODE IN BINARY TREE\n");
    printf("PRESS '4' TO EXIT THE MENU\n");
    printf("ENTER CHOICE\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            bfs(root);
            break;
        case 2:
            printf("ENTER A VALUE TO INSERT:    ");
            scanf("%d",&data);
            insert(&root,data);
            break;
        case 3:
            printf("ENTER A VALUE TO DELETE:    ");
            scanf("%d",&key);
            deletetree(&root,key);
            break;
        case 4:
            printf("BYE...\n");
            break;
        default:
            printf("WRONG CHOICE! REENTER\n");
            break;
        }
    }while(choice!=4);
    return 0;
}