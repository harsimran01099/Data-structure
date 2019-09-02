#include<iostream>
#include<vector>
using namespace std;
int coins[]={1,2,5,10,20,50,100,200,500,2000};
int n=sizeof(coins)/sizeof(coins[0]);

void find(int num)
{
	vector <int> ans;
	for(int i=n-1;i>=0;i--)
	{
		if(num>=coins[i])
		{
			num=num-coins[i];
			ans.push_back(coins[i]);
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<endl;
	}
 }
 int main()
 {
 	int x=2097;
 	find(x);
 	return 0;
 }
