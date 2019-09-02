#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node
{
	int data;
	Node *left,*right;
};
Node* newNode(int key)
{
	Node *temp=new Node();
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
}
void getVerticalOrder(Node* root, int hd, map<int, vector<int> > &m)
{
	if(root==NULL)
	{
		return;
	}
	m[hd].push_back(root->data);
	getVerticalOrder(root->left,hd-1,m);
	getVerticalOrder(root->right,hd+1,m);
}
void printVerticalOrder(Node *root)
{
	map<int,vector<int> > m;
	int hd=0;
	getVerticalOrder(root,hd,m);
	map<int,vector<int> > :: iterator itr;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		for(int i=0;i<itr->second.size();i++)
		{
			cout<<itr->second[i]<<"    ";
		}
		cout<<endl;
	}
}
int main() 
{ 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 
    cout << "Vertical order traversal is n"; 
    printVerticalOrder(root); 
    return 0; 
}
