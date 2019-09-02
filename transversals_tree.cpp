#include<iostream>
#include<queue>
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
void levelOrder(BstNode* root)
{ 
 queue<BstNode*> q;
 if(root==0)
 {
 	return;
 }
 q.push(root);
 while(!q.empty())
 { 
    BstNode* current=q.front();
 	cout<<current->data<<",";
 	if(current->left!=0)
 	{
	 
 	 q.push(current->left);
    }
 	if(current->right!=0)
 	{
 		q.push(current->right);
	 }
	 q.pop();
	
 }
	
}
void preOrder(BstNode* root)
{
	if (root==0)
	{
		return;
	}
	cout<<root->data<<" ,";
	if (root->left!=0)
	{
		preOrder(root->left);
	}
	if(root->right!=0)
	{
		preOrder(root->right);
	}
	
}
void inOrder(BstNode* root)
{
	if (root==0)
	{
		return;
	}
	if (root->left!=0)
	{
		preOrder(root->left);
	}
	cout<<root->data<<" ,";
	if(root->right!=0)
	{
		preOrder(root->right);
	}
	
}
void postOrder(BstNode* root)
{
	if (root==0)
	{
		return;
	}
	
	if (root->left!=0)
	{
		preOrder(root->left);
	}
	if(root->right!=0)
	{
		preOrder(root->right);
	}
	cout<<root->data<<" ,";
	
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
    levelOrder(root);
    preOrder(root);
    inOrder(root);
    postOrder(root);
  
}
