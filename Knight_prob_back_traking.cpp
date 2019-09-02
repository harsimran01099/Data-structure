#include<iostream>
#define N 8
using namespace std;

void printSolution(int s[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<s[i][j]<<"  ";
		}
		cout<<endl;
	}
}
bool isPossible(int x,int y,int s[N][N])
{
	if(x>=0 && y>=0  && x<N && y<N && s[x][y]==-1)
	{
		return true;
	}
	return false;
}
bool solveKTUtil(int x, int y, int movei, int s[N][N], int xMove[N], int yMove[N]) 
{
	int x_next,y_next;
	
	if(movei==N*N)
	{   
		return true;
	}
	for(int  k=0;k<N;k++)
	{
		x_next=x+xMove[k];
		y_next=y+yMove[k];
		if(isPossible(x_next,y_next,s))
		{
			s[x_next][y_next]=movei;
			if(solveKTUtil(x_next,y_next,movei+1,s,xMove,yMove)==true)
			{
				return true;
			}
			else
			 s[x_next][y_next]=-1;
		}
	}
	return false;
}
                
bool solveKT()
{
	 int s[N][N];
	 for(int i=0;i<N;i++)
	 {
	 	for(int j=0;j<N;j++)
	 	{
	 		s[i][j]=-1;
		 }
	 }
	 s[0][0]=0;
	 int x[]={ 2, 1, -1, -2, -2, -1, 1, 2 }; 
	 int y[]={ 1, 2, 2, 1, -1, -2, -2, -1 };
	 if(solveKTUtil(0,0,1,s,x,y)==false)
	 {
	 	cout<<"the solution does not exists";
	 	return false;
	 }
	 else
	 {
	     printSolution(s);
	 }
	 return true;
}
int main() 
{ 
    solveKT(); 
    return 0; 
} 
