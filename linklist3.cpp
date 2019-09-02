#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};

void insert(Node** head,int x)
{
	Node* temp =new Node();
	temp->data=x;
	temp->next=0;
	if(head!=NULL)
	{
		temp->next=*head;
	}
    *head=temp;
	
}
printll(Node* head)
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
 Node* head ;
 head=NULL;
 cout<<"enter the no of elements to enter";
 int i,n,x;
 cin>>n;
 for(i=0;i<n;i++)
 {
 	cout<<"enter the no to insert ";
 	cin>>x;
 	insert(&head,x);
 	printll(head);
	 }	
}
