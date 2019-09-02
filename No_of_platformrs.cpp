#include<iostream>
#include<algorithm>
using namespace std;

int findStations(int arv[],int dep[],int n)
{
	int i=0,j=0;
	int result=0,platform=0;
	sort(dep,dep+n);
	sort(arv,arv+n);
	while(i<n && j<n)
	{
		if(arv[i]<=dep[j])
		{
			i++;
			platform++;
			if(platform>result)
			{
				result=platform;
			}
			
		}
		else
		{
			j++;
			platform--;
		}
	}
	return result;
}
int main() 
{ 
    int arr[] = {900, 940, 950, 1100, 1500, 1800}; 
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << "Minimum Number of Platforms Required = " 
         << findStations(arr, dep, n); 
    return 0; 
}
