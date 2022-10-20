#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[])
{
    struct Node *last, *t;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < 5; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Length(struct Node *p)
{
    int length = 0;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

int sumOfElements(struct Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int maxOfList(struct Node *p)
{
    int element = INT_MIN;
    while (p)
    {
        if (element < p->data)
        {
            element = p->data;
        }
        p = p->next;
    }
    return element;
}

int minOfList(struct Node *p)
{
    int element = INT_MAX;
    while (p)
    {
        if (element > p->data)
        {
            element = p->data;
        }
        p = p->next;
    }
    return element;
}

int Search(struct Node *p, int key)
{
    int flag = 0, pos = 0;
    while (p)
    {
        if (p->data == key)
        {
            flag = 1;
        }
        pos++;
        p = p->next;
    }
    return flag;
}

int searchIndex(struct Node *p, int key)
{
    int pos = 0;
    while (p->data != key)
    {
        pos++;
        p = p->next;
    }
    return (pos + 1);
}

void Insert(struct Node *p, int value, int index)
{
    struct Node *t;
    if (index < 0 || index > 5)
    {
        return;
    }
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->prev = NULL;
        t->data = value;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        t->prev = p;
        t->next = p->next;
        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int Delete(struct Node *p, int index)
{
    int x = 0;
    if (index < 0 || index > 5)
    {
        return 0;
    }
    if (index == 1)
    {
        first = first->next;
        if (first)
        {
            first->prev = NULL;
            x = p->data;
            free(p);
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next)
        {
            p->next->prev = p->prev;
        }
        x = p->data;
        free(p);
    }
    return x;
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5}, n, x, index;
    create(A);
    printf("1 for Displaying List!\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("2 for Displaying Length of List!\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("3 for Displaying Sum of Elements of List!\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("4 for Displaying Max element of List!\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("5 for Displaying Min element of List!\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("6 for Searching element from List!\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("7 for Inserting elements in List!(put index=0 for inserting at beginning)\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("8 for Deleting elements from List!\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("9 To Quit\n");
    printf("-----------------------------------------------------------------------------------\n");

    while (1)
    {
        printf("Enter Value:\n");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("Here are the elements of list: \n");
            Display(first);
            break;
        case 2:
            printf("Here is the length of elements of list: \n");
            Length(first);
            break;
        case 3:
            printf("Here is the Sum of elements of list: \n");
            sumOfElements(first);

            break;
        case 4:
            printf("Here is the Max element of list: \n");
            maxOfList(first);

            break;
        case 5:
            printf("Here is the Min element of list: \n");
            minOfList(first);
            break;
        case 6:
            printf("Enter element you wish to search:\n");
            scanf(" %d", &x);
            Search(first, x);
            if (Search(first, x))
            {
                printf("Element Found at index: %d\n", searchIndex(first, x));
            }
            else
            {
                printf("Element Not found!\n");
            }
            break;
        case 7:
            printf("Enter value you wish to insert:\n");
            scanf(" %d", &x);
            printf("Enter index at which you wish to insert:\n");
            scanf(" %d", &index);
            Insert(first, x, index);
            printf("Here is your list after updation\n");
            Display(first);

            break;
        case 8:
            printf("Enter index at which you wish to delete:\n");
            scanf(" %d", &index);
            Delete(first, index);
            printf("Here is your list after updation\n");
            Display(first);
            break;

        case 9:
            exit(1);
            break;
        }
    }
    return 0;
}
