#include <stdio.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;

void push(int data)
{
    if(top == MAX-1)
    {
        printf("Stack is full.\n");
        return 1;
    }
    top = top +1;
    stack_arr[top] = data;
}

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);

    return 0;
}

//it is works. but we can not see anything because of we can not print any thing.