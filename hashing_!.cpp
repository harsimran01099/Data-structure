#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int a[1000][2];
bool isPresent(int x)
{
	if(x>=0)
	{
		if(a[x][0]==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		x=abs(x);
		if(a[x][1]==1)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
}
void insert(int b[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(b[i]>=0)
		{
			a[b[i]][0]=1;
		}
		else
		{
			a[abs(b[i])][1]=1;
		}
	}
}
int main() 
{ 
    int a[] = { -1, 9, -5, -8, -5, -2 }; 
    int n = sizeof(a)/sizeof(a[0]); 
    insert(a, n); 
    int X = -5; 
    if (isPresent(X) == true) 
       cout << "Present";  
    else
       cout << "Not Present"; 
    return 0; 
}
