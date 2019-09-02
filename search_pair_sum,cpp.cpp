#include<iostream> 
using namespace std;

 bool pairInSortedRotated(int arr[],int n,int sum)
  { 
  	int cout=0;
  	int s=0;
 	 for(int i=0;i<n-1;i++)
 	 {
 	 	arr[i]>arr[i++];
 	 	cout++;
	  }
	  int h=cout%n;
	  int k=(h+1)%n;
	  while (h!=k)
	  {
	  	s=arr[h]+arr[k];
	  	if (s==sum)
	  	{   
	  		return true;
		}
		else if(s<sum)
		{   
		
			k=(k+1)%n;
		}
		else 
		{   
		   if(h!=0)
		   {
		   
			h=(h-1)%n;
		   }
		   else
		    h=n-1;
		}
	  }
	  return false;
  }
  
  int main() 
{ 
    int arr[] = {11, 15, 6, 8, 9, 10}; 
    int sum = 102; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    if (pairInSortedRotated(arr, n, sum)) 
        cout << "Array has two elements with sum 16"; 
    else
        cout << "Array doesn't have two elements with sum 16 ";     

  
    return 0; 
} 
