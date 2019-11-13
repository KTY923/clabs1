# include<stdio.h>
int main (void)
{
    unsigned int m = 1;
    unsigned int n = 0;
    unsigned int x = m-1;
    while (m > 0)
    {
        m++;
    }
    printf("The max value in usigined int = %u\n",m - 1);
    
    do {
        x = x/2;
        n++;
    }
    while (x>0);
    printf ("The unsigned int bit is %d\n",n);
    return 0;
}
    