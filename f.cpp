#include<bits/stdc++.h>
using namespace std;
int gcdExtended(int a, int b, int *x, int *y); 
  
// Function to find modulo inverse of a 
int modInverse(int a, int m) 
{ 
    int x, y; 
     gcdExtended(a, m, &x, &y);  
    int res = (x%m + m) % m; 
    return  res; 
    
} 
  

int gcdExtended(int a, int b, int *x, int *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0, *y = 1; 
        return b; 
    } 
  
    int x1, y1; // To store results of recursive call 
    int gcd = gcdExtended(b%a, a, &x1, &y1); 
  
    // Update x and y using results of recursive 
    // call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
  
    return gcd; 
} 
int main()
{
	int t1;
	cin>>t1;
	while(t1--)
	{
	 int n,m,t;
	 cin>>n>>t>>m;
	 long long int p=1;
	 long long int q=1;
	 for(int i=0;i<t;i++)
	 {
	 	p=p*(n-m-i);
	 	q=q*(n-i);
	 }
	 long long int p1=q-p;
	 	
	 long long int a=q,m1=1000000007;
	 cout<<(p1*modInverse(q,m1))%1000000007;
     }
	return 0;

}
