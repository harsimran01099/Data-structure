#include<iostream>
using namespace std;
 
struct Node{
	int data;
	Node *link;
};
Node *top=0;
void push(int x)
{
	Node *temp=new Node();
	temp->data=x;
	temp->link=top;
	top=temp;
	
}
void pop()
{
//	Node *temp=top;
	if(top==0)
	{
		cout<<"list is empty";
		return;
	}
	top=top->link;
	
	
}
bool isEmpty()
{
	if(top==0)
	{
		return true;
	}
	return false;
}
int Top()
{
		if(top==0)
	{
		cout<<"list is empty";
		return 0;
	}
	return top->data;
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
