/* Search for the given key (target) element in the given list of positive integers that are stored using a singly linked list 
in which elements are added to the front of the list.

Input:
The first line of input will contain the key element.
The subsequent lines will each contain one integer of the list.
The end of the list will be indicated through an input of -1. Do not add the -1 itself to the list.

Output:
Display the position of the given element, if found. If not found, display 0.

Note:
Position of the first element in the list is 1 and not 0. */

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
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

void addFront(int val, list *lst)
{
    node *temp = (node *)malloc(sizeof(node));
    if(lst->head == NULL)
    {
        temp->data = val;
        temp->next = NULL;
        lst->head = temp;
    }
    else
    {
        temp->data = val;
        temp->next = lst->head;
        lst->head = temp;
    }
    lst->size++;
}

void search(int ele, list *lst)
{
    int pos = 0;
    int index = 1;
    node *curr;
    curr = lst->head;
    while(curr != NULL)
    {
        if(curr->data == ele)
        {
            pos = index;
            break;
        }
        index++;
        curr = curr->next;
    }
    printf("%d", pos);
}

int main()
{
    int ele, val;
    list *lst = createList();
    scanf("%d", &ele);
    while(1)
    {
        scanf("%d", &val);
        if(val == -1)
        {
            break;
        }
        addFront(val, lst);
    }
    search(ele, lst);
}