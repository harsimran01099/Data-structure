#include<iostream>
#include<limits.h>
#include<stdio.h>
#include<stdlib.h>
# define V 5
using namespace std;

int minKey(int key[],bool mstSet[])
{    
    int min = INT_MAX,ind;
	for(int i=0;i<V;i++)
	{
	  if(mstSet[i]==false && key[i]<min)
	  {
	  	min =key[i];
	  	ind=i;
		  }	
	
	}
	return ind;
}
void printTree(int parent[],int graph[V])
{
	for(int i=1;i<V;i++)
	{   
		cout<<parent[i]<<"    "<<i<<"   "<<graph[i]<<endl;
	}
}
void primsMST(int graph[V][V])
{
	int key[V],parent[V];
	bool mstSet[V];
	for(int i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		mstSet[i]=false;
	}
	key[0]=0;
	parent[0]=-1;

	for(int i=0;i<V-1;i++)
	{   
	   	int u=minKey(key,mstSet);
		mstSet[u]=true;
		for(int j=0;j<V;j++)
		{
			if(graph[u][j] && mstSet[j]==false  && graph[u][j]<key[j])
			{
				key[j]=graph[u][j];
				parent[j]=u;
			}
		}
		
	}
	printTree(parent,key);
}
int main() 
{ 

int graph[V][V] = {{0, 2, 0, 6, 0}, 
                    {2, 0, 3, 8, 5}, 
                    {0, 3, 0, 0, 7}, 
                    {6, 8, 0, 0, 9}, 
                    {0, 5, 7, 9, 0}}; 
  
   
    primsMST(graph); 
  
    return 0; 
}

