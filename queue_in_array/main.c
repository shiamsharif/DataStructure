#include <stdio.h>
#define MAX 6

int rear;
int front;
int Q[MAX];

void enque()
{
    int data;
    if(rear == MAX)
    {
        printf("Liner Queue isFull.\n");
        return;
    }
    else
    {
        printf("Enter a data: ");
        scanf("%d",&data);
        Q[rear] = data;
        rear++;
        printf("Data inserted in the Queue.\n");
    }
}

void deque()
{
    if(rear == front)
    {
        printf("Linear Queue is empty.\n");
        return;
    }
    else
    {
        printf("Deleted element from Queue is %d.\n",Q[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front == rear)
    {
        printf("Queue is Empty.\n");
        return;
    }
    else
    {
        printf("Element of Queue: \n");
        for(i=front; i<rear; i++)
        {
            printf("%d\t",Q[i]);
        }
    }
}

int main()
{
    int option, looper=1;
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
            printf("Thank you for using Queue.\n");
            looper = 0;
            break;
        
        default:
            printf("ERROE: Wrong option.\n");
            break;
        }
    }
    
}