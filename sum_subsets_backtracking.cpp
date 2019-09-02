#include<iostream>
#include<algorithm>
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
		if(ite+1<=s_size && sum-s[ite]+s[ite+1]<=target_sum)
		{
		subset_sum(s,t,s_size,t_size-1,sum-s[ite],ite+1,target_sum);
	     }
		return;
	}
	else
	{  
	if(ite<=s_size && sum +s[ite]<=target_sum)
	{
		for(int i=ite;i<s_size;i++)
		{
			t[t_size]=s[i];
			subset_sum(s,t,s_size,t_size+1,sum+s[i],i+1,target_sum);
		}
	}
   }
}
int comparator(const void *a,const void *b)
{
	int *a1=(int *)a;
	int *b1=(int *)b;
	return a1>b1;
}
int main()
{
	int sub[]={10, 7, 5, 18, 12, 20, 15};
	int size=7,target_sum=35,total;
	int *vector_tuple=new int[size];
	qsort(sub,7,sizeof(int),&comparator);
	for(int i=0;i<7;i++)
	{
		total=total+sub[i];
	}
	if(sub[0]<=target_sum && total >=target_sum)
	{
	subset_sum(sub, vector_tuple, size, 0, 0, 0, target_sum);
    }
}
