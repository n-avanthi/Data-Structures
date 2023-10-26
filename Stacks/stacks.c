#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int top = -1, ch, ele;
int stk[SIZE];

void push()
{
    if(SIZE - 1 == top)
    {
        printf("\nStack Overflow!!");
        printf("\nPlease pop some items to continue!!");
    }
    else
    {
        printf("\nEnter int element to be pushed into stack: ");
        scanf("%d", &ele);
        stk[++top] = ele;
        printf("\nElement %d has been pushed into stack and value of top is %d", ele, top);
    }
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack Underflow!!");
        printf("\nPlease push some items to continue!!");
    }
    else
    {
        int pop;
        pop = stk[top];
        top--;
        printf("\nElement popped out is %d and value of top is %d", pop, top);
    }
}

void peek()
{
    if(top == -1)
    {
        printf("\nStack Underflow!!");
        printf("\nPlease push some items to continue!!");
    }
    else
    {
        printf("\nElement at the top is %d and value of top is %d", stk[top], top);
    }
}

void display()
{
    if(top == -1)
    {
        printf("\nStack Underflow!!");
        printf("\nPlease push some items to continue!!");
    }
    else
    {
        printf("\nElements of stack are: ");
        for(int i = top; i >= 0; i--)
        {
            printf("\n%d", stk[i]);
        }
        printf("\n");
    }
}

int main()
{
    for(; ;)
    {
        printf("\nSTACKS - OPERATIONS");
        printf("\n1. PUSH");
        printf("\n2. POP");
        printf("\n3. PEEK");
        printf("\n4. DISPLAY");
        printf("\n5. EXIT");

        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nProgram exiting!!");
                exit(0);
        }
    }
}

