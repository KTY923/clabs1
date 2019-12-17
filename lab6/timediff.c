#include<stdio.h>
main(int argc,char *argv[])
{	int time1[3]={0};
	int time2[3]={0};
	int i,j,y,m1,m2,d1,d2;
	for (i=0,j=0;argv[1][i]!='\0';i++)
		if (argv[1][i]>='0'&&argv[1][i]<='9')
			time1[j]=time1[j]*10+(argv[1][i]-'0');
		else
			j++;
	for (i=0,j=0;argv[2][i]!='\0';i++)
		if (argv[2][i]>='0'&&argv[2][i]<='9')
			time2[j]=time2[j]*10+(argv[2][i]-'0');
		else
			j++;
	//printf("%d,%d\n",time1[2],time2[2]);
	y=365*(time2[0]-time1[0]);
	switch(time1[1])
	{	case 1:
			m1=0;
			break;
		case 2:
			m1=31;
			break;
		case 3:
			m1=59;
			break;
		case 4:
			m1=90;
			break;
		case 5:
			m1=120;
			break;
		case 6:
			m1=151;
			break;
		case 7:
			m1=181;
			break;
		case 8:
			m1=212;
			break;
		case 9:
			m1=243;
			break;
		case 10:
			m1=273;
			break;
		case 11:
			m1=304;
			break;
		case 12:
			m1=334;
			break;
	}
	switch(time2[1])
	{	case 1:
			m2=0;
			break;
		case 2:
			m2=31;
			break;
		case 3:
			m2=59;
			break;
		case 4:
			m2=90;
			break;
		case 5:
			m2=120;
			break;
		case 6:
			m2=151;
			break;
		case 7:
			m2=181;
			break;
		case 8:
			m2=212;
			break;
		case 9:
			m2=243;
			break;
		case 10:
			m2=273;
			break;
		case 11:
			m2=304;
			break;
		case 12:
			m2=334;
			break;
	}
	d1=m1+time1[2];
	d2=m2+time2[2];
	printf("两个日期相差%d天。\n",d2-d1+y+1);



}