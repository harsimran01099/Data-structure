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
bool isLes(BstNode* root,int data)
{
	if (root==0)
	{
		return true;
	}
	else if ((root->data >data) && isLes(root->left,data) && isLes(root->right,data))
	{
		return true;
	}
	else false;
}
bool isGrt(BstNode* root,int data)
{
	if (root==0)
	{
		return true;
	}
	else if ((root->data <data) && isGrt(root->left,data) && isGrt(root->right,data))
	{
		return true;
	}
	else false;
}
bool isBST1(BstNode* root)
{
	if(root==0)
	{
		return true;
	}
	if(isLes(root->right,root->data) && isGrt(root->left,root->data) && isBST1(root->left) && isBST1(root->right))
	{
		return true;
	 } 
	 else 
	 return false;
}
bool isBst2(BstNode* root,int max,int min)
{
	if(root==0)
	{
		return true;
	}
	else if((root->data<max)&&(root->data>min)&&isBst2(root->left,root->data,min)&&isBst2(root->right,max,root->data))
	{return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	BstNode *root=0;
	root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);
    cout<<isBST1(root);
    cout<<isBst2(root,255,0);
}
