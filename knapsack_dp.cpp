#include<bits/stdc++.h>
using namespace std;
int knapsack_dp(int p[],int cap[],int n,int c)
{
	int table[n+1][c+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<c+1;j++)
		{
			if(i==0 || j==0)
			{
				table[i][j]=0;
			}
			else if(cap[i-1]<=j)
			{
			   table[i][j]=max((p[i-1]+table[i-1][j-cap[i-1]]),table[i-1][j]);	
			}
			else
			{
				
				table[i][j]=table[i-1][j];
			}
		}
	}
	return table[n][c];
}
int main() 
{ 
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d", knapsack_dp( val,wt,n,W)); 
    return 0; 
}
