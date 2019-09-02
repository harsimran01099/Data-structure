#include<iostream>
#define V 4
using namespace std;

void printSolution(int color[])
{
	for(int i=0;i<V;i++)
	{
		cout<<color[i]<<"   ";
	}
}
bool isPossible(int c,bool graph[V][V],int color[V],int v)
{
	for(int i=0;i<V;i++)
	{
		if(graph[v][i] && c==color[i])
		{
			return false;
		}
		
	}
	return true;
		
}
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v)
{
	if(v==V)
	{
		return true;
	}
	for(int i=1;i<=m;i++)
	{
	
		if(isPossible(i,graph,color,v))
		{  
		   	color[v]=i;
			if(graphColoringUtil(graph,m,color,v+1)==true)
			{
				return true;
			}
			color[v]=0;
		}
		
	}
	return false;
}
void graphColoring(bool graph[V][V],int m)
{
	int color[V];
	for(int i=0;i<V;i++)
	{
		color[i]=0;
	}
	if(graphColoringUtil(graph,m,color,0)==false)
	{
		cout<<"the solution does not exists";
		return;
	}
	printSolution(color);
}
int main() 
{ 
    
    bool graph[V][V] = {{0, 1, 1, 1}, 
        {1, 0, 1, 0}, 
        {1, 1, 0, 1}, 
        {1, 0, 1, 0}, 
    }; 
    int m = 3; // Number of colors 
    graphColoring (graph, m); 
    return 0; 
}
