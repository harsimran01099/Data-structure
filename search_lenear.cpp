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
bool binarySearch1(int a[],int x,int f,int l)
{   
     int mid=(f+l)/2;
     if(a[mid]==x)
    {
    	cout<<mid;
    	return true;
	}
	 else if(a[mid]<x)
		{
			binarySearch1(a,x,mid+1,l);
		}
	else
		 binarySearch1(a,x,f,mid-1);
		
	
	return false;
}
bool binarySearch2(int a[],int x,int f,int l)
{   
    
	 while(f<=l)
	 {
     int mid=(f+l)/2;
     if(a[mid]==x)
      {
    	cout<<mid;
    	return true;
	  }	
	  else if (a[mid]<x)
	  {
	  	f=mid+1;
	  }
	  else 
	   l=mid-1;
	  
	 }
		
	
	return false;
}
int main()
{
	int a[]={1,2,3,8,25,26,56,89,785,6522};
	int x;
	cin>>x;
	lenearSearch(a,x);
	binarySearch1(a,x,0,9);
	binarySearch2(a,x,0,9);
}
