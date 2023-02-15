#include<stdio.h>
#include<stdlib.h>

int enqueue(int);
void display();
int dequeue();
int front=-1,rear=-1,q[10],N;
int main()
{
    int value,choice;
    printf("Enter the size of queue:");
    scanf("%d",&N);
     while(1)
   {
      printf("\n MENU \n");
      printf("1. Enqueue 2. Display 3.Dequeue\n");
      printf("Enter your choice: ");
      scanf("%d",&choice);
      switch(choice)
        {
	        case 1: printf("Enter the value to be insert: ");
		    scanf("%d", &value);
	    	enqueue(value);
	    	break;
	        case 2: display();
	        break;
	        case 3: dequeue();
	        break;
	        default: printf("\nWrong selection!!! Please try again!!!\n");
        }
   }
}

int enqueue(int value)
{
    if(front== -1 && rear==-1)
    {
        front=0;
        rear=0;
        q[rear]=value;
    }
    else if((rear+1)%N == front)
        printf("Queue is Full");
    else
    {
        rear=(rear+1)%N;
        q[rear]=value;
    }
}

int dequeue()
{
    if(front== -1 && rear==-1)
        printf("Queue is empty");
    else if(front == rear)
    {
        front = -1;
        rear = -1;
    }

    else
    {
        printf("%d is deleted",q[front]);
        front=(front++)%N;
    }
}

void display()
{

    if(front== -1 && rear==-1)
        printf("Queue is empty");
    else
    {
        int i=front;
        printf("Queue is:");
        while(i!=rear)
        {
            printf("%d--",q[i]);
            i=(i+1)%N;
        }
        printf("%d",q[rear]);
    }
}

