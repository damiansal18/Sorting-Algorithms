#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class Heap
{

public:
	int size;
	vector <int> list;
	
	Heap();
	Heap(int );

	void print();
	void sort();
	void MaxHeapify(vector <int> arr,int currentElement,int arrSize);
	void BuildMaxHeap(vector <int> arr, int arrSize);




};