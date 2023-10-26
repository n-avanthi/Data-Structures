/* Count how many times 'e' is present among the input characters that are stored using a singly linked list.

Input:
Each character will be input in a new (separate) line.
When the input character is a space, you can ignore the space and stop scanning for more input 
(i.e.) you have reached the end of the list of input characters.

Output:
An integer */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
}node;

typedef struct list
{
    node *head;
    int size;
}list;

list* createList()
{
    list *lst = (list *)malloc(sizeof(list));
    lst->head = NULL;
    lst->size = 0;
    return lst;
}

void push(char ele, list* lst)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    if(lst->head == NULL)
    {
        temp->next = NULL;
        lst->head = temp;
    }
    else
    {
        temp->next = lst->head;
        lst->head = temp;
    }
}

void count(list *lst)
{
    int count = 0;
    node *curr = lst->head;
    while(curr != NULL)
    {
        if(curr->data == 'e')
        {
            count++;
        }
        curr = curr->next;
    }
    printf("%d", count);
}

int main()
{
    char ele;
    list *lst = createList();
    while(1)
    {
        scanf("%c", &ele); //not " %c" as that doesnt take space as a char.
        if(ele == ' ') 
        {
            break;
        }
        else if(ele == '\n')
        {
            continue;
        }
        else 
        {
            push(ele, lst);
        }
    }
    count(lst);
}

