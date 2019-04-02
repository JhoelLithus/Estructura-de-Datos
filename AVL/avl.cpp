#include "avl.h"


int main()
{
	avl<int, char> tree;
	
	tree.insert(10, 'a');
	tree.insert(8, 'b');
	tree.insert(16, 'c');
	tree.insert(2, 'd');
	tree.insert(20, 'e');
	
	return 0;
}
