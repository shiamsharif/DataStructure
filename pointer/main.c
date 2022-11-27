#include <stdio.h>

int main()
{
    unsigned int p = 100;
    double *pointer = &p;
    printf("%p \n",pointer);
    p = 4535;
    printf("%lf \n", *pointer);
    
    return 0;
}