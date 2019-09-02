#include<bits/stdc++.h>
using namespace std;
int coinPuzzel(int n,int k)
{
	int table[k+1][n+1],res;
	{
		for(int i=1;i<=k;i++)
		{
			table[i][0]=0;
			table[i][1]=1;
		}
		for(int i=1;i<n+1;i++)
		{
			table[1][i]=i;
		}
		for(int i=2;i<k+1;i++)
		{
			for(int j=2;j<n+1;j++)
			{
			  table[i][j]=INT_MAX;
			  for(int x=1;x<=j;x++)
			  {
			  	res=1+max(table[i-1][x-1],table[i][j-x]);
			  	if(res<table[i][j])
			  	{
			  		table[i][j]=res;
				  }
			  }
			}
		}
	}
	return table[k][n];
}
int main() 
{ 
    int n = 2, k = 36; 
    printf ("nMinimum number of trials in worst case with %d eggs and "
             "%d floors is %d \n", n, k, coinPuzzel(k,n)); 
    return 0; 
} 
