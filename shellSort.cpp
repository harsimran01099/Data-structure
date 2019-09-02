#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
void shellSort(int a[],int n)
{   
	for(int gap=n/2;gap>0;gap=gap/2)
	{
		for(int i=0;i<(n/gap);i=i+1)
		{
			for(int j=i;j<n;j=j+gap)
			{
			  int x=a[j],k=j-gap;
			  while(k>=i && x<a[k])
			  {
			  	a[k+gap]=a[k];
			  	  k=k-gap;
				  }	
				a[k+gap]=x;  
			}
		}
	}
}
int main()
{
	int a[]={84,59,78,458,25,45,87,64,2,31};
    shellSort(a,10);
    printArray(a,10);
	
	
	
}
