#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int front = -1, rear = -1, ch, ele;
int myQ[SIZE];

void enQueue()
{
    if(rear == SIZE-1)
    {
        printf("\nQueue is full.. Dequeue some elements to continue!!\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        myQ[++rear] = ele;
        printf("\n%d has been inserted\n", ele);
        printf("\nFront is at %d position and Rear is at %d position\n", front, rear);
    }
}

int deQueue()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue is empty.. Enqueue some items to continue!!\n");
        return -1; //what if element is -1?
    }
    else
    {
        int del;
        del = myQ[front++];
        if(front == rear + 1)
        {
            front = -1, rear = -1;
        }
        printf("\n%d has been deleted\n", del);
        printf("\nFront is at %d position and Rear is at %d position\n", front, rear);
    }
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("\nQueue is empty.. Enqueue some items to continue!!\n");
    }
    else
    {
        printf("\n");
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", myQ[i]);
        }
        printf("\n");
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



