#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
int max(int a[],int n)
{
	int max1=a[0];
	for(int i=1;i<n;i++)
	{
		if(max1<a[i])
		{
			max1=a[i];
		}
	}
	return max1;
}
void countSort(int a[],int n ,int exp)
{ 
  int count[10]={0};
  int output[n];
  for(int i=0;i<n;i++)
  {
  	count[(a[i]/exp)%10]++;
  }
  for(int i=1;i<10;i++)
  {
  	count[i]=count[i]+count[i-1];
  }
  for(int i=n-1; i >=0; i--)
  {
  	output[count[(a[i]/exp)%10]-1]=a[i];
  	count[(a[i]/exp)%10]--;
  }
   for (int i = 0; i<n;i++)  
   {
        a[i] = output[i];
    }
	
}
void radixSort(int a[],int n)
{
	int max1=max(a,n);
    for(int i=1;max1/i>0;i=i*10)
    {
	countSort(a,n,i);
    }
	
}
int main()
{
	int a[]={84,59,78,458,25,45,87,64,2,31};
    radixSort(a,10);
    printArray(a,10);	
}
