#include <stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    double min;
    int i;
 
min=atof(argv[1]);
    for (i =1; i < 6; i++)
{
        if ( atof(argv[i])< min)
        {
            min =atof(argv[i]);
        }
}
if (min>atof(argv[i+1]))
min=atof(argv[i+1]);
    printf("%f", min);
}