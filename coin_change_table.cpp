#include<bits/stdc++.h>
using namespace std;
int coinChange(int s[],int m,int n)
{
	int table[n+1][m];
	int x,y;
	for(int i=0;i<m;i++)
	{
		table[0][i]=1;
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i-s[j]>=0)
			{
				x=table[i-s[j]][j];
			}
			else 
			x=0;
			if(j>=1)
			{
				y=table[i][j-1];
			}
			else 
			y=0;
			table[i][j]=x+y;
		}
		
	}
	return table[n][m-1];
}
int main() 
{ 
    int i, j; 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    printf("%d ", coinChange(arr, m, 4)); 
    getchar(); 
    return 0; 
} 
