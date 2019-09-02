#include<iostream>
using namespace std;

void printSolution(int s[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<s[i]<<"  ";
	}
	cout<<endl;
}
void subset_sum(int s[], int t[],int s_size, int t_size,int sum, int ite,int const target_sum) 
{
	if(sum==target_sum)
	{
		printSolution(t,t_size);
		subset_sum(s,t,s_size,t_size-1,sum-s[ite],ite+1,target_sum);
		return;
	}
	else
	{
		for(int i=ite;i<s_size;i++)
		{
			t[t_size]=s[i];
			subset_sum(s,t,s_size,t_size+1,sum+s[i],i+1,target_sum);
		}
	}
}
int main()
{
	int sub[]={10, 7, 5, 18, 12, 20, 15};
	int size=7,target_sum=35;
	int *vector_tuple=new int[size];
	subset_sum(sub, vector_tuple, size, 0, 0, 0, target_sum);
	
}
