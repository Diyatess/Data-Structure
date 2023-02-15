#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}*top = NULL,*temp;
int push(int);
int pop();
int peak();
void display();

int main()
{
    int choice,value;
    while(1)
    {
        printf("\n--------MENU--------\n");
        printf("\n 1.PUSH 2.POP \n 3.PEAK 4.DISPLAY");
        printf("\n Enter Your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the value to be insert: ");
		    scanf("%d", &value);
	    	push(value);
            break;
            case 2:pop();
            break;
            case 3:peak();
            break;
            case 4:display();
            break;
            default:printf("OOPS!! You selected wrong option");
        }
    }
}

int push(int value)
{
    struct Node *newnode;
    newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = value;
    if(top == NULL)
    {
        newnode->next = NULL;
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
      }
}

int pop()
{
    if(top== NULL)
    {
       printf("\n Stack Underflow");
    }
    else
    {
        temp=top;
        top=temp->next;
        free(temp);
        printf("\n element poped");
      }
}

int peak()
{
    if(top==NULL)
        printf("\n Stack is empty!!");
    else
        printf("\n Peak value is: %d",top->data);
}

void display()
{
    if(top == NULL)
    {
      printf("\n Stack is Empty!!!\n");
      return 0;
    }
    else
    {
        temp=top;
        printf("Printing Stack elements \n");
        while(temp->next!=NULL)
        {
           printf("%d--->",temp->data);
	        temp = temp -> next;
        }
        printf("%d-->NULL",temp->data);
    }
}

