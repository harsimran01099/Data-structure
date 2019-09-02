#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include<algorithm>
using namespace std;

struct job
{
	char data;
	int deadline;
	int profit;
};
bool comparison(job a, job b) 
{ 
     return (a.profit > b.profit); 
}
void jobsequence(job arr[],int n)
{
	bool stajob[n];
	int result[n];
    sort(arr, arr+n, comparison);
	for(int i=0;i<n;i++)
	{
		stajob[i]=false;
	}
	for(int i=0;i<n;i++)
	{
		int temp=arr[i].deadline;
		for(int j=min(n,temp)-1;j>=0;j--)
		{
			if(stajob[j]==false)
			{
				result[j]=i;
				stajob[j]=true;
				break;
			}
		}
	}
	for(int i=0;i<n;i++)
	{   
	if(stajob[i])
		cout<<arr[result[i]].data<<endl;
	}
}

int main() 
{ 
   job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27}, 
                   {'d', 1, 25}, {'e', 3, 15}}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    jobsequence(arr,n);
    return 0;
}
