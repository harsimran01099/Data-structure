#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printArray(float a[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
void bucketSort(float a[],int n)
{
	vector<float> b[n];
	for(int i=0;i<n;i++)
	{
		int b1=n*a[i];
		b[b1].push_back(a[i]);
	
	}
	for(int i=0;i<n;i++)
	{
		sort(b[i].begin(),b[i].end());
	}
	 int index = 0; 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < b[i].size(); j++) 
          a[index++] = b[i][j]; 
	
}
int main()
{
    float a[15]={.12,.25,.02,.48,.96,.26,.89,.54,.754,.954,.005,.36,.462,.364,.254};
    bucketSort(a,15);
    
    printArray(a,15);
	
	
	
}
