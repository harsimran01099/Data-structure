#include<bits/stdc++.h>
using namespace std;
int min(int a,int b,int c)
{
	return min(min(a,b),c);
}
int editDist(string x,string y,int m,int n)
{
	int l[m+1][n+1];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0 )
			{
				l[i][j]=j;
			}
			if(j==0)
			{
				l[i][j]=i;
			}
			else if(x[i-1]==y[j-1])
			{
			  l[i][j]=l[i-1][j-1];	
			}
			else
			 l[i][j]= 1+min(l[i][j-1],l[i-1][j],l[i-1][j-1]);
		}
	}
	return l[m][n];
	
}

int main() 
{ 
    // your code goes here 
    string str1 = "sunday"; 
    string str2 = "saturday"; 
  
    cout << editDist( str1 , str2 , str1.length(), str2.length()); 
  
    return 0; 
}
