#include<iostream>
using namespace std;
bool binarySearch(int a[],int x,int f,int l)
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
bool exponentialSearch(int a[],int x)
{  
   int i=0;
   	if(a[i]==x)
   	{
   		cout<<i;
   		return true;
	   }
	i++;
   while(i<10)
   {
   	if(a[i]==x)
   	{
   		cout<<i;
   		return true;
	   }
	else if (a[i]<x)
	{
	  i=i*2;
	}
	else 
	 return binarySearch(a,x,i/2,i);
	}
	return false;	
}
int main()
{
	int a[]={1,2,3,8,25,26,56,89,785,6522};
	int x,b;
	cin>>x;
	exponentialSearch(a,x);
}
