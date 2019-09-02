#include<bits/stdc++.h>
#define TABLE_SIZE 13
#define PRIME 5
using namespace std;

class DoubleHashing
{
	int current_size;
	int *hashTable;
public:	
	DoubleHashing()
	{
		hashTable=new int[TABLE_SIZE];
		for(int i=0;i<TABLE_SIZE;i++)
		{
			hashTable[i]=-1;
		}
		current_size=0;
	}
	int hash1(int a)
	{
		return a%TABLE_SIZE;
	}
	int hash2(int a)
	{
		return PRIME-a%PRIME;
	}
	bool isFull()
	{
		if(current_size==TABLE_SIZE)
		{
			return true;
		}
		return false;
	}
	void insert(int a)
	{
		if(isFull())
		{
			cout<<"the table is full";
			return;
		}
		int index1=hash1(a);
		if(hashTable[index1]==-1)
		{
			hashTable[index1]=a;
		}
		else
		{
			int index2=hash2(a);
			int i=1;
			while(1)
			{
              int index=(index1+i*index2)%TABLE_SIZE;
              if(hashTable[index]==-1)
              {
              	hashTable[index]=a;
              	break;
			  }
			  i++;
			  				
			}
		}
	}
	void display()
	{
		for(int i=0;i<TABLE_SIZE;i++)
		{
			if(hashTable[i]!=-1)
			{
				cout<<i<<"     "<<hashTable[i]<<endl;
			}
			else
			   cout<<i<<endl;
		}
	}
};

int main() 
{ 
    int a[] = {19, 27, 36, 10, 64}; 
    int n = sizeof(a)/sizeof(a[0]); 
  
    // inserting keys into hash table 
    DoubleHashing h; 
    for (int i = 0; i < n; i++) 
        h.insert(a[i]); 
  
    // display the hash Table 
    h.display(); 
    return 0; 
}
