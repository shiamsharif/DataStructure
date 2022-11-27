#include <stdio.h>
#include <stdlib.h>

struct node
{
    int ginger;
    int garlic;
    struct node *next;
};
typedef struct node herbs;
// ShiamSharif_0032
herbs *start = NULL;
// node_creation.
herbs *getnode()
{
    herbs *newnode;
    newnode = (herbs *)malloc(sizeof(herbs));
    printf("Enter ginger value: \n");
    scanf("%d", &newnode->ginger);
    printf("Enter garlic value: \n");
    scanf("%d", &newnode->garlic);
    newnode->next = NULL;

    return newnode;
}
// ShiamSharif_0032.
// linked_list_creation.
void creation(int n)
{
    int i;
    herbs *newnode;
    herbs *temp;
    for (i = 0; i < n; i++)
    {
        newnode = getnode();
        if (start == NULL)
        {
            start = newnode;
        }
        else
        {
            temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }
}
// ShiamSharif_0032.
//  insertion a node from the first of list.
void insert_at_first()
{
    herbs *newnode;
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        newnode->next = start;
        start = newnode;
    }
}

// insretion a node at the end of list.
void insert_at_end()
{
    herbs *newnode;
    herbs *temp;
    newnode = getnode();
    if (start == NULL)
    {
        start = newnode;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

// inserting a node in intermediate position.
void insert_at_intermediate_position(int position)
{
    if (position == 0)
    {
        insert_at_first();
        return;
    }
    herbs *newnode;
    herbs *temp;
    newnode = getnode();
    if (start == NULL)
    {
        printf("ERROR: List is empty.\n");
        return;
    }
    int iterator = 1;
    temp = start;
    while (temp != NULL)
    {
        if (iterator == position)
        {
            newnode->next = temp->next;
            temp->next = newnode;
            return;
        }
        temp = temp->next;
        iterator += 1;
    }

    printf("ERROE: List is smaller than %d \n", position);
    return;
}
// ShiamSharif_0032.
// print_linked_list.
void traverse()
{
    if (start == NULL)
    {
        printf("\nEmpty list.");
        return;
    }
    printf("\n");
    herbs *temp = start;
    while (temp != NULL)
    {
        printf("%d ", temp->ginger);
        printf("%d ", temp->garlic);
        printf("\t");
        temp = temp->next;
    }
    printf("\n");
}
// ShiamSharif_0032.
// main_function.
int main()
{
    int option, n, p, looper = 1;
    printf("Enter number of node: ");
    scanf("%d", &n);
    creation(n);
    traverse();
    while (looper)
    {
        printf("Menu\n");
        printf("Enter 1 to insert at given position\n");
        printf("Enter 2 to insert at travarse\n");
        printf("Enter 0 to exit\n\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("clear");
            printf("Enter a Position: ");
            scanf("%d", &p);
            insert_at_intermediate_position(p);
            printf("\n\n");
            break;
        case 2:
            system("clear");
            traverse();
            printf("\n\n");
            break;
        case 0:
            system("clear");
            printf("Thank you for using Linked List.\n");
            looper = 0;
            break;
        default:
            system("clear");
            printf("Error: Wrong option.\n\n");
            break;
        }
    }
    return 0;
}
// ShiamSharif_0032