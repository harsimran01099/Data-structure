#include<bits/stdc++.h>
using namespace std;
int matrixChainMultiplication(int s[],int n)
{
	int table[n][n];
	for(int i=0;i<n;i++)
	{
		table[i][i]=0;
	}
   for(int l=2;l<n;l++)
   {
   	for(int i=1;i<n+1-l;i++)
   	{
   		int j=i+l-1;
   		int min=INT_MAX;
   		for(int k=i;k<j;k++)
   		{
   			if(min>(table[i][k] + table[k+1][j] + s[i-1]*s[k]*s[j]));
   			{
   				min=table[i][k] + table[k+1][j] + s[i-1]*s[k]*s[j];
			   }
		   }
		   table[i][j]=min;
	   }
   }
	return table[1][n-1];
}
int main() 
{ 
    int arr[] = {1, 2, 3, 4}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Minimum number of multiplications is %d ", 
                       matrixChainMultiplication(arr, size)); 
   
    return 0; 
}
