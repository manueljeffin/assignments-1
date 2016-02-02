/*
*
* Square root using Babylonian Method
*
*/

#include <stdio.h>
#include <math.h>

double bmsqrt(int n,int acc)
{
    double x = n, y = 1.0;
    
    double err = 1.0 / pow(10,acc);

    

    while( x - y > err)
    {
        x = (x + y) / 2;
        y = (double) n / x;
    }

    return x;
}

int main()
{
    int n, acc;
    double sqrrt;

    printf("Enter the number: ");
    scanf("%d",&n);

    printf("Enter the precision: ");
    scanf("%d",&acc);

    sqrrt = bmsqrt(n,acc);

    printf("Square root of %d is %lf\n",n,sqrrt);
    return 0;

}
