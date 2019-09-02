#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
void merge(int a[],int f,int mid,int h)
{
	int nl,nr;
	nl=mid-f+1;
	nr=h-mid;
	int j=0,k=0,w=f;
	int l[nl],r[nr];
	for(int i=0;i<nl;i++)
	{
		l[i]=a[f+i];
	}
	for(int i=0;i<nr;i++)
	{
		r[i]=a[mid+1+i];
	}
	while(j<nl && k<nr)
	{
	  if(l[j]<r[k])
	  {
	  	a[w]=l[j];
	  	j++;
	   }
	 else if(l[j]>r[k])
	  {
	  	a[w]=r[k];
	  	k++;
	   }
	   w++;
	   	
	}
    while(j<nl)
    {
    	a[w]=l[j];
    	w++;
    	j++;
	}
	while(k<nr)
	{
	  	a[w]=r[k];
		w++;
		k++;
	
    }


}
void mergeSort(int a[],int f,int h)
{   
  

	if(f<h)
	{
	int mid;
	 mid =(f+h)/2;
	 mergeSort(a,f,mid);
	 mergeSort(a,mid+1,h);
	 merge(a,f,mid,h);	
	}
	
}

int main()
{
	int a[]={84,59,78,458,25,45,87,64,2,31};
	mergeSort(a,0,9);
	printArray(a,10);
	
}
