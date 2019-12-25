#include<stdio.h>
int t=0;
char s1[200]={'\0'};
void reverse(char s[])
{	if(s[0]!='\0')
	{	reverse(s+1);
		*(s1+t++)=*s;
	}
}
main()
{
	char s[200]={'\0'};
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®£º\n");
	gets(s);
	reverse(s);
	puts(s1);

}
	