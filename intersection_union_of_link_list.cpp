#include<iostream>
#include<map>
using namespace std;

struct Node
{
	int data;
	Node *next;
};
void push(Node** node,int data)
{
	Node *temp=new Node();
	temp->data=data;
	temp->next=*node;
	*node=temp;
}
void storeEle(struct Node* head1, struct Node *head2, 
                    map<int, int> &eleOcc) 
{ 
    struct Node* ptr1 = head1; 
    struct Node* ptr2 = head2; 
  
    // Traverse both lists 
    while (ptr1 != NULL || ptr2 != NULL) 
    { 
        // store element in the map 
        if (ptr1!=NULL) 
        { 
            eleOcc[ptr1->data]++; 
            ptr1=ptr1->next; 
        } 
  
        // store element in the map 
        if (ptr2 != NULL) 
        { 
            eleOcc[ptr2->data]++; 
            ptr2=ptr2->next; 
        } 
    } 
} 
  
/* Function to get union of two linked lists head1 
   and head2 */
struct Node *getUnion(map<int, int> eleOcc) 
{ 
    struct Node *result = NULL; 
    map<int,int> :: iterator it;
  
    // Push all the elements into the resultant list 
    for (it=eleOcc.begin(); it!=eleOcc.end(); it++) 
        push(&result, it->first); 
  
    return result; 
} 
  

struct Node *getIntersection(map<int, int> eleOcc) 
{ 
    struct Node *result = NULL; 
     map<int,int> :: iterator it;
  
     for (it=eleOcc.begin(); it!=eleOcc.end(); it++) 
        if (it->second == 2) 
            push(&result, it->first); 
  
      return result; 
} 
  

void printList(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf ("%d ", node->data); 
        node = node->next; 
    } 
} 
   
void printUnionIntersection(Node *head1, Node *head2) 
{ 
    map<int, int> eleOcc; 
    storeEle(head1, head2, eleOcc); 
  
    Node *intersection_list = getIntersection(eleOcc); 
    Node *union_list = getUnion(eleOcc); 
  
    printf("\nIntersection list is \n"); 
    printList(intersection_list); 
  
    printf("\nUnion list is \n"); 
    printList(union_list); 
} 
  
int main() 
{ 
    /* Start with the empty list */
    struct Node* head1 = NULL; 
    struct Node* head2 = NULL; 
  
    /* create a linked lits 11->10->15->4->20 */
    push(&head1, 1); 
    push(&head1, 2); 
    push(&head1, 3); 
    push(&head1, 4); 
    push(&head1, 5); 
  
    /* create a linked lits 8->4->2->10 */
    push(&head2, 1); 
    push(&head2, 3); 
    push(&head2, 5); 
    push(&head2, 6); 
  
    printf("First list is \n"); 
    printList(head1); 
  
    printf("\nSecond list is \n"); 
    printList(head2); 
  
    printUnionIntersection(head1, head2); 
  
    return 0; 
} 
