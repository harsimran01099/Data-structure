#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
using namespace std;
void printArray(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
int compator(const void *p,const void *q)
{
	int l=*( int *)p;
	int r=*(int*)(q);
	if(l&1 && r&1)
	{
		return r-l;
	}
	if(!(l&1)&& !(r&1))
	{
		return l-r;
	}
	if(!(l&1))
	{
		return 1;
	}
	 return -1;
}
int main()
{
	int a[]={10,52,69,87,65,45,25,136,58,42};
	qsort(a,10,sizeof(a[0]),compator);
	 printArray(a,10);
	
}
