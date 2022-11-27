#include <stdio.h>

int factorial(int n)
{
    int result;
    if(n==0)
    {
        return 1;
    }
    else
    {
        result = n * factorial(n-1);
    }
    return result;
}

int main()
{
    int number,fact;
    printf("Please insert a number: ");
    scanf("%d",&number);
    fact = factorial(number);
    printf("\n Factorial of %d is = %d \n\n",number,fact);
    return 0;
}