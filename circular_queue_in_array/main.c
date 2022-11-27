#include <stdio.h>
#define max 6

int arr[max];

int front = 0;
int count = 0;

void enque()
{
    int data;
    if(count>=max)
    {
        printf("Circular queue is full.\n");
        return;
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&data);
        arr[count] = data;
        count++;
    }
}

void deque()
{
    if(front==count)
    {
        printf("Circular queue is empty.\n");
        return;
    }
    else
    {
        printf("deleted element from Queue is %d\n",arr[front]);
        front++;
        count--;
    }
}

void display()
{
    int i;
    if(front == count)
    {
        printf("Queue is Empty.\n");
        return;
    }
    else
    {
        printf("Element of Queue: \n");
        for(i=front; i<count; i++)
        {
            printf("%d\t",arr[i]);
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