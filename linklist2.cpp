#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* head ;
void insert(int x)
{
	Node* temp =new Node();
	temp->data=x;
	temp->next=0;
	if(head!=NULL)
	{
		temp->next=head;
	}
	head=temp;
	
}
printll()
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
 head=NULL;
 cout<<"enter the no of elements to enter";
 int i,n,x;
 cin>>n;
 for(i=0;i<n;i++)
 {
 	cout<<"enter the no to insert ";
 	cin>>x;
 	insert(x);
 	printll();
	 }	
}
