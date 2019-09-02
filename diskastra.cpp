#include<iostream>
# define V 9
using namespace std;

int minIndex(int dist[V],bool dstSet[V])
{
	int min=INT_MAX,ind;
	for(int i=0;i<V;i++)
	{
		if(dstSet[i] == false && min>dist[i])
		{
			min=dist[i];
			ind=i;
		}
	}
	return ind;
}
void printDistances(int dist[V])
{
	for(int i=0;i<V;i++)
	{
		cout<<0<<"---"<<i<<"   "<<dist[i]<<endl;
	}
}
void diskastera(int graph[V][V],int scr)
{
	int dist[V];
	bool dstSet[V];
	for(int i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		dstSet[i]=false;
	}
	dist[scr]=0;
	for(int i=1;i<V-1;i++)
	{
		int u=minIndex(dist,dstSet);
		dstSet[u]=true;
		for(int j=0;j<V;j++)
		{
			if(graph[u][j]  && dstSet[j] == false && dist[u]+graph[u][j]<dist[j])
			{
				dist[j]=dist[u]+graph[u][j];
			}
		}
		
	}
	printDistances(dist);
}
int main() 
{ 
   /* Let us create the example graph discussed above */
   int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, 
                      {4, 0, 8, 0, 0, 0, 0, 11, 0}, 
                      {0, 8, 0, 7, 0, 4, 0, 0, 2}, 
                      {0, 0, 7, 0, 9, 14, 0, 0, 0}, 
                      {0, 0, 0, 9, 0, 10, 0, 0, 0}, 
                      {0, 0, 4, 14, 10, 0, 2, 0, 0}, 
                      {0, 0, 0, 0, 0, 2, 0, 1, 6}, 
                      {8, 11, 0, 0, 0, 0, 1, 0, 7}, 
                      {0, 0, 2, 0, 0, 0, 6, 7, 0} 
                     }; 
   
    diskastera(graph,0); 
   
    return 0; 
}
