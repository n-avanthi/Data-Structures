#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int top = -1, ch;
int stk[SIZE];

struct shop
{
    char name[20];
    int price;
};
typedef struct shop shop;
shop s[SIZE];

void push();
void pop();
void peek();
void display();

int main()
{
for(; ;)
    {
        printf("\nSTACK OF STUCTURES - OPERATIONS");
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

void push()
{
    if(SIZE - 1 == top)
    {
        printf("\nStack Overflow!!");
        printf("\nPlease pop some items to continue!!");
    }
    else
    {
        ++top;
        printf("\nEnter name of item: ");
        scanf("%s", s[top].name);
        printf("\nEnter price of item: ");
        scanf("%d", &s[top].price);
        printf("\nElements %s and %d have been pushed into stack. Value of top is %d", s[top].name, s[top].price, top);
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
        printf("\nPopped elements are %s and %d. Value of top is %d", s[top].name, s[top].price, top);
        top--;
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
        printf("\nElements at the top are %s and %d. Value of top is %d", s[top].name, s[top].price, top);
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
            printf("\n%s ", s[i].name);
            printf("%d", s[i].price);
        }
        printf("\n");
    }
}


