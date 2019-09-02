#include<iostream>
#include<stdio.h>
#include<stdlib.h>

# define Max_Height_TREE 100
using namespace std;

struct MinHeapNode
{
	char data;
	int frequency;
	
	MinHeapNode *left,*right;
	
};

struct MinHeap
{
	unsigned size;
	unsigned capasity;
	
	MinHeapNode **array;
	
	
};
 
MinHeapNode* NewNode(char data,int frequency)
{
	MinHeapNode *temp =new MinHeapNode();
	temp->data=data;
	temp->frequency=frequency;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
MinHeap* CreateMinHeap(unsigned capacity)
{
	MinHeap *temp=new MinHeap();
	temp->size=0;
	temp->capasity=capacity;
  	temp->array  = (MinHeapNode**)new MinHeapNode[capacity];
  	return temp;
	
}
void swapNodes(MinHeapNode** a,MinHeapNode** b)
{
	MinHeapNode *temp= *a;
      *a=*b;
      *b=temp;
}

void MinHeapfy(MinHeap *minHeap,int idx  )
{
	   int smallest = idx; 
    int left = 2 * idx + 1; 
    int right = 2 * idx + 2; 
  
    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) 
        smallest = left; 
  
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) 
        smallest = right; 
  
    if (smallest != idx) { 
        swapNodes(&minHeap->array[smallest], 
                        &minHeap->array[idx]); 
        MinHeapfy(minHeap, smallest); 
    }
}
int IsOne(MinHeap *minHeap)
{
   if(minHeap->size==1)
      { 
	      return 1;
      }
      return 0;
}
MinHeapNode* extractMinHeap(MinHeap *minHeap)
{
	MinHeapNode *temp=minHeap->array[0];
	minHeap->array[0]=minHeap->array[minHeap->size-1];
	--minHeap->size;
	MinHeapfy(minHeap,0);
	return temp;
}
void InsertMinHeap(MinHeap* minHeap,MinHeapNode *node)
{
	minHeap->size++;
	int i=minHeap->size-1;
	while (i && minHeap->array[(i-1)/2]->frequency > node->frequency)
	{
		minHeap->array[i]=minHeap->array[(i-1)/2];
		i=(i-1)/2;
	}
	minHeap->array[i]=node;
	
}
void BuildHeap(MinHeap *minHeap)
{ 
  
    int n = minHeap->size - 1; 
    int i; 
  
    for (i = (n - 1) / 2; i >= 0; --i) 
        MinHeapfy(minHeap, i); 
}
void printArr(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; ++i) 
        printf("%d", arr[i]); 
  
    printf("\n"); 
} 
  
int isLeaf( MinHeapNode* root) 
  
{ 
  
    return !(root->left) && !(root->right); 
}
 MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) 
{ 
  
    struct MinHeap* minHeap = CreateMinHeap(size); 
  
    for (int i = 0; i < size; ++i) 
        minHeap->array[i] = NewNode(data[i], freq[i]); 
  
    minHeap->size = size; 
    BuildHeap(minHeap); 
  
    return minHeap; 
}

MinHeapNode* createHoffmanTree(char data[],int freq[],int size)
{
   MinHeap *temp=createAndBuildMinHeap(data,freq,size);
   MinHeapNode *left,*right,*top;
   while(!IsOne(temp))
   {
   	left=extractMinHeap(temp);
   	right=extractMinHeap(temp);
   	 top=NewNode('$',left->frequency+right->frequency);
   	 top->left=left;
   	 top->right=right;
   	 InsertMinHeap(temp,top);
	   }	
	   return extractMinHeap(temp);
}
void printCodes(MinHeapNode *root,int arr[],int top)
{
      if (root->left) 
    { 
        arr[top] = 0; 
        printCodes(root->left, arr, top + 1); 
    } 
  
    if (root->right)
	{ 
  
        arr[top] = 1; 
        printCodes(root->right, arr, top + 1); 
    } 
  
  
    if (isLeaf(root))
	{ 
  
        printf("%c: ", root->data); 
        printArr(arr, top); 
    } 
	
}
void HuffmanCodes(char data[], int freq[], int size) 
  
{ 
    struct MinHeapNode* root 
        = createHoffmanTree(data, freq, size); 
  
    int arr[Max_Height_TREE], top = 0; 
  
    printCodes(root, arr, top); 
}
int main() 
{ 
  
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    HuffmanCodes(arr, freq, size); 
  
    return 0; 
}

