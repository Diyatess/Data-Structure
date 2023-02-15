#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*head = NULL,*temp,*prev;
int insert(int);
int insert_end(int);
int insert_between(int,int);
int delete_end();
int delete_begin();
int delete_loc(int);
void display();
void main()
{
   int choice, value,loc;
   while(1)
   {
      printf("\n MENU \n");
      printf(" 1. Insert  2. Display 3.Insert at End 4.Insert Between \n 5.Delete at end 6.Delete at beginning 7.Delete Between \n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
        {
	        case 1: printf("Enter the value to be insert: ");
		    scanf("%d", &value);
	    	insert(value);
	    	break;
	        case 2: display();
	        break;
	        case 3: printf("Enter the value to be insert: ");
		    scanf("%d", &value);
	    	insert_end(value);
		    break;
		    case 4: printf("Enter the value to be insert: ");
		    scanf("%d", &value);
		    printf("Enter the location: ");
		    scanf("%d", &loc);
	    	insert_between(value,loc);
		    break;
		    case 5:
	    	delete_end();
		    break;
		    case 6:
		    delete_begin();
		    break;
		    case 7:
            printf("Enter the location: ");
		    scanf("%d", &loc);
		    delete_loc(loc);
		    break;
	        default: printf("\nWrong selection!!! Please try again!!!\n");
        }
   }
}
int insert(int value)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if(head == NULL)
    {
        newNode->next = NULL;
        head=newNode;
    }
    else
    {
        newNode->next=head;
        head=newNode;
      }
    }
void display()
{
    if(head == NULL)
    printf("\nList is Empty!!!\n");
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
	        printf("%d--->",temp->data);
	        temp = temp -> next;
        }
        printf("%d--->NULL",temp->data);
   }
}

int insert_end(int value)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    newnode->next= NULL;
    if(head == NULL)
    {
        head=newnode;
    }
    else
    {
        temp=head;
      while(temp->next != NULL)
      {
    	temp=temp->next;
      }
      temp->next=newnode;
    }
}

int insert_between(int value,int loc)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    //newnode->next= NULL;
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        temp=head;
      while(temp->data != loc)
      {
    	if(temp->next==NULL)
        {
            printf("Location not found");
            exit(0);
        }
        else
        {
            temp=temp->next;
        }
      }

      newnode->next=temp->next;
      temp->next=newnode;
    }
}

int delete_end()
{
    if(head== NULL)
    {
       printf("list is empty");
    }
    else
    {
        temp=head;
        if(temp->next==NULL)
        {
            head=NULL;
            free(temp);
        }
        while(temp->next!=NULL)
        {
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        free(temp);
      }
}
int delete_loc(int loc)
{
   if(head==NULL)
    {
        printf("There is no element to delete");
        return 0;
    }
    temp=head;
    if((temp->next!=NULL)&&(temp->data==loc))
    {
        head=temp->next;
        free(temp);
        return 0;
    }

      while((temp!=NULL)&&(temp->data!=loc))
    {
         prev=temp;
         temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("Element not Found");
        return 0;
    }
    else
    {
    prev->next=temp->next;
    free(temp);
    }


}

int delete_begin()
{
   if(head== NULL)
    {
       printf("list is empty");
    }
    else
    {
        temp=head;
        if(temp->next==NULL)
        {
            head=NULL;
            free(temp);
        }
        if(temp->next==NULL)
        {
            head=NULL;
        }
        if(temp->next!=NULL)
        {
            head=temp->next;
            free(temp);
        }
      }
}
