#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include<iostream>
#include<math.h>

class binaryheap
{
private:
	int size;
	int *data;
	int cap_max;
	static const int delta_cap=10;

public:
	binaryheap();
	binaryheap(const binaryheap & b); //construcctor copia
	virtual ~binaryheap(); //destructor .-> libera la memoria
	void delete_max();
	void reserve(int p_cap); //
  	void up(int i);
  	void dow(int i);
  	void swap(int &a, int &b);
  	void push(const int & e); // insertar elementos
  	int max();
  	bool test_max_heap(int size);
  	int & operator[](int i);
  	int getMax();
  	void heapify(int A, int n);
  	void heapshort(int A, int n);
};
#endif //
