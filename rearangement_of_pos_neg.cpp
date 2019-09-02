#include<stdio.h>
#include<conio.h>
#include <bits/stdc++.h> 

using namespace std;
 void swap(int arr[],int i,int j)
   {
 	 int temp=0;
 	temp= arr[i];
 	 arr[i]=arr[j];
 	 arr[j]=temp;
   }
 int partition(int arr[],int l, int h)
 { 
    int i=l;
    int j=h;
    int v=0;
 	while(i<j)
 	 {
 	   while(arr[i]<v)
		{
		   i++;	
		}
		while(arr[j]>v)
		{
		   j--;	
		}
		if(i<j)
		 {
		    swap(arr,i,j);
        	}
	 }
 }

   int main()
   {
   	int a[]={1,3,-25,-13,5,9,65,78,-45,-3,586};
   	 int n=sizeof(a)/sizeof(int);
   	 partition(a,0,n-1);
   	 int b[n-1];
   	 int k=0;
   	 for(int i=0;i<n;i=i+2)
   	   {   
   	 	b[i]=a[k];
   	 	k++;
		}
	    for(int i=1;i<n;i=i+2)
   	   {   
   	 	b[i]=a[k];
   	 	k++;
		}
		for(int i=0;i<n;i=i+1)
   	   {   
   	     cout<<b[i]<<"   ";
		}
			
   }
