#include<stdio.h>
#include<conio.h>
struct Node
{
	int data;
	Node *link;
};
void append(struct Node *head_ref,int a)
{
  struct Node* temp=(struct Node*) malloc(sizeof(struct Node));
  struct Node* temp1=head_ref;

  temp->data=a;
  temp->link=NULL;
  if(head_ref->link==NULL)
  {
  	head_ref=temp;
  }
  while(temp1->link !=NULL)
  {
     temp1->link=
	  }	
	head_ref->link=temp; 
	  
}

int main() 
{ 
  /* Start with the empty list */
  struct Node* head = NULL; 
  
  // Insert 6.  So linked list becomes 6->NULL 
  append(head, 6); 
  
 /* // Insert 7 at the beginning. So linked list becomes 7->6->NULL 
  push(&head, 7); 
  
  // Insert 1 at the beginning. So linked list becomes 1->7->6->NULL 
  push(&head, 1); 
  
  // Insert 4 at the end. So linked list becomes 1->7->6->4->NULL 
  append(&head, 4); 
  
  // Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL 
  insertAfter(head->next, 8); 
  
  printf("\n Created Linked list is: "); 
  printList(head); */
  
  return 0; 
}

