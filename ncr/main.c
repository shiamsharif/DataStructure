#include<stdio.h>
float ncr (int n, int r);
void main()
{
int n, r, result;
printf("Enter the value of N and R :");
scanf("%d %d", &n, &r);
result = ncr(n, r);
printf("The NCR value is %.3f", result);
}
float ncr (int n, int r)
{
if(r == 0)
return 1;
else
return(n * 1.0 / r * ncr (n-1, r-1));
}