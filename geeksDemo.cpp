#include<iostream>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2,no;
	    cin>>n1>>n2;
	    int hres=1,lres=n1*n2;
	    no=min(n1,n2);
	    for(int i=1;i<=no;i++)
	    {
	        while((n1%i)==0 && (n2%i)==0)
	        {
	           hres=hres*i;
	           n1=n1/i;
	           n2=n2/i;
	        }
	    }
	    cout<<lres/hres<<" "<<hres;
	    cout<<endl;
	}
	return 0;
}
