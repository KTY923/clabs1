#include <stdio.h>
#include <stdlib.h>
#define MAXOP 100
#define NUMBER '0'
int getop(char[]);
void push(double);
double pop(void); 
double top(void);
extern int sp;
int main()
{ 
	printf("t means print the top factot\n");
	printf("e means exchange the topest two factors\n");
	printf("c means copy the top factor\n");
	printf("d means delete the val\n");
    int type;
    double op2, op0, copy; 
    char s[MAXOP];
    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
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
            if (op2 != 0) 
                push(pop() / op2);
            else
                printf("errer:zero divisor\n");
            break;
        case '%': 
            op2 = pop();
            if (op2 != 0)
                push(((int)pop()) % ((int)op2));
            else
                printf("errer:zero divisor\n");
            break;
        case 't': 
            printf("%.8g\n", top());
            break;
        case 'e': 
            op2 = pop();
            op0 = pop(); 
            push(op2);
            push(op0);
            break;
        case 'c': 
            copy = top();
            push(copy);
            break;
        case 'd': 
            sp = 0;
            break; 
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error:unknow command %s\n", s);
            break;
        }
    }
    return 0;
}
#define MAXVAL 100
int sp = 0;
double val[MAXVAL];
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full,can not push %g\n", f);
}
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else
    {
        printf("error:stack empty\n");
        return 0.0;
    }
}
double top(void)
{
    double result;
    if (sp > 0)
    {
        result = val[--sp];
        ++sp;
        return result;
    }
    else
    {
        printf("error:stack empty\n");
        return 0.0;
    }
}
#include <ctype.h>
int getch(void);
void ungetch(int);
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-') /*dealing with negative numbers*/
        return c;
    if (c == '-')
    {
        if (isdigit(c = getch()))
            s[++i] = c;
        else
        {
            if (c != EOF)
            {
                ungetch(c);
            }
            return '-';
        }
    }
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch:too many characters\n");
    else
        buf[bufp++] = c;
}