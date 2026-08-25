#include<stdio.h>

int fact(int n)
{
    if(n==1)
        return 1;
    return n*fact(n-1);
}

int main()
{
    int n;
    printf("\n Enter any number");
    scanf("%d",&n);
    printf("\n Factorial of %d is %d",n,fact(n));
}