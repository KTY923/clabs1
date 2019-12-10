#include<stdio.h>
void reverse(char s[])
{	if(s[0]!='\0')
	{	reverse(s+1);
		printf("%c",*s);
	}
}
main()
{
	char s[200]={'\0'};
	printf("ÇëÊäÈëÒ»¸ö×Ö·û´®£º\n");
	gets(s);
	reverse(s);
	printf("\n");

}
	