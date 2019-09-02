#include<stdio.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* head ;
void insert(int x,int y)
{
	Node* temp =new Node();
	temp->data=x;
	temp->next=0;
	if(y==1)
	{
		temp->next=head;
			head=temp;
			return;
	}
	Node* temp2 =head;
	for(int i=0;i<y-2;i++)
	{
	  temp2=temp2->next;	
	}
	temp->next=temp2->next;
	temp2->next=temp;
	
	

	
}
void deletel(int x)
{
	Node* temp1=head;
	if (x==1)
	{
		head=head->next;
	
	}
	for(int i=0;i<x-2;i++)
	{
		temp1=temp1->next;
	}
	Node* temp2=temp1->next;

	temp1->next=temp2->next;
	return;

}
void printll()
{
	Node* temp=head;
	while(temp!=0)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<"/n";
}
int main()
{
 head=NULL;
 int i;
 insert(5,1);
 insert(3,2);
 insert(4,1);
 insert(5,2);
 	printll();
 	cout<<"enter the index to delete";
 	cin>>i;
     deletel(i);
  	printll();
 
	 	
}
