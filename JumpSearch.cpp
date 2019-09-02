#include<iostream>
using namespace std;
bool lenearSearch(int a[],int f,int l,int x)
{    
	for(int i=f;i<l;i++)
	{
		if(a[i]==x)
		{    
		    cout<<i;
			return true;
		}
		
	}
	return false;
	
}
bool jumpSearch(int a[],int x,int b)
{
   for(int i=0;i<10;i=i+b)
   {
   	if(a[i]==x)
   	{
   		cout<<i;
   		return true;
	   }
	if (a[i]>x)
	{
	 return lenearSearch(a,i-b,i,x);
	}
	
	}
	return false;	
}
int main()
{
	int a[]={1,2,3,8,25,26,56,89,785,6522};
	int x,b;
	cin>>x;
	cin>>b;
	jumpSearch(a,x,b);
}
