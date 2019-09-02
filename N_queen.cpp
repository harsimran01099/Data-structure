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

bool isPossible(int s[N][N],int row,int col)
{
	for(int i=0;i<col;i++)
	{
		if(s[row][i])
		return false;
	}
	for(int i=row,j=col;i>=0 && j>=0;i--,j--)
	{
		if(s[i][j])
		return false;
	}
	for(int i=row,j=col;j>=0 && i<N;i++,j--)
	{
	    if(s[i][j])
		return false;	
	}
	return true;
}
bool solveNQUtil(int s[N][N], int col) 
{
	if(col==N)
	{
		return true;
	}
	for(int i=0;i<N;i++)
	{
		
		if(isPossible(s,i,col))
		{
		   s[i][col]=1;
		   if(solveNQUtil(s,col+1))
		   {
		   	return true;
			   }	
			   s[i][col]=0;
		}
	}
	return false;
}
bool solveNQ() 
{ 
    int s[N][N] = { {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0} 
    }; 
  
    if ( solveNQUtil(s, 0) == false ) 
    { 
      printf("Solution does not exist"); 
      return false; 
    } 
  
    printSolution(s); 
    return true; 
} 
int main() 
{ 
    solveNQ(); 
    return 0; 
}
