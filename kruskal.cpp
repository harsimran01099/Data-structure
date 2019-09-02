#include<iostream>
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
using namespace std;
struct Edge
{
	int src,des,weg;
};
struct Graph 
{
	int v,e;
	Edge *edge;
};
Graph* createGraph(int v,int e)
{
	 Graph *g=new Graph();
	 g->v=v;
	 g->e=e;
	 g->edge= new Edge[e];
	 return g;
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
       parent[x] = y; 
	}
bool isCycle(Graph *graph,int j)
{
	int *parent =new int[graph->v];
	memset(parent,-1,sizeof(int) * graph->v);
	for(int i=0;i<graph->e && i<j ;i++)
	{  
		int x =find(parent,graph->edge[i].src);
		int y= find(parent,graph->edge[i].des);
		if(x==y)
		{
			return true;
		}
		else
		{
			Union(parent,x,y);
		}
	}
	return false;
}
int compare(const void *p,const void *q)
{
	Edge *e1=(Edge *)p;
	Edge *e2=(Edge *)q;
	return e1->weg > e2->weg;
}
struct Graph* kruskal(Graph *graph)
{
  Graph *result=createGraph(graph->v,graph->v-1);

  qsort(graph->edge,graph->e,sizeof(graph->edge[0]),compare);
  int j=0;
  for(int i=0;i<graph->e && j<(graph->v)-1;i++)
  {
  	result->edge[j].des=graph->edge[i].des;
  	result->edge[j].src=graph->edge[i].src;
  	result->edge[j].weg=graph->edge[i].weg;
  	 if(!isCycle(result,j+1) )
  	 {
  	 	j++;
	   }
	}
	return result;	
}
int main() 
{ 
    /* Let us create following weighted graph 
             10 
        0--------1 
        |  \     | 
       6|   5\   |15 
        |      \ | 
        2--------3 
            4       */
    int V = 4;  // Number of vertices in graph 
    int E = 5;  // Number of edges in graph 
    struct Graph* graph = createGraph(V, E); 
  
  
    // add edge 0-1 
    graph->edge[0].src = 0; 
    graph->edge[0].des = 1; 
    graph->edge[0].weg = 10; 
  
    // add edge 0-2 
    graph->edge[1].src = 0; 
    graph->edge[1].des = 2; 
    graph->edge[1].weg = 6; 
  
    // add edge 0-3 
    graph->edge[2].src = 0; 
    graph->edge[2].des = 3; 
    graph->edge[2].weg = 5; 
  
    // add edge 1-3 
    graph->edge[3].src = 1; 
    graph->edge[3].des = 3; 
    graph->edge[3].weg = 15; 
  
    // add edge 2-3 
    graph->edge[4].src = 2; 
    graph->edge[4].des = 3; 
    graph->edge[4].weg = 4; 
  
   Graph *g= kruskal(graph); 
   for(int i=0;i<g->e;i++)
   {
   	cout<< g->edge[i].src <<"       "<<g->edge[i].des<<"          " <<g->edge[i].weg<<endl; 
	 }  
    return 0; 
}
