#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
string infix_to_postfix(char c[],int n)
{   
    stack<char> s;
	string res;
	for(int i=0;i<n;i++)
	{
		if (isdigit(c[i]))
		{
			res=res+c[i];
		}
		if(c[i]==')'||c[i]=='('||c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/')
		{
			while(s.empty() && hashigpor(c[i]) &&s.top()=='(')
		}
	}
		
	}

