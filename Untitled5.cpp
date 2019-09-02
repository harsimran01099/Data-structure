#include<iostream>
using namespace std;
bool lenearSearch(int a[],int x)
{
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
	{
		if(a[i]==x)
		{    
		    cout<<i;
			return true;
		}
		
	}
	return false;
	
}
bool ternarySearch(int a[],int x,int f,int l)
{   
     int mid1=(f+l)/3;
     int mid2=2(f+l)/3;
     if(a[mid1]==x) 
    {
    	cout<<mid1;
    	return true;
	}
	  else if(a[mid2]==x) 
    {
    	cout<<mid2;
    	return true;
	}
	 else if(a[mid1]>x)
		{
		 ternarySearch(a,x,l,mid1-1);
		}
	else if (a[mid2]<x)
		 ternarySearch(a,x,mid2+1,l);
    else 
	    ternarySearch(a,x,mid1+11,mid2-1);		 
		
	
	return false;
}

int main()
{
	int a[]={1,2,3,8,25,26,56,89,785,6522};
	int x;
	cin>>x;
    ternarySearch(a,x,0,10);
}
