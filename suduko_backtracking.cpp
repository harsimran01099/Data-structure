#include<iostream>
#define N 9
using namespace std;

void printSolution(int s[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<s[i][j]<<"   ";
		}
		cout<<endl;
	}
}
bool rowPossible(int s[N][N],int num,int row)
{
	for(int i=0;i<N;i++)
	{
		if(s[row][i]==num)
		{
			return false;
		}
	}
	return true;
}
bool colPossible(int s[N][N],int num,int col)
{
	for(int i=0;i<N;i++)
	{
		if(s[i][col]==num)
		{
			return false;
		}
	}
	return true;
}
bool boxPossible(int s[N][N],int start_row,int start_col,int num)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(s[start_row+i][start_col+j]==num)
			{
				return false;
			}
		}
	}
	return true;
}
bool findUnassigned(int s[N][N],int &row,int &col)
{
  for( row=0;row<N;row++)
  {
  	for( col=0;col<N;col++)
  	{
  		if(s[row][col]==0)
  		{
		  	return true;
		  }
	  }
	}
	return false;	
}
bool isPossible(int s[N][N],int row,int col,int num)
{
	if(rowPossible(s,num,row) && colPossible(s,num,col) && boxPossible(s,row-row%3,col-col%3,num ) )
	{
		return true;
	}
	return false;
}
bool SolveSudoku(int s[N][N])
{   
  int row,col;
	if(!findUnassigned(s,row,col))
	{   
		return true;
	}
	for(int i=1;i<=N;i++)
	{   
		if(isPossible(s,row,col,i))
		{     
			s[row][col]=i;
			if(SolveSudoku(s))
			{   
				return true;
			}
			s[row][col]=0;
		}
	}
	return false;
}
int main()  
{  
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
    if (SolveSudoku(grid) == true)  
        printSolution(grid);  
    else
        cout << "No solution exists";  
  
    return 0;  
}
