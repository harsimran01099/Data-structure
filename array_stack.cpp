#include<iostream>
#define Max_size 101
using namespace std;
int A[Max_size],top=-1;
void push(int x)
{
	if(top==Max_size-1)
	{
		cout<<"stack over flow";
		return;
	}
	A[++top]=x;
}
void pop()
{
	if(top==-1)
	{
		cout<<"stack is under flow";
		return;
	}
	top--;
	
}
int Top()
{
	if(top==-1)
	{
		cout<<"stack is empty";
		return 0;
	}
	return A[top];
	
}

bool isEmpty()
{
	if(top==-1)
	{
		return true;
	}
	return false;
}

int main()
{
	push(2);
	push(3);
	push(4);
	pop();
	isEmpty();
	push(2);
	Top();
	push(6);
}


