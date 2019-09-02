#include<iostream>
using namespace std;

void search(char pat[],char txt[])
{
	for(int i=0;i<18;i++)
	{   
	    int count=0;
		for(int j=i,k=0;j<i+4 && k<4;j++,k++)
		{
			if(txt[j]==pat[k])
			{
				count++;
			}
			
		}
		if(count==4)
		{
			cout<<"the pattern is present at index "<<i<<endl;
		}
	}
}
int main() 
{ 
    char txt[] = "AABAACAADAABAAABAA"; 
    char pat[] = "AABA"; 
    search(pat, txt); 
    return 0; 
}
