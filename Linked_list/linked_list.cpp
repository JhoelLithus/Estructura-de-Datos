#include <iostream>
#include "linked_list.h"

using namespace std;

int main(){

	linked_list<int> lli;

	lli.insert_front(5);
	lli.insert_front(2);
	lli.insert_front(3);
	lli.insert_front(8);
	lli.insert_front(9);
	
	lli.remove(3);

	for(linked_list<int>::iterator it = lli.begin(); it != lli.end(); ++it)
		cout << *it << ", ";
	cout << endl;
}
