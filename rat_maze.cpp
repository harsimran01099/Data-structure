#include<iostream>
#define N 4
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
bool isPossible(int x,int y,int m[N][N])
{
	return (x>=0 && y>=0 && x<N && y<N && m[x][y]==1);
}
bool solveMazeUtil(int m[N][N], int x, int y, int s[N][N]) 
{
   if(x==N-1 && y==N-1)
   {
   	s[x][y]=1;
   	return true;
    }
	if(isPossible(x,y,m)==true)
	{
	 s[x][y]=1;
	 if(solveMazeUtil(m,x+1,y,s)==true)
	   {
	 	return true;
	    }   
	 if(solveMazeUtil(m,x,y+1,s)==true)
	   { 
	      return true;
	   }
	 s[x][y]=0;
	 return false;  
	}	
	return false;
}
bool solveMaze(int m[N][N])
{
	int s[N][N];
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			s[i][j]=0;
		}
	}
	if(solveMazeUtil(m,0,0,s)==false)
	{
	  cout<<"result doesnot exist";	
	}
	
	printSolution(s);
	return true;
	
}

int main() 
{ 
    int maze[N][N] = { { 1, 0, 0, 0 }, 
                       { 1, 1, 0, 1 }, 
                       { 0, 1, 0, 0 }, 
                       { 1, 1, 1, 1 } }; 
  
    solveMaze(maze); 
    return 0; 
}
