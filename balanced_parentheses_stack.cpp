#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
bool balance(char c[],int n)
{
  stack<char> s;
  for(int i=0;i<n;i++)
  {
  	if(c[i]=='['||c[i]=='{'||c[i]=='(')
  	   {
  	   	s.push(c[i]);
		 }
	else if(c[i]==']'||c[i]=='}'||c[i]==')')
	{
		if((c[i]==']' &&s.top()=='[') ||(c[i]==')' && s.top()=='(') ||(c[i]=='}' && s.top()=='{') )
		 {
		 	s.pop();
		 }
		 else
		 return false;
		 }	 
	  }
	return s.empty();  	
}
int main()
{
	char c[101];
	cout<<"enter the eqation";
	gets(c);
	cout<<balance(c,strlen(c));
}
