#include<iostream>
#include <stdio.h> 
#include <stdlib.h>
#include<math.h>
#include<vector>
#include<float.h>
using namespace std;
struct Point
{
	int x;
	int y;
};
int compactorX(const void *p,const void *q )
{
	Point l=*(Point *)p;
	Point r=*(Point *)q;
	return l.x-r.x;
}
int compactorY(const void *p,const void *q )
{
	Point l=*(Point *)p;
	Point r=*(Point *)q;
	return l.y-r.y;
}
float dist(Point p1,Point p2)
{
	return sqrt(((p1.x)-(p2.x))*((p1.x)-(p2.x)) +  ((p1.y)-(p2.y))*((p1.y)-(p2.y)));
}
float bruteForce(Point p[],int n)
{
	float min =FLT_MAX;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(dist(p[i],p[j])<min)
			{
				min = dist(p[i],p[j]);
			}
		}
	}
	return min;
}
float min(float x, float y)  
{  
    return (x < y)? x : y;  
} 
float stripClosest(Point p[],int n,float d)
{   
  float min =d;
  qsort(p,n,sizeof(Point),compactorY);
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n && (p[j].y-p[i].y)<min;j++)
		{
			if(dist(p[j],p[i])<min)
			{
				min= dist(p[j],p[i]);;
	    	}
		}
	}
	return min;
}
float closestUtil(Point p[],int n)
{
	if(n<=3)
	{
		return bruteForce(p,n);
	}
	int mid =n/2;
	Point midPoint=p[mid];
	float dl=closestUtil(p,mid);
	float dr =closestUtil(p+mid,n-mid);
	float d= min(dl,dr);
	int j=0;
	Point strip[n];
	for(int i =0;i<n;i++)
	{
		if(abs(p[i].x-midPoint.x)<d)
		{
			strip[j]=p[i];
			j++;
		}
	}
	return min(d,stripClosest(strip,j,d));
}
int main()
{
	Point p[]={{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
	qsort(p,6,sizeof(Point),compactorX);
	cout<<closestUtil(p,6);
}
