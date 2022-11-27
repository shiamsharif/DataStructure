#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *below;
};
typedef struct stack item;

int count = 0;
int node;

item *base = NULL;
item *top = NULL;

// create getnode
item *getnode()
{
    item *newnode;
    newnode = (item *)malloc(sizeof(item));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->below = NULL;
    return newnode;
}

// display stack
void display()
{
    item *temp = top;
    if (top == NULL)
    {
        printf("Empty list: ");
        return;
    }
    else
    {
        printf("Stack item: \n");
        while (temp != NULL)
        {
            printf("%d\n", temp->data);
            temp = temp->below;
        }
    }
}

// print reverse
void printreverse(item* node)
{
    if (node == NULL)
    {
        return;
    }
    else
    {
        printreverse(node->below);
        printf("%d\n", node->data);
    }
}

//push data on stack
void push()
{
    if(count == node)
    {
        printf("Stack overflow.🥵\n");
        return;
    }
    else
    {
        item* newnode;
        newnode = getnode();
        if(base == NULL)
        {
            base = newnode;
        }
        else
        {
            newnode->below = top;         
        }
        top = newnode;
        count++;
    }
}

//poped element on stack
void pop()
{
    item* temp;
    if(top == NULL)
    {
        printf("Stack Underflow.🥺\n");
        return;
    }
    else
    {
        printf("\nDeleted item: %d\n",top->data);
        temp = top;
        top = temp->below;
        free(temp);
        count--;
    }
}

int main()
{
    printf("How many item do you want to store?🤨\n");
    scanf("%d",&node);
    int option, looper = 1;
    while(looper)
    {
        printf("\t MENU \t\n");
        printf("-------------------\n");
        printf("1.Push.⬇\n");
        printf("2.Pop.⬆\n");
        printf("3.Display.\n");
        printf("4.Display Reverse.\n");
        printf("0.Quit.\n");
        printf("\nEnter yout option: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            system("clear");
            push();
            break;
        case 2:
            system("clear");
            pop();
            break;
        case 3:
            system("clear");
            display();
            break; 
        case 4:
            system("clear");
            printreverse(top);
            break;            
        case 0:
            system("clear");
            printf("Thank you for using stack! \n");
            looper = 0;
            break;
        default:
            printf("ERROR: Wrong option! \n");
            break;
        }


    }
    return 0;
}