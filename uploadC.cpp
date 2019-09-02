#include<bits/stdc++.h>
using namespace std;
int main()
{
    unsigned	int n;
	cin>>n;
	int fir[n][2],sec[n][2];
	for(unsigned int i=0;i<n;i++)
	{
		cin>>fir[i][0];
		cin>>fir[i][1];
		cin>>sec[i][0]>>sec[i][2];
	}
	int x,y;
	cin>>x>>y;
	int a[n];
	for(unsigned int i=0;i<n;i++)
	{
	int	dis1=abs(x-fir[i][0])+abs(y-fir[i][1]);
	int	dis2=abs(x-sec[i][0])+abs(y-sec[i][1]);
	int	dis3=abs(x-(fir[i][0]+sec[i][0]))+abs(y-fir[i][1]);
	int	dis4=abs(x-fir[i][0])+abs(y-(fir[i][1]+sec[i][1]));
	a[i]=min(dis1,min(dis2,min(dis3,dis4)));
	}
	for(unsigned int i=0;i<n;i++)
    {
      int min=a[0],k=0;
      for(unsigned int j=1;j<n;j++)
      {
        if(min>a[j])
        {
          min=a[j];
          k=j;
        }
    
      }
         a[k]=INT_MAX;
        cout<<k+1<<" ";
      
    }
}
