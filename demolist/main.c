#include <stdio.h>
#include <stdlib.h>

struct node
{
    int ginger;
    int garlic;
    struct node *next;
};
typedef struct node herbs;
//ShiamSharif_0032
herbs *start = NULL;
//node_creation.
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
//ShiamSharif_0032.
//linked_list_creation.
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
//ShiamSharif_0032.
// insertion a node from the first of list.
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
        while (temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp -> next = newnode;
    }
}

//inserting a node in intermediate position.
void insert_at_intermediate_position(int position)
{
    if(position == 0)
    {
        insert_at_first();
        return;
    }
    herbs *newnode;
    herbs *temp;
    newnode = getnode();
    if(start == NULL)
    {
        printf("ERROR: List is empty.\n");
        return;
    }
    int iterator = 1;
    temp = start;
    while(temp != NULL)
    {
        if(iterator == position)
        {
            newnode->next = temp -> next;
            temp->next = newnode;
            return;
        }
        temp = temp -> next;
        iterator += 1;
    }

    printf("ERROR: List is smaller than %d \n",position);
    return;
}//ShiamSharif_0032.
//deleting_at_frist.
void deleting_at_frist()
{
    herbs* temp;
    if(start == NULL)
    {
        printf("ERROR: List is empty.\n");
        return;
    }
    else
    {
        temp = start;
        start = start->next;
        free(temp);
        printf("\n Node Deleting Done.\n");
    }
}
//deleting_at_end.
void deleting_at_end()
{
    herbs* temp;
    herbs* temp2;
    if(start == NULL)
    {
        printf("ERROR: List is empty.\n");
        return;
    }
    else
    {
        temp = temp2 = start;
        while(temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
        printf("\n Node Deleting Done.\n");
    }
}
//deleting_node_from_any_position.
void deleting (int position)
{
    herbs* temp = start;
    herbs* temp2;
    if(start == NULL)
    {
        printf("ERROR: List is empty.\n");
        return;
    }
    int iterator = 1;

    while(temp != NULL)
    {
        temp2 = temp;
        temp = temp -> next;
        if(iterator == position)
        {        
            temp2->next = temp->next;
            free(temp);
            return;
        }
       iterator += 1;
    }

    printf("ERROE: List is smaller than %d \n",position);
    return;
}
//print linked list.
void traverse()
{
    if(start == NULL)
    {
        printf("\nEmpty list.");
        return;
    }
    printf("\n");
    herbs* temp = start;
    while(temp != NULL)
    {
        printf("%d ",temp -> ginger);
        printf("%d ",temp -> garlic);
        printf("\t");
        temp = temp -> next;
    }
    printf("\n");
}
//reverse traverse
void rev_traverse(herbs* start)
{
    if(start == NULL)
    {
        return;
    }
    else
    {
        rev_traverse(start->next);
        printf("%d ",start->next);
    }
}
//main function.
int main()
{
    int option, n, p, looper = 1;
    printf("Enter number of node: ");
    scanf("%d",&n);
    creation(n);
    traverse();
    while(looper) 
    {
        printf("Menu\n");
        printf("Enter 1 to insert at first.\n");
        printf("Enter 2 to insert at end.\n"); 
        printf("Enter 3 to insert at given position.\n");
        printf("Enter 4 to delete at first.\n");
        printf("Enter 5 to delete at end.\n");
        printf("Enter 6 to delete at given position.\n");
        printf("Enter 7 to Print linked list.\n");
        printf("Enter 8 to Print linked list REVERSE.\n");
        printf("Enter 0 to exit\n\n");
        printf("Enter an option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            system("clear");
            insert_at_first();
            printf("\n\n");
            break;
        case 2:
            system("clear");
            insert_at_end();
            printf("\n\n");
            break;
        case 3:
            system("clear");
            printf("Enter a Position: ");
            scanf("%d", &p);
            insert_at_intermediate_position(p);
            printf("\n\n");
            break;
        case 4:
            system("clear");
            deleting_at_frist();
            printf("\n\n");
            break;

        case 5:
            system("clear");
            deleting_at_end();
            printf("\n\n");
            break;    
        case 6:
            system("clear");
            printf("Enter a Position: ");
            scanf("%d", &p);
            deleting(p);
            printf("\n\n");
            break;  
        case 7:
            system("clear");
            traverse();
            printf("\n\n");
            break;
        case 8:
            system("clear");
            rev_traverse(start);
            printf("\n\n");
            break;          
        case 0:
            system("clear");
            printf("Thank you for using Linked List.\n");
            looper = 0;
            break;
        default:
            system("clear");
            printf("Error: Wrong option.\n\n" );
            break;
        }
    }
    return 0;
}
