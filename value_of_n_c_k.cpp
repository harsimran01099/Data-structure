#include<bits/stdc++.h>
using namespace std;

int n_c_r(int n,int k)
{
	int table[n+1][k+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=min(i,k);j++)
		{
			if(i==j || j==0)
			{
				table[i][j]=1;
			}
			else
			{
				table[i][j]=table[i-1][j-1]+table[i-1][j];
			}
			
		}
	}
	return table[n][k];
}
int main() 
{ 
    int n = 5, k = 2; 
    cout << "Value of C[" << n << "][" 
         << k << "] is " << n_c_r(n, k); 
}
