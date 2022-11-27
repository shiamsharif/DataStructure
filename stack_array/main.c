#include <stdio.h>
#include <stdlib.h>
#define MAX 6


int stack[MAX];
int top =0;

//push data in stack
void push()
{
    int data;
    if(top == MAX)
    {
        printf("Stack Overflow.\n");
        return ;
    }
    else
    {
        printf("Enter data: ");
        scanf("%d",&data);
        stack[top] = data;
        top = top + 1;
        printf("Data pushed into the stack.👍👍👍\n\n");

    }
}

//pop data is stack
void pop()
{
    if(top ==0)
    {
        printf("Stack Underflow.\n");
        return;
    }
    else
    {
        printf("Popped element is : %d\n\n",stack[--top]);
    }
}

//display stack
void display()
{
    int i;
    if(top == 0)
    {
        printf("Stack empty.\n");
        return;
    }
    else
    {
        printf("Element is stacks: \n");
        for(i=0; i<top; i++)
        {
            printf("\t%d ",stack[i]);
        }
    printf("\n\n");
    }
}
 //main function
 int main()
 {
    int option, looper = 1;
    while (looper)
    {
        printf("\t MENU \t\t \n");
        printf("----------------------\n");
        printf("1.Push. \n");
        printf("2.Pop.\n");
        printf("3.Display.\n");
        printf("4.Quit.\n\n");
        printf("Enter your option: ");
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
            printf("Thank you for using stack! \n");
            looper = 0;
            break;
        default:
            printf("ERROR: Wrong option! \n");
            break;
        }
    }
    
 }