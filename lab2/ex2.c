#include<stdio.h>
main()
{	int i,num=0;
	int count=0;
	char s[100]={0};
	
	printf("take a number<99999\n");
	gets(s);
	for(i=0;s[i]!='\0';i++)	
			num=num*10+(s[i]-'0');
	
	while(strlen(s)>5)          
 
	{	
		num=0;
		printf("take a number again:\n"); 
		gets(s);							
		for(i=0;s[i]!='\0';i++)	
			num=num*10+(s[i]-'0');
	}
	
	for(i=0;i<17;i++)					
		if(num&(1<<i))						
			count++;
	printf("%d\n",count);
    return 0;
}
