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
printll()
{
	Node* temp=head;
	while(temp!=0)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	cout<<"/n";
}
void reverse()
{
	Node *nex,*pre,*cur;
	cur=head;
	pre=0;
	while(cur!=0)
	{
		nex=cur->next;
		cur->next=pre;
		pre=cur;
		cur=nex;
	}
	head=pre;
}
int main()
{
 head=NULL;
 insert(5,1);
 insert(3,2);
 insert(4,1);
 insert(5,2);
 	printll();
 	reverse();
 	printll();
	 	
}
