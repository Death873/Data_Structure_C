#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}bst;

bst *createnode (int data)
{
    bst *temp;
    temp=(bst *)malloc(sizeof(bst));
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void insert(bst **root,int data)
{
bst *newnode=createnode(data);
if(*root==NULL)
{
    *root=newnode;
    return;
}
if((*root)->data>data)
{
    insert((&(*root)->left),data);
}
else
{
    insert((&(*root)->right),data);
}
}

void preorder(bst *root)
{
    if(root)
    {
    printf("%d  ",root->data);
    preorder(root->left);
    preorder(root->right);
    }
}

void inorder(bst *root)
{
    if(root)
    {
    inorder(root->left);
    printf("%d  ",root->data);
    inorder(root->right);
    }
}

void postorder(bst *root)
{
    if(root)
    {
    postorder(root->left);
    postorder(root->right);
    printf("%d  ",root->data);
    }
}

bst *findmin(bst *root)
{
while(root && root->left)
{
    root=root->left;
}
return root;
}

bst *deletenode(bst *root,int key)
{
    if (root==NULL)
    {
        printf("TREE IS EMPTY, NOTHING TO DELETE\n");
        return NULL;
    }
    if(key<root->data)
    {
        root->left=deletenode(root->left,key);
    }
    else if(key>root->data)
    {
        root->right=deletenode(root->right,key);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            printf("%d DELETED FROM TREE\n",key);
            free(root);
            return NULL;
        }
        else if(root->left==NULL)
        {
            printf("%d DELETED FROM TREE\n",key);
            bst *temp=root->right;
            free(root);
            return temp;   
        }
        else if(root->right==NULL)
        {
            printf("%d DELETED FROM TREE\n",key);
            bst *temp=root->left;
            free(root);
            return temp;
        }
        bst *temp=findmin(root->right);
        int swap=root->data;
        root->data=temp->data;
        temp->data=swap;
        root->right=deletenode(root->right,temp->data);


    }
    return root;
}

int main()
{
    int choice,data,key;
    bst *root=NULL;
    do
    {
    printf("\nPRESS '1' TO INSERT IN BST\n");
    printf("PRESS '2' TO DELETE A NODE\n");
    printf("PRESS '3' TO DISPLAY PREORDER TRAVERSAL\n");
    printf("PRESS '4' TO DISPLAY INORDER TRAVERSAL\n");
    printf("PRESS '5' TO DISPLAY POSTORDER TRAVERSAL\n");
    printf("PRESS '6' TO EXIT MENU\n");
    printf("ENTER CHOICE\n");
    scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("ENTER A VALUE TO INSERT:   ");
            scanf("%d",&data);
            insert(&root,data);
            break;
        case 2:
            printf("ENTER A VALUE TO DELETE:   ");
            scanf("%d",&key);
            root=deletenode(root,key);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            inorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            printf("EXITING MENU......\n");
            break;
        default:
            printf("WRONG CHOICE! PLEASE REENTER\n");
            break;
        }
    }while(choice!=6);
}