#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue* next; //address
};
typedef struct queue node;

int count = 0;
int max;

node* front = NULL;
node* rear = NULL;

//creat new node.
node* getnode()
{
    node* newnode;
    newnode = (node*) malloc(sizeof(node));
    printf("Enter Data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

//insertion
void enque()
{
    if(count==max)
    {
        printf("Queue is full 🥵🥵🥵\n");
        return;
    }
    node* newnode;
    newnode = getnode();
    if(front==NULL)
    {
        front = newnode;
    }
    else
    {
        rear->next = newnode;
    }
    rear = newnode;
    count++;
}

//deleted
void deque()
{
    if(front==NULL)
    {
        printf("Queue is empty 🥺🥺🥺");
        return;
    }
    else
    {
        node* temp = front;
        printf("Deleted element: %d",front->data);
        front = front->next;
        free(temp);
    }
}

//display output
void display()
{
    if(front==NULL)
    {
        printf("Queue is empty 🥺🥺🥺");
        return;
    }
    else
    {
        node* temp = front;
        while (temp!=NULL)
        {
            printf("%d  ",temp->data);
            temp = temp->next;
        }   
    }
    printf("\n");
}

//main function
int main()
{
    int option, looper=1;
    printf("Total emement of Queue: ");
    scanf("%d",&max);
    while(looper)
    {
        printf("\n\n\t MENU \n");
        printf("--------------------\n");
        printf("1.Insert.\n");
        printf("2.Delete.\n");
        printf("3.Display.\n");
        printf("4.Quit.\n");
        printf("--------------------\n\n");
        printf("Enter your option: ");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            enque();
            break;
        case 2:
            deque();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Thank you for using Queue 🥰🥰🥰 \n");
            looper = 0;
            break;
        default:
            printf("ERROE: Wrong option 😒😒😒\n");
            break;
        }
    }
    
}