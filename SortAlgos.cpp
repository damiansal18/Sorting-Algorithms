#include <iostream>
#include <math.h>
using namespace std;

void print(int array[],int length);
void selectionSort(int array[],int length);
void bubbleSort(int array[],int length);
void insertionSort(int array[],int length);
int Partition(int array[], int p, int r);
void QuickSort(int array[],int p, int r);
void Merge(int array[],int p, int q, int r);
void MergeSort(int array[], int p, int r);

int main()
{
  int size=0;
  
  //SELECTION SORT
  cout << "Enter desired size of the array: " ;
  cin >> size;
  int array[size];
  for(int i=0; i<size; i++)
    {
      cout << "Enter integer array slot[" << i << "]: ";
      cin >> array[i];
    }
   selectionSort(array,size);
   cout << "Array has been sorted using Selection Sort..." << endl;
   print(array,size);

   //BUBBLE SORT
  cout << "Enter desired size of the array: " ;
  cin >> size;
  int array1[size];
  for(int i=0; i<size; i++)
    {
      cout << "Enter integer array slot[" << i << "]: ";
      cin >> array1[i];
    }
  bubbleSort(array1,size);
  cout << "Array has been sorted using Bubble Sort..." << endl;
  print(array1,size);

  //INSERTION SORT
  cout << "Enter desired size of the array: " ;
  cin >> size;
  int array2[size];
  for(int i=0; i<size; i++)
    {
      cout << "Enter integer array slot[" << i << "]: ";
      cin >> array2[i];
    }
  insertionSort(array2,size);
  cout << "Array has been sorted using Insertion Sort..." << endl;
  print(array2,size);

  //QUICKSORT
  cout << "Enter desired size of the array: " ;
  cin >> size;
  int array3[size];
  for(int i=0; i<size; i++)
    {
      cout << "Enter integer array slot[" << i << "]: ";
      cin >> array3[i];
    }
  QuickSort(array3,0,size-1);
  cout << "Array has been sorted using Quick Sort..." << endl;
  print(array3,size);
  
  //MERGESORT
  cout << "Enter desired size of the array: " ;
  cin >> size;
  int array4[size];
  for(int i=0; i<size; i++)
    {
      cout << "Enter integer array slot[" << i << "]: ";
      cin >> array4[i];
    }
  MergeSort(array4,0,size-1);
  cout << "Array has been sorted using Merge Sort..." << endl;
  print(array4,size);



  return 0;
}

void print(int array[],int length)
{
  cout << "{";
  for(int k=0; k<length-1; k++)
    {
      cout << array[k] << ",";
    }
  cout << array[length-1] << "}" << endl;
}

void selectionSort(int array[],int length)
{
  int temp=0;
  for(int i=0; i<length-1; i++)
    {
      int smallest=i;
      for(int j=i+1; j<length; j++)
	{
	  if(array[j] < array[smallest]) //if the next slot is smaller
	    smallest = j;            //next slot is now the smallest
	}                         
      temp=array[i];                //store a[i] in temp 
      array[i]=array[smallest];     //put the smallest value in a[i]
      array[smallest]=temp;         //a[i]value now in  a[smallest]
    }
}

void bubbleSort(int array[],int length)
{
  int temp;
  for (int i=0;i<length-1; i++)
    {
      for(int j=i+1; j<length; j++)
	{
	  if(array[i]>array[j])
	    {
	      temp=array[i];
	      array[i]=array[j];
	      array[j]=temp;
	    }
	}
    }
}

void insertionSort(int array[],int length)
{
  int index;
  int value;
  for(int i=1; i<length; i++)//i=1 the first elemnt is start of sorted subarray
    {
      value=array[i];
      index=i;
      while(index>0 && array[index-1]>value)
	{
	  array[index]=array[index-1];
	  index--;
	}
      array[index]=value;
    }
}

int Partition(int array[], int p, int r)
{
   int pivot ,pIndex ,temp;
  pivot=array[r];
  pIndex=p;
  for(int j=p; j<=r-1;j++)
    {
      if(array[j]<=pivot) //if value is less than pivot
	{
	  temp=array[pIndex];   
	  array[pIndex]=array[j];
	  array[j]=temp;

	  pIndex++;
	}

    }
  temp=array[pIndex];  
  array[pIndex]=array[r];
  array[r]=temp;

  return pIndex;
}

void QuickSort(int array[],int p,int r) //p=0 and r=length-1 
{
  int q=0;
  if(p<r)
    {
      q=Partition(array,p,r);  //q = pivot index
      QuickSort(array,p,q-1);      //sort partition left of pivot 
      QuickSort(array,q+1,r);      //sort partition right of pivot
    }
}

void Merge(int array[],int p, int q, int r)
{
 
  int L[q-p+1];
  int i=p,j=q+1,k=0; 

  while(i <= q && j <= r)
    {
      if(array[i] < array[j])
	{
	  L[k]=array[i];
	  i++;
	  k++;
	}
      else
	{
	  L[k]=array[j];
	  j++;
	  k++;
	}
    }
 

  while(i <= q) //q=mid
    {
      L[k]=array[i];
      i++;
      k++;
    }
  while(j <= r) //r=high
    {
      L[k]=array[j];
      j++;
      k++;
    }

  for(i=p; i <= r; i++)
    {
      array[i]=L[i-p];
    }
}

void MergeSort(int array[], int p, int r)
{
  if(p<r)
    {
      int q=floor((p+r)/2);
      MergeSort(array,p,q); // sorts first half
      MergeSort(array,q+1,r);
      Merge(array,p,q,r);
    }
}
