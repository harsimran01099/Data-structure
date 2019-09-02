	#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node *next,*pre;
	
};
Node* head ;
Node* getNewNode(int x)
{
	Node *temp =new Node();
	temp->data=x;
	temp->next=0;
	temp->pre=0;
	return temp;	
}
void insertHead(int x)
{ 

   Node* temp =getNewNode(x);
	if(head==0)
	{ 
	 head=temp;
	 return;
		
	}
	temp->next=head;
	head->pre=temp;
	head=temp;
	
	
	
}
printdl()
{
	Node* temp=head;
	while(temp!=0)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}

int main()

{
  insertHead(25);
  insertHead(15);
  printdl();	
}
