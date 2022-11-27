#include <stdio.h>

int factorial(int n)
{
    int i, result=1;
    if(n==0)
    {
        return result;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            result = result*i;
        }
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