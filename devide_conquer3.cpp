#include<iostream>
using namespace std;
int count(int a[],int n)
{
	int count=0;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				count++;
			}
		}
	}
}
int main()
{
	int a[]={20,54,1,58,654,87,57,3,16,46};
	cout<<count(a,10);
}
