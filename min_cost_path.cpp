#include<bits/stdc++.h>
#define V 3
#define G 3
using namespace std;

int min(int a,int b,int c)
{
	return min(min(a,b),c);
}
int minCost(int cost[V][G],int m,int n)
{
	int result[V][G];
	result[0][0]=cost[0][0];
	for(int i=1;i<G;i++)
	{
		result[0][i]=result[0][i-1]+cost[0][i];
	}
	for(int i=1;i<V;i++)
	{
		result[i][0]=result[i-1][0]+cost[i][0];
	}
	for(int i=1;i<V;i++)
	{
		for(int j=1;j<G;j++)
		{
			result[i][j]=cost[i][j]+min(result[i-1][j-1],result[i][j-1],result[i-1][j]);
		}
	}
	return result[m][n];
}
int main() 
{ 
   int cost[V][G] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
   printf(" %d ", minCost(cost, 2, 2)); 
   return 0; 
}
