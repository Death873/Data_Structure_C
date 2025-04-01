#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}node;

node *start=NULL;

//Function to display Doubly Circular Linked List
void display()
{
    node *temp;
    if(start==NULL)
    {
        printf("NO LINKED LIST AVAILABLE\n");
        return ;
    }
    else
    {
        temp=start;
        while(temp->next!=start)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

//Function to insert at begin/start
node *insert_begin(int data)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    if(start==NULL)
    {
        temp->prev=temp;
        temp->next=temp;
        start=temp;
    }
    else
    {
        temp->next=start;
        temp->prev=start->prev;
        start->prev->next=temp;
        start->prev=temp;
        start=temp;

    }
    return start;
}

//Function to insert node at the end
node *insert_end(int data)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    if(start==NULL)
    {
        temp->prev=temp;
        temp->next=temp;
        start=temp;
    }
    else
    {
        temp->prev=start->prev;
        temp->next=start;
        start->prev->next=temp;
        start->prev=temp;
    }
    return start;
}

//Function to insert node at any index
node *insert_index(int data,int ind)
{
    node *temp,*curr;
    char ch;
    int i=1;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    if(start==NULL)
    {
        printf("wrong choice\n");
        printf("DO YOU WANT TO INSERT THIS VALUE AT BEGINNING?   Y/N\n");
        getchar();
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        insert_begin(data);
        else
        return 0;
    }
    else if(ind<=0)
    {
        printf("ERROR CHECK THE POSITION VALUE\n");
        return 0;
    }
    else if(ind==1)
    {
        insert_begin(data);
        return 0;
    }
    else
    {
        curr=start;
        while(i<ind &&curr->next!=start)
        {
            curr=curr->next;
            i++;
        }
        if(i==ind)
        {
            if(curr->next==start)
            {
                insert_end(data);
                return 0;
            }
         temp->next=curr;
         temp->prev=curr->prev;
         curr->prev->next=temp;
         curr->prev=temp;
        }
        else
        {
            printf("wrong choice\n");
            printf("DO YOU WANT TO INSERT THIS VALUE AT END?    Y/N\n");
            getchar();
            scanf("%c",&ch);
            if(ch== 'y' || ch=='Y')
            insert_end(data);
            else
            return 0;
        }
        return start;
    }
}

//Function to delete node at start/begin
void delete_begin()
{
node *temp;
if(start==NULL)
{
    printf("CAN YOU DELETE A NODE WHICH IS NOT CREATED?\nI GUESS NOT!\n");
    return;
}
else if(start->next==start)
 {
    printf("DELETED VALUE=%d\n",start->data);
    free(start);
    start=NULL;
 }
 else
 {
    temp=start;
    printf("DELETED VALUE=%d\n",temp->data);
    start->prev->next=start->next;
    start->next->prev=start->prev;
    start=start->next;
    free(temp);
}
}

//Function to delete at end
void delete_end()
{
    node*temp;
    if(start==NULL)
{
    printf("CAN YOU DELETE A NODE WHICH IS NOT CREATED?\nI GUESS NOT!\n");
    return;
}
else if(start->next==start)
 {
    printf("DELETED VALUE=%d\n",start->data);
    free(start);
    start=NULL;
 }
 else
 {
    temp=start->prev;
    start->prev=temp->prev;
    temp->prev->next=start;
    printf("DELETED VALUE=%d\n",temp->data);
    free(temp);
 }
}

//Function to delete node at any index
void delete_pos(int pos)
{
    node *temp;
    int i=1;
    char ch;
    if(start==NULL)
    {
      printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED\n");
      return ;
    }
      else if(pos<=0)
      {
        printf("ERROR CHECK THE POSITION VALUE\n");
        return ;
      }
      else if(pos==1)
      {
          delete_begin();
          return ;
      }
    else
    {
        temp=start;
        while(i<pos && temp->next!=start)
        {
            temp=temp->next;
            i++;
        }
        if(i==pos)
        {
            if(temp->next==start)
            {
                delete_end();
                return;
            }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        printf("DELETED VALUE=%d\n",temp->data);
        free(temp);
        }
        else
        {
            printf("WRONG CHOICE\n");
            printf("DO YOU WANT TO DELETE THE LAST NODE?   Y/N\n");
            getchar();
            scanf("%c",&ch);
            if(ch=='Y' || ch=='y')
            delete_end();
            else
            return;
        }
    }
}

//Function to delete entire list
void freemem()
{
    node *temp;
    if(start!=NULL)
    {
    while(start->link!=start)
    {
        temp=start;
        start=start->link;
        free(temp);
    }
    free(start);
    }
}

void main()
{
int choice,data,value,val,pos,sval;
    do{
    printf("PRESS '1' TO DISPLAY\n");
    printf("PRESS '2' TO APPEND\n");
    printf("PRESS '3' TO INSERT BEGIN\n");
    printf("PRESS '4' TO INSERT AT ANY POSITION\n");
    printf("PRESS '5' TO DELETE BEGIN\n");
    printf("PRESS '6' TO DELETE END\n");
    printf("PRESS '7' TO DELETE AT ANY POSITION\n" );
    printf("PRESS '8' TO DELTE ENTIRE LIST\n");
    printf("PRESS '9' TO EXIT\n");
    printf("ENTER CHOICE\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            display();
            break;
        case 2:
            printf("ENTER THE VALUE TO STORE:     ");
            scanf("%d",&data);
            append(data);
            break;
        case 3:
            printf("ENTER THE VALUE TO STORE:     ");
            scanf("%d",&value);
            insert_begin(value);
            break;
        case 4:
            printf("ENTER THE VALUE TO STORE     ");
            scanf("%d",&val);
            printf("ENTER THE POSITION    ");
            scanf("%d",&pos);
            insert_pos(val,pos);
            break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
        case 7:
            printf("ENTER THE POSITION    ");
            scanf("%d",&pos);
            delete_pos(pos);
            break;
        case 8:
        	if(start==NULL)
            {
                printf("LIST ALREADY EMPTY!\n");
                break;
            }
            freemem();
            break;
        	break;
        case 9:
            printf("BYE\n");
            break;
        default:
            printf("ENTER A VALID CHOICE\n");
            break;
    }
}while(choice!=9);
freemem();
}
