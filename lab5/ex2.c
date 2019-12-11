#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define BUFSIZE 100
#define NUMBER '0'
#define MAXVAL 100
char buf[BUFSIZE];
int bufp=0;

int getch(void)
{	return (bufp>0) ? buf[--bufp]:getchar();


}
void ungetch(int c)
{	if(bufp >=BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;

}
int getfloat(float *pn)
{	int c,sign,i;
	while(isspace(c=getch()))
		;
	if(!isdigit(c) && c!=EOF && c!='+' && c!='-' && c!='.')
	{	ungetch(c);
		return 0;
	}
	sign=(c=='-')? -1:1;
	if(c=='-'||c=='+')
		c=getch();
	for (*pn=0;isdigit(c);c=getch())
		*pn=10* *pn + (c-'0');
	if(c=='.')
		c=getch();
	for (i=1;isdigit(c);c=getch(),i++)
		*pn=*pn+(float)(c-'0')/(float)(pow(10,i));
	*pn *= sign;
	if(c==' ')
		getfloat(pn+1);
	if(c!=EOF)
		ungetch(c);
	
	return c;

}
main()
	{float a[100]={'\0'};
	int i;
	float sum=0.0;
	float *p;
	p=&a[0];
	getfloat(a);
	for(i=0;a[i]!='\0';i++)
		sum+=a[i];

	printf("%f \n",sum);



}