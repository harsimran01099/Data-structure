#include<bits/stdc++.h>
using namespace std;

int coinChange(int s[],int m,int n)
{
   if(n<0)
   {
   	return 0;
   }
   if(m>=0 && n==0)
   {
   	return 1;
   }
   if(m<=0  && n>=1)
   {
   	return 0;
   }
   return coinChange(s,m-1,n) + coinChange(s,m,n-s[m-1]);
}
int main() 
{ 
    int i, j; 
    int arr[] = {1, 2, 3}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    printf("%d ", coinChange(arr, m, 4)); 
    getchar(); 
    return 0; 
} 
