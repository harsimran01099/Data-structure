#include<iostream>
#include<stack>
using namespace std;
struct Node{
	int data;
	Node* next;
};
Node* head ;
void reverse()
{   
  //  Node *temp1=temp;
     Node* temp1=head;
	stack<Node*> s;
	while(temp1!=0)
	{
	  s.push(temp1);
	  temp1=temp1->next; 	
	}
	head->next=0;
	head=s.top();
	s.pop();
	 Node* temp2=head;
	while(!s.empty())
	{
		temp2->next=s.top();
		s.pop();
		temp2=temp2->next;
	}
}
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
