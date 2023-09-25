// Simple factorial calculator - without error checking

#include <stdio.h>

int main(void)
{
    int n;
    printf("n  = ");
    scanf("%d", &n);

    int fac = 1;
    int i = 1;

loop:
    if (i <= n) {
        fac *= i;
        i++;
        goto loop;
    }

    printf("n! = %d\n", fac);
    return 0;
}
