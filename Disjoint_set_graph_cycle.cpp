#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
using namespace std;
struct Edge
{
	int scr,des;
};
struct Graph
{
	int v,e;
	struct Edge *edge;
};
struct Graph* createGraph(int v,int e)
{
	Graph *graph=new Graph();
	graph->v=v;
	graph->e=e;
	graph->edge=new Edge[e];
	return graph;
} 
int find(int *parent,int i)
{
	if(parent[i]==-1)
	{
		return i ;
	}
	else
	 {
	 	find(parent,parent[i]);
	 }
	
}
void Union(int *parent ,int x,int y)
{
	
    int xset = find(parent, x); 
    int yset = find(parent, y); 
    if(xset!=yset){ 
       parent[xset] = yset; 
    } 
	}
bool isCycle(Graph *graph)
{
	int *parent =new int[graph->v];
	memset(parent,-1,sizeof(int) * graph->v);
	for(int i=0;i<graph->e;i++)
	{
		int x =find(parent,graph->edge[i].scr);
		int y= find(parent,graph->edge[i].des);
		if(x==y)
		{
			return 1;
		}
		else
		{
			Union(parent,x,y);
		}
	}
	return 0;
}
int main()
{
	int v=3,e=2;
	Graph *g=createGraph(v,e);
	g->edge[0].scr = 0; 
    g->edge[0].des = 1; 
  
    // add edge 1-2 
    g->edge[1].scr = 1; 
    g->edge[1].des = 2; 
  
        // add edge 0-2 
    g->edge[2].scr = 0; 
    g->edge[2].des = 2;
    
     if (isCycle(g)) 
        printf( "graph contains cycle" ); 
    else
        printf( "graph doesn't contain cycle" ); 
  
    return 0; 
}
