#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		map <char, int> r;
		for(unsigned int i=0;i<s.length();i++)
		{
			r.insert({s[i],i});
		}
		string q;
		cin>>q;
	    unsigned int a[q.length()];
		for(int i=0;i<q.length();i++)
		{
			a[i]=r[q[i]];
		}
		unsigned int n=q.length();
		sort(a,a+n);
		cout<<endl;
		map<char, int> :: iterator j;
		for(unsigned int i=0;i<n;i++)
		{
			for( j=r.begin();j!=r.end();j++)
			{
				if(j->second==a[i])
				{
					cout<<j->first;
				}
			}
		}
		
		
	}
}
