#include<iostream>
#include<stdlib.h>
#include<stack>
#include<string.h>
using namespace std;
float eval_post(char c[],int n)
{    
    float op1,op2,r;
    stack<float> s;
	for(int i=0;i<n;i++)
	{
	 if(isdigit(c[i]))
	 {
	 	s.push((float)c[i]);
		 }	
	  else if(c[i]=='+')
	   {
	   	op2 =s.top();
	   	s.pop();
	   	op1 =s.top();
	   	s.pop();
	   	r=op1+op2;
	   	s.push(r);
	   }
	   else if(c[i]=='-')
	   {
	    op2 =s.top();
	   	s.pop();
	   	op1 =s.top();
	   	s.pop();	   	
	   	s.push(op1-op2);
	   }
	   else if(c[i]=='*')
	   {
	    op2 =s.top();
	   	s.pop();
	   	op1 =s.top();
	   	s.pop();
	   	s.push(op1*op2);
	   }
	   else if(c[i]=='/')
	   {
	    op2 =s.top();
	   	s.pop();
	   	op1 =s.top();
	   	s.pop();
	   	s.push(op1/op2);
	   }
	}
	return s.top();
}
 int main()
 {
 	char c[]="23+";
 	cout<<eval_post(c,strlen(c));
 
 	
 	
 }
