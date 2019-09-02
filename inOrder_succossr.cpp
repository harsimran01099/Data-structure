#include<iostream>
using namespace std;
struct BstNode 
{
 int data;
 BstNode *left,*right;	
};
BstNode* getNewNode(int x)
{
	BstNode* temp=new BstNode();
	temp->data=x;
	temp->left=0;
	temp->right=0;
	return temp;
}
BstNode* insert(BstNode* root,int x)
{
	BstNode* newNode=getNewNode(x);
	if(root==0)
	{
		root=newNode;
		
	}
	else if(root->data>x)
	{
	 root->left=insert(root->left,x);	
	}
	else 
	root->right=insert(root->right,x);
	return root;
}
BstNode* search(BstNode* root,int x)
{
	if(root==0)
	{
		return root;
	}
	else if(root->data == x)
	{
		return root;
	}
	else if(root->data < x)
	{
		search(root->right,x);
	}
	else 
	  search(root->left,x);
	  
}
BstNode* findMin(BstNode* root)
{
	if (root==0)
	{
		return root;
	}
	else if(root->left==0)
	{
		return root;
	}
	else 
	 findMin(root->left);
}
BstNode* getSuccessor(BstNode* root,int data)
{
	BstNode* current = search(root,data);
	if(current==0)
	{
		return 0;
	}
	if(current->right!=0)
	{
		return findMin(current->right);
	}
	else
	{
		BstNode* successor=0;
		BstNode* ancector=root;
		while(current!=ancector)
		{
			if(current->data<ancector->data)
			{
				successor=ancector;
				ancector=ancector->left;
				
			}
			else
			{
				ancector=ancector->right;
			}
		}
		return successor;
	}
}
int main()
{
	BstNode *root=0;
	root=insert(root,12);
    root=insert(root,5);
    root=insert(root,15);
    root=insert(root,3);
    root=insert(root,7);
    root=insert(root,13);
    root=insert(root,17);
    root=insert(root,1);
    root=insert(root,9);
}
