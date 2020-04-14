#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
/*****BY Aman Gupta*****/
/*Implementation of infix expression to postfix and evaluation of postfix expression */
/*This code handles brackets and right to left operators also in converting prefix to postfix expression*/
struct st
{
	int top;
	char *data;

}stak;

void create(int n)
{
	stak.top=-1;
	stak.data=(char*)malloc(n*sizeof(char));
}
void push(char x)
{
	stak.data[++stak.top]=x;
}

char pop()
{
	char y=stak.data[stak.top--];
	return y;
}

int outpre(char x)
{
	if(x=='+'||x=='-')
		return 1;
	if(x=='*'||x=='/')
		return 3;
	if(x=='^')
		return 6;
	if(x=='(')
		return 7;
	if(x==')')
		return 0;
	return -1;
}

int inpre(char x)
{
	if(x=='+'||x=='-')
		return 2;
	if(x=='*'||x=='/')
		return 4;
	if(x=='^')
		return 5;
	if(x=='(')
		return 0;
	return -1;
}

void evalpostfix(char x)
{
	int t;
	int x1,x2,res;
	if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
	{
		x1=pop();
		x2=pop();
		switch(x)
		{
			case'+':res=(x2-48)+(x1-48);
					break;
			case'-':res=(x2-48)-(x1-48);		
					break;
			case'*':res=(x2-48)*(x1-48);	
					break;
			case'/':res=(x2-48)/(x1-48);
					break;
			case'^':res=pow((x2-48),(x1-48));
					break;
		}
		push(res+48);
	}
	else
		{
			push(x);
		}

}
int main()
{
	int q;

	
	int i=0;
	int k=0;
	char infixexp[100],postfixexp[100];
	printf("Enter the infix expresion\n");
	scanf("%s",&infixexp);
	strcat(infixexp,")");
	create(strlen(infixexp));
	push('(');
	while(infixexp[i]!='\0')
	{
		char x=infixexp[i];
		if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')')
		{
			if(outpre(x)>inpre(stak.data[stak.top])&&outpre(x!=0))
			push(infixexp[i++]);
			else
			{
				if(outpre(infixexp[i])==0)
				{
					while(inpre(stak.data[stak.top])!=0)
					{
						postfixexp[k++]=pop();
					}
					pop();
					i++;
				}
				else
				{
					while(outpre(infixexp[i])<inpre(stak.data[stak.top]))
						postfixexp[k++]=pop();
					push(infixexp[i++]);
				}
			}
		}
		else
			postfixexp[k++]=infixexp[i++];
		
	}
	postfixexp[k]='\0';
	printf("expresion in postfix form is\n");
	for (int j = 0; j<k; ++j)
	{
		printf("%c",postfixexp[j]);
	}

	for(int x=0;x<k;x++)
	{
		evalpostfix(postfixexp[x]);	
	}
	return 0;
}