#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}
int is_operator(char x)
{
	if( x == '*' || x == '/' || x == '+' || x =='-' || x == '%')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
	if(x == '*' || x == '/'|| x == '%')
	{
		return(2);
	}
	else if(x == '+' || x == '-')
	{
		return(1);
	}
	else
	{
		return(0);
	}
}

int main()
{
    char exp[100];
    char *e,*b, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    b = exp;
    while (*b != '\0')
    {
        if (is_operator(*b) == 1 || isalnum(*b)){
            b++;
        }
        else{
            printf("Wrong Expression");
            exit(0);
        }
    }
    while(*e != '\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
    
}
