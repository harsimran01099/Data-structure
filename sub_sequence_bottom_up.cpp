#include<bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	return b;
}
int lcs(char *a,char *b,int m, int n)
{
	int l[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
		   if(i==0 || j==0)
		   {
		   	l[i][j]=0;
			   }
			   else if(a[i]==b[j])
			   {
			   	l[i][j]=1+l[i-1][j-1];
				   }
				else 
				  l[i][j]=max(l[i-1][j],l[i][j-1]);	
		}
	}
	return l[m][n];
}
int main() 
{ 
  char X[] = "AGGTAB"; 
  char Y[] = "GXTXAYB"; 
  
  int m = strlen(X); 
  int n = strlen(Y); 
  
  printf("Length of LCS is %d", lcs( X, Y, m, n ) ); 
  
  return 0; 
}