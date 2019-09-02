
// C++ program to rotate an array by 
// d elements 
#include <bits/stdc++.h> 
using namespace std; 
  
/*Function to left Rotate arr[] of  
  size n by 1*/

  
/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n) 
{ 
int temp,b[d];
     for (int i = 0; i < d; i++)
	 { 
	  b[i]=arr[i];
	  } 
    for (int i = 0; i < n-d; i++) 
        {
        	int temp;
        	temp=arr[i];
        	arr[i]=arr[i+d];
        	arr[i+d]=temp;
		 } 
		 for (int i =0; i < d; i++) 
		 {
		  arr[n-d+i]=b[i];
		 }
		 
} 

  
/* utility function to print an array */
void printArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
  
/* Driver program to test above functions */
int main() 
{ 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    // Function calling 
    leftRotate(arr, 6, n); 
    printArray(arr, n);
 
  
    return 0; 
}
