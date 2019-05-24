#include "Binomial_tree.h"
int main()
{
	bh<int> b;
	
	b.insert(8);
	b.insert(16);
	b.insert(32);
	
	b.getMin();
	
	b.insert(64);
	b.insert(128);

	b.print();
	
	b.printArbol(4);
	return 0;
}
