#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define BUFSIZE 100
#define NUMBER '0'
#define MAXVAL 100

char buf[BUFSIZE];
int bufp=0;
int sp = 0;
double val[MAXVAL];


void ungetch(int);
int getch(void);
int getop(char []);
void push(double);
double pop(void);
void clear(void) ;
void top(void);
double copy(void);

main()
{
    int type;
    double op2;
    char var[MAXVAL];

    while ((type = getop(val)) != EOF)
	{
        switch (type)
		{
			case NUMBER:
				push(atof(val));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else 
					printf("error:zero divisor\n");
				break;
			case '%':
				op2=pop();
				if(op2 != 0.0)
				push((int)pop() % (int)op2);
				else
				printf("error: zero divisro \n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error:unknown command %s\n", val);
		}
	}
return 0;
}


void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, can't push %g\n", f);
}

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else{
        printf("error:stack empty\n");
        return 0.0;
    }
}

void top(void)
{	
	if (sp>0)
	{	sp=sp-1;
		printf("top of stack : %f\n",val[sp]);
		sp=sp+1;
	}
	else
		printf("error: stack empty\n");
	

}

double copy(void)
{	double copy;
	if (sp>0)
	{	sp=sp-1;
		copy=val[sp];
		sp=sp+1;
		return copy;
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	
	}

}

void exchange(void) 
{	
	if (sp>1)
	{	double a;
		int i=sp;
		a=val[i-1];
		val[i-1]=val[i-2];
		val[i-2]=a;
	}
	else
		printf("error: value not enough \n");
	
}

void clear(void) 
{	
	if (sp>0)
		for(sp=sp-1;sp>=0;sp--)
			val[sp]='\0';
	
	else
		printf("error: stack empty\n");
}

int getch(void)
{	return (bufp>0) ? buf[--bufp]:getchar();


}
void ungetch(int c)
{	if(bufp >=BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;

}

int getop(char s[])
{	int i,c;
	while ((s[0]=c=getch())==' '||c=='\t')
		;
	s[1]='\0';
	if(!isdigit(c)&&c!='.')
		return c;
	i=0;
	if(isdigit(c))
		while(isdigit(s[++i]=c=getch()))
			;
	s[i]='\0';
	if(c!= EOF)
		ungetch;
	return NUMBER;


}