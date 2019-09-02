#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
int partion(int a[],int l,int h)
{
	int i=l-1;
	int j;
	int piv=a[h];

    for( j=l;j<h;j++ )
    {
    	if(a[j]<piv)
    	{
    		i++;
    		int temp=a[i];
    		a[i]=a[j];
    		a[j]=temp;
		}
	}
	int temp=a[h];
	a[h]=a[i+1];
	a[i+1]=temp;
	
	
	return i+1;
}
void quickSort(int a[],int l,int h)
{

	if(l<h)
	{   
	    	int p;
	    p=partion(a,l,h);
		quickSort(a,l,p-1);
		quickSort(a,p+1,h);
	}
}
int main()
{
	int a[]={84,59,78,458,25,45,87,64,2,31};
	quickSort(a,0,9);
	printArray(a,10);
	
}
