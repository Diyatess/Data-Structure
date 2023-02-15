#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head=NULL,*temp,*pre;

int insert(int);
int insert_end(int);
int insert_after(int,int);
int dlt_begin();
int dlt_end();
int dlt_value();
void display();

int main()
{
    int choice,value,loc;
    while(1)
    {
        printf("\n----Menu----\n");
        printf("\n 1.Insert at beginning \t 2.Insert at end\t 3.Insert after a value");
        printf("\n 4.Delete at beginning \t 5.Delete at end \t 6.Delete a value \n 7.Display");
        printf("\n Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter your data:");
            scanf("%d",&value);
            insert(value);
            break;
        case 2:
            printf("Enter your data:");
            scanf("%d",&value);
            insert_end(value);
            break;
        case 3:
            printf("Enter the value to be insert: ");
		    scanf("%d", &value);
		    printf("Enter the location: ");
		    scanf("%d", &loc);
	    	insert_after(value,loc);
            break;
        case 4:dlt_begin();
            break;
        case 5:dlt_end();
            break;
        case 6:
            printf("Enter your data to be deleted:");
            scanf("%d",&value);
            dlt_value(value);
            break;
        case 7:
            display();
            break;
        default:printf("\n !!OOPS!! You entered a wrong choice...");
        }
    }
}

int  insert( int value)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
        newnode->next=head;
        head=newnode;
        temp->prev=newnode;
    }
}

void display()
{
    if(head==NULL)
        printf("List is empty!!");
    else
    {
        printf("\n");
        temp=head;
        while(temp->next!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d->NULL \n",temp->data);
    }
}

int insert_end(int value)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

int insert_after(int value , int loc)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    temp=head;
    if(head==NULL)
        printf("List is empty");

    else if((temp->next==NULL)&&(temp->data==loc)&&(temp->prev==NULL))
    {
        newnode->prev=temp;
        newnode->next=NULL;
        temp->next=newnode;
    }
    else
    {
        temp=head;
        while((temp->data!=loc)&&(temp->next!=NULL))
        {
            temp=temp->next;
        }


         if((temp->next==NULL)&&(temp->data==value))
          {
               temp->next=newnode;
               newnode->prev=temp;
               newnode->next=NULL;
          }
          else if(temp->data==loc && temp->next!=NULL)
          {
              newnode->prev=temp;
              temp->next->prev=newnode;
              newnode->next=temp->next;
              temp->next=newnode;
          }

        else
            printf("NOT found...");
    }

}

int dlt_begin()
{
    temp=head;
    if(head==NULL)
        printf("List is empty..");
    else if(temp->next==NULL && temp->prev==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        head=temp->next;
        temp->next->prev=NULL;
        free(temp);
    }
}
int dlt_end()
{
    temp=head;
    if(head==NULL)
        printf("List is empty..");
    else if(temp->next==NULL && temp->prev==NULL)
    {
        head=NULL;
        free(temp);
    }
    else
    {
       while(temp->next!=NULL)
       {
           pre=temp;
           temp=temp->next;
       }
       pre->next=NULL;
       free(temp);
    }
}

int dlt_value(int value)
{
    if(head==NULL)
    {
       printf("List is empty");
       return 0;
    }
    else if((temp->next==NULL)&&(temp->data==value)&&(temp->prev==NULL))
    {
        head=NULL;
        free(temp);
        return 0;
    }
    else
    {
        temp=head;
        while((temp->data!=value) && (temp->next!=NULL))
        {
            pre=temp;
            temp=temp->next;
        }

         if((temp->next==NULL)&&(temp->data==value))
          {
               pre->next=NULL;
               free(temp);
               return 0;
          }
          else if(temp->data==value && temp->next!=NULL)
          {
              pre->next=temp->next;
              temp->next->prev= temp->prev;
              free(temp);
          }

        else
            printf("NOT found...");
    }
}
