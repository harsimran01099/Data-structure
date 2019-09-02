#include<iostream>
using namespace std;
int a[100];
int front=-1,rear=-1;
bool isEmpty()
{
	if(rear==-1&&front==-1)
	{
		return false;
	}
	return true;
}
void enque(int x)
{   if(rear==99)
    {
    	cout<<"que is full";
    	return;
	
     }      
	else if(isEmpty())
	{
		rear=0;
		front=0;
		
		
	}
	else 
	rear=rear+1;
	a[rear]=x;
		
}
void deque()
{
	if(isEmpty())
	{
		cout<<"quen is empty";
	}
	else if(rear==front)
	{
		rear=-1;
		front=-1;
	}
	else
	front =front +1;
}


int main()
{
	deque();
	enque(2);
	enque(3);
	deque();
}
