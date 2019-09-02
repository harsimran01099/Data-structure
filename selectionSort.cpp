#include<iostream>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
void selectionSort(int n,int a[])
{
	int temp,min;
	
	for(int i=0;i<n-1;i++)
	{
	  min=a[i];	
	  for(int j=i+1;j<n;j++)
	  {
	  	if(min>a[j])
	  	{   
	  	    min=a[j];
	  		temp=a[i];
	  		a[i]=a[j];
	  		a[j]=temp;
	  		
		  }
	  }
	}
	
	
}
void bubbleSort(int n,int a[])
{
	int temp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
			
		}
	}
}
void insertionSort(int n,int a[])
{

	int i, key, j; 
	for (i = 1; i < n; i++) 
	{ 
		key = a[i]; 
		j = i - 1; 

		/* Move elements of arr[0..i-1], that are 
		greater than key, to one position ahead 
		of their current position */
		while (j >= 0 && a[j] > key) 
		{ 
			a[j + 1] = a[j]; 
			j = j - 1; 
		} 
		a[j + 1] = key; 
	}
}
int main()
{
	int a[]={84,59,78,458,25,45,87,64,2,31};
	//printArray(a,11);
   // selectionSort(11,a);
    
   // bubbleSort(11,a);
   insertionSort(10,a);
    printArray(a,10);
	
	
	
}
