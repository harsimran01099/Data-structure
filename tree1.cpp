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
bool search(BstNode* root,int x)
{
	if(root==0)
	{
		return false;
	}
	else if(root->data == x)
	{
		return true;
	}
	else if(root->data < x)
	{
		search(root->right,x);
	}
	else 
	  search(root->left,x);
	  
}
int findMin(BstNode* root)
{
	if (root==0)
	{
		return 0;
	}
	else if(root->left==0)
	{
		return root->data;
	}
	else 
	 findMin(root->left);
}
int findMax(BstNode* root)
{
	if (root==0)
	{
		return 0;
	}
	else if(root->right==0)
	{
		return root->data;
	}
	else 
	 findMax(root->right);
}
int Max(int x,int y)
{
	if(x>y)
	{
		return x;
	}
	else 
	return y;
}
int height(BstNode* root)
{
	int hl,hr;
	if(root==0)
	{
		return -1;
		
	}
	else 
	 {
	  hl=height(root->left);
	  hr=height(root->right);
	  return Max(hl,hr)+1;
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
   cout<< search(root,2)<<"\n";
   cout<< search(root,12)<<endl;
   cout<<findMin(root)<<endl;
   cout<<findMax(root)<<endl;
   cout<<height(root)<<endl;
}
