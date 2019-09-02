// Search an element in sorted and rotated 
// array using single pass of Binary Search 
#include <bits/stdc++.h> 
using namespace std; 


int binarysearch(int arr[], int l, int mid, int key)
{ 
	int m=(l+(mid))/2;
	
	int h=mid;
   	while (l<=h)
        	{ 
        	   if(key==arr[m])
        	     { 
        	     	return m;
			      }
			    else if(key>arr[m])
			      {  
				  
			        l=m+1;
			         return	binarysearch(arr,l,h,key);
			     	
					 }
				else 
				{   
				    h=m-1;
				    return binarysearch(arr,l,h,key);
				}
         	}
         	return -1;
       
}

// Returns index of key in arr[l..h] if 
// key is present, otherwise returns -1 
int search(int arr[], int l, int h, int key) 
{ 
	if (l > h) return -1; 

	int mid = (l+h)/2; 
	if (arr[mid] == key) return mid; 

	/* If arr[l...mid] is sorted */
	if (arr[l] <= arr[mid]) 
	{ 
	  if (key>=arr[l] && key <= arr[mid-1])
	{
	 	/* As this subarray is sorted, we can quickly 
		check if key lies in half or other half */
	       return  binarysearch(arr,l, mid-1,key);
	}
   }    
      /*if the list is not sorted the again devide the
  list into two parts*/
  else
   {  
    search(arr,l,mid-1,key);
    }

	
  /* it is for remaining half of list*/
	search( arr, mid+1, h, key);

} 


// Driver program 
int main() 
{ 
	int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int key = 1; 
	int i = search(arr, 0, n-1, key); 

	if (i != -1) 
	cout << "Index: " << i << endl; 
	else
	cout << "Key not found"; 
} 

