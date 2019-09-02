#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main()
{
	int r1,r2,run=0,b,w=0;
	cin>>r1;
	map<char,int>q;
	cin>>q['s'];
	cin>>q['n'];
	string s;
	cin>>s;
	cin>>r2;
	vector<int> t;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==0 || s[i]==1 || s[i]==2 || s[i]==3 || s[i]==4 || s[i]==5 || s[i]==6)
		{
			run=run+(int)s[i];
			t.push_back(s[i]);
			w=w+1;
		}
		else if(s[i]=='W')
		{
			w=w+1;
			t.push_back(-1);
		}
	}
	
	b=(6*run-w*r2)/(r2-r1);
	int sore=b*r1/6;
	cout<<sore+run<<" ";
	for(int i=0;i<t.size();i++)
	{
		if((b+i)%6==0)
		{
			int temp;
			temp=q['s'];
			q['s']=q['n'];
			q['n']=temp;
		}
		if(t[i]==-1)
		{
			q['s']=0;
		}
		else if(t[i]%2==0)
		{
			q['s']=q['s']+t[i];
		}
		else 
		{
		   	q['s']=q['s']+t[i];
			int temp;
			temp=q['s'];
			q['s']=q['n'];
			q['n']=temp;
		}
	}
	cout<<q['s']<<" "<<q['n'];
	return 0;
	
}
