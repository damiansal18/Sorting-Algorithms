#include <iostream>
#include "Heap.h"

using namespace std;

int main()
{
	int dsize = 0;
	
	cout << "Enter the size of the heap you want to be sort!" << endl;
	cout << "You will manually input all the values." << endl;
	cout << "Desired size: ";
	cin >> dsize;

	Heap newHeap(dsize);

	for (int i = 0; i < dsize; i++)
	{
		cout << "Enter the value for heap slot [" << i + 1 << "] : ";
		cin >> newHeap.list[i];
	}
	cout << "Printing Heap before sorting:" << endl;
	newHeap.print();
	
	newHeap.sort();
	
	cout << "Printing Heap after sorting:" << endl;
	newHeap.print();



}