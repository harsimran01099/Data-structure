#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
void heapfy(int a[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[largest])
	{
		largest=l;
	}
	if(r<n && a[r]>a[largest])
	{
		largest=r;
	}
	if(largest != i)
	{
		int temp=a[largest];
		a[largest]=a[i];
		a[i]=temp;
		heapfy(a,n,largest);
	}
}
void heapSort(int a[],int n)
{
	for(int i=(n/2)-1;i>=0;i--)
	{
		heapfy(a,n,i);
	}
	for(int i=n-1;i>0;i--)
	{  
	  int temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		heapfy(a,i,0);
	}
}
int main()
{
	int a[]={84,59,78,458,25,45,87,64,2,31};

    heapSort(a,10);
    printArray(a,10);
	
	
	
}
