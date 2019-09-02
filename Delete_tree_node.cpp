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
BstNode* delete1(BstNode* root,int data)
{
	if(root==0)
	{
		return root;
	}
	else if(data<root->data)
	{
	  root->left=delete1(root->left,data);
	}
	else if(data>root->data)
	{
		root->right=delete1(root->right,data);
	}
	else
	{
		if ((root->left==0)&&(root->right==0))
		{
			delete root;
			root=0;
			return root;
		}
		else if(root->left==0)
		{
			BstNode* temp=root;
			root=root->right;
			delete temp;
			return root;
		}
		else if(root->right==0)
		{
			BstNode* temp=root;
			root=root->left;
			delete temp;
			return root;
		}
		else
		{
			BstNode* temp=findMin(root->right);
			root->data=temp->data;
			delete1(root->right,temp->data);
		}
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
    root=delete1(root,1);
    root=delete1(root,7);
    root=delete1(root,15);
    
  
}
