#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else 
	return b;
}
int lcs(char *x,char *y,int m,int n)
{

	if(m==0 || n==0)
	{
		return 0;
	}
	if(x[m]==y[n])
	{
		return 1+lcs(x,y,m-1,n-1);
	}
	else
	 return max(lcs(x,y,m-1,n),lcs(x,y,m,n-1));
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
