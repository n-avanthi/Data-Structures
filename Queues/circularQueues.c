#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int ele, ch, front = -1, rear = -1;
int myQ[SIZE];

void enQueue()
{
    if((front == 0 && rear == SIZE - 1) || (front == rear+1))
    {
        printf("\nQueue is full.. Dequeue some items to continue!!");
        printf("\nFront is at %d and Rear is at %d \n", front, rear);
    }
    else
    {
        if(front == -1)
        {
            front = 0;
            printf("\nfront == -1 hence front = 0\n");
        }
        if(rear == SIZE - 1 && front != 0)
        {
            rear = -1;
            printf("\nrear == size - 1 && front != 0 hence rear = -1\n");
        }

        myQ[++rear] = ele;
        printf("\n%d has been inserted\n", ele);
        printf("\nFront is at %d position and Rear is at %d position\n", front, rear);
    }
}

int deQueue()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty.. Enqueue some items to continue!!\n");
        printf("\nFront is at %d and Rear is at %d \n", front, rear);
        return -1; //what if element is -1?
    }
    else
    {
        int del;
        del = myQ[front++];
        if(front - 1 == rear)
        {
            front = -1, rear = -1;
            printf("\nfront - 1 == rear hence front = rear = -1\n");
        }
        if(front == SIZE)
        {
            front = 0;
            printf("\nfront == size hence front = 0\n");
        }

        printf("\n%d has been deleted\n", del);
        printf("\nFront is at %d and Rear is at %d \n", front, rear);
        return del;
    }
}

void display()
{
    if(front == -1 && rear == -1)
    {
        printf("\nQueue is empty.. Enqueue some items to continue!!\n");
        printf("\nFront is at %d and Rear is at %d \n", front, rear);
    }
    else
    {
        if(front <= rear)
        {
            printf("\nIn front <= rear");
            printf("\nFront is %d, rear is %d\n", front, rear);
            printf("\n");
            for (int i = front; i <= rear; i++)
            {
                printf("%d\t",myQ[i]);
            }
            printf("\n");
        }
        
        else
        {
            printf("\nIn front > rear (else part)");
            printf("\nFront is %d, rear is %d\n", front, rear);
            printf("\n");
            for (int i = 0; i <= rear; i++) 
            {
                printf("%d\t",myQ[i]);
            }

            printf("\n");
            
            for (int i = front; i <= SIZE - 1; i++) 
            {
                printf("%d\t", myQ[i]);               
            }
            printf("\n");
        }
    }
}

int main()
{
    for(; ;)
    {
        printf("\nLINEAR QUEUE - OPERATIONS");
        printf("\n1. ENQUEUE");
        printf("\n2. DEQUEUE");
        printf("\n3. DISPLAY");
        printf("\n4. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter element to be inserted: ");
                scanf("%d", &ele);
                enQueue();
                break;

            case 2:
                int del = deQueue();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram exiting!!");
                exit(0);
        }
    }
}