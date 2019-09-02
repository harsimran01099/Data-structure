
// C++ program to rotate an array by 
// d elements 
#include <bits/stdc++.h> 
using namespace std; 
  
/*Function to left Rotate arr[] of  
  size n by 1*/

  
/*Function to left rotate arr[] of size n by d*/
void leftRotate(int arr[], int d, int n) 
{ 
    for (int i = 0; i < n-1-d; i++) 
        {
        	int temp;
        	temp=a[i];
        	a[i]=a[i+d];
        	a[i+d]=temp;
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
    leftRotate(arr, 2, n); 
 
  
    return 0; 
}
