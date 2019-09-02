#include<iostream>
using namespace std;
int merge(int a[],int n1,int n2,int c[])
{
	int b[n1+n2];
	int i=0,j=0,k=0;
	while(i<n1 && j<n2)
	{
		if(a[i]<c[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=c[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		b[k]=c[j];
		j++;
		k++;
	}
	for(int i=0;i<n1+n2;i++)
	{
		cout<<b[i]<<endl;
	}
	if((n1+n2)%2==0)
	{	
	
	return b[(n1+n2)/2]+b[(n1+n2)/2-1];
      }
     else
	    return  b[(int)((n1+n2)/2)];

}

int main()
{
  int	a[]={10,25,36,45,65,95};
  int 	c[]={11,32,94,105};
  cout<<merge(a,6,4,c);
	
}
