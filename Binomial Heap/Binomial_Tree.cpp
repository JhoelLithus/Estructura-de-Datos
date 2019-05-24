#include "Binomial_tree.h"
int main()
{
	bh<int> b;
	
	b.insert(5);
	b.insert(15);
	b.insert(25);
	
	b.getMin();
	
	b.insert(35);
	b.insert(45);

	b.print();
	
	b.printArbol(4);
	return 0;
}
