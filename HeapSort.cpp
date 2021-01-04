#include <iostream>
#include <math.h>

using namespace std;

void print(int array[],int arraySize);
void MaxHeapify(int arr[],int i,int size);
void BuildMaxHeap(int arr[],int size);
void HeapSort(int arr[],int size);

int main()
{
  int size=0;
  cout << "Enter a desired size for the array: " ;
  cin >> size;
  int array[size];
  for(int i=0; i < size; i++)
    {
      cout << "Enter the valuse for array slot[" << i << "]: ";
      cin >> array[i];
    }
  HeapSort(array,size);
  print(array,size);
  return 0;
}

void print(int array[],int arraySize)
{
  cout << "{";
  for(int k=0; k<arraySize-1; k++)
    {
      cout << array[k] << ",";
    }
  cout << array[arraySize-1] << "}" << endl;
}

void MaxHeapify(int arr[],int i,int size)
{
  int largest=i;
  int temp,l,r;

  l=2*i+1; //left
  r=2*i+2; //right

  if(l < size && arr[l] > arr[largest])//largest=i
     largest=l;
  else
     largest=i;
 
  if(r < size && arr[r] > arr[largest])
    largest=r;

  if(largest != i)
    {
      temp=arr[i];
      arr[i]=arr[largest];
      arr[largest]=temp;

      MaxHeapify(arr,largest,size);
    }
	  
}

void BuildMaxHeap(int arr[],int size)
{
  for(int i=floor(size/2); i >=0; i--)
    {
      MaxHeapify(arr,i,size);
    }
}

void HeapSort(int arr[],int size)
{
  int temp;
  BuildMaxHeap(arr,size);
  for(int i=size-1; i>=0; i--)
    {
      temp=arr[i];
      arr[i]=arr[0];
      arr[0]=temp;

      MaxHeapify(arr,i,size);
    }

}
