#include <iostream>
#include <math.h>
#include <vector>
#include "Heap.h"

using namespace std;

//const int DEFAULT_SIZE = 1;

/*
int size;
vector <int> list[];
*/

Heap::Heap()
{
	size = 1;
	list.resize(size);
}
Heap::Heap(int Size)
{
	size = Size;
	list.resize(size);
}
void Heap::print()
{
	cout << "[";
	
	for (int i = 0; i < size -1 ; i++)
		cout << list[i] << ",";

	cout << list[size - 1] << "]" << endl;
}

void Heap::MaxHeapify(vector <int> arr, int currentElement, int size)
{
	int largest = currentElement;
	int temp, left, right;
	
	left = 2 * currentElement + 1;
	right = 2 * currentElement + 2;

	if (left < size && arr[left] > arr[largest])
		largest = left;
	else
		largest = currentElement;
	
	if(right < size&& arr[right] > arr[largest])
		largest = right;

	if (largest != currentElement)
	{
		temp = arr[currentElement];
		arr[currentElement] = arr[largest];
		arr[largest] = temp;

		MaxHeapify(arr, largest, size);
	}

}

void Heap::BuildMaxHeap(vector <int> arr, int size)
{
	
	for (int i = floor(size / 2); i >= 0; i--)
		MaxHeapify(arr, i, size);

}

void Heap::sort()
{
	int temp; 
	BuildMaxHeap(list, size);
	for (int i = size - 1; i >= 0; i--)
	{
		temp = list[i];
		list[i] = list[0];
		list[0] = temp;

		MaxHeapify(list, i, size);

	}
}

