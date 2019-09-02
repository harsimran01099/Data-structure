#include<iostream>
#define V 5
using namespace std;
void printSolution(int s[V])
{
	for(int i=0;i<V;i++)
	{
		cout<<s[i]<<"   ";
	}
	cout<<s[0];
	cout<<endl;
	
}
bool isPossible(int i,bool graph[V][V],int s[V],int pos)
{
	if(graph[s[pos-1]][i]==0)
	{
		return false;
	}
	for(int j=0;j<pos;j++)
	{
		if(s[j]==i)
		{
			return false;
		}
	}
	return true;
}
bool hamCycleUtil(bool graph[V][V],int s[], int pos)
{
    if(pos==V)
	{
		if(graph[s[pos-1]][s[0]]==1)
		{
			return true;
		}
	return false;	
	}	
	for(int i=1;i<V;i++)
	{
		if(isPossible(i,graph,s,pos))
		{
			s[pos]=i;
			if(hamCycleUtil(graph,s,pos+1))
			{
				return true;
			}
			s[pos]=-1;
		}
	}
	return false;
}
void hamCycle(bool graph[V][V])
{
	int *s=new int[V];
	for(int i=0;i<V;i++)
	{
		s[i]=-1;
	}
	s[0]=0;
	if(hamCycleUtil(graph,s,1)==false)
	{
		cout<<"the solution does not exists";
		return;
	}
	printSolution(s);
	
}
int main()  
{  
    
    bool graph1[V][V] = {{0, 1, 0, 1, 0},  
                        {1, 0, 1, 1, 1},  
                        {0, 1, 0, 0, 1},  
                        {1, 1, 0, 0, 1},  
                        {0, 1, 1, 1, 0}};  
      
     
    hamCycle(graph1);  
      
   
    bool graph2[V][V] = {{0, 1, 0, 1, 0},  
                         {1, 0, 1, 1, 1},  
                         {0, 1, 0, 0, 1},  
                         {1, 1, 0, 0, 0},  
                         {0, 1, 1, 0, 0}};  

    hamCycle(graph2);  
  
    return 0;  
}  
  
