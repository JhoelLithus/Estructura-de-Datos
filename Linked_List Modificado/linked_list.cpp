#include <iostream>
#include "linked_list.h"
#include <ctime>
#include <cstdlib>

#include <list>
using namespace std;


	int mk_random(int min, int max)
	{
		return min + rand() % max;
	}

int main()
{
	srand(time(NULL));
	linked_list<int> lli;
	list <int> slli;	

	int iter=0;
	
	do 
	{
		system("cls");
		std::cout << "Seleccione su numero de iteraciones: ";
		std::cin >> iter;
		if (iter > 1000 || iter < 1) continue;
	}
	while (iter == 0);

	for (int i = 0; i < iter; ++i)
	{
		int option = mk_random(1, 3);
		std::cout << "option: " << option << "\n";
		switch (option)
		{
				case 1:
				{
				
					lli.insert_front(1);
					lli.insert_front(6);
					lli.insert_front(7);
					lli.insert_front(8);
					lli.insert_front(3);
					lli.insert_front(4);
					
					slli.push_back(1);
					slli.push_back(6);
					slli.push_back(7);
					slli.push_back(8);
					slli.push_back(3);
					slli.push_back(4);

				} break;
				case 2:
				{
					lli.remove(5);
					lli.remove(10);
					lli.remove(1);
					
					slli.remove(5);
					slli.remove(10);
					slli.remove(1);
				} break;
				case 3:
				{
					lli.insert_back(2);
					lli.insert_back(5);
					lli.insert_back(9);
					lli.insert_back(10);
					lli.insert_back(12);
					lli.insert_back(11);
					
					slli.push_back(2);
					slli.push_back(5);
					slli.push_back(9);
					slli.push_back(10);
					slli.push_back(12);
					slli.push_back(11);
				} break;
		}
	}
	cout<<endl<<"MY linked_list : "<<endl;
	for(list<int>::iterator it= slli.begin(); it !=slli.end(); ++it)
		cout<< *it<< "->";
	cout<<endl;
	cout<<endl<<"SYSTEM linked_list : "<<endl;
	for(linked_list<int>::iterator it= lli.begin(); it !=lli.end(); ++it)
		cout<< *it<< "->";
	cout<<endl;
	
	
	return 0;
	
	
}



// TESTING
/*
int main()
{
	linked_list <int> link;
	list <int> slink;
	
	for(int i=0; i<10; i++)
	{
		slink.push_front(i);
		link.insert_front(i);
	}
	
	for(list<int>::iterator it= slink.begin(); it !=slink.end(); ++it)
		cout<< *it<< "->";
	cout<<endl;
	
	for(linked_list<int>::iterator it= link.begin(); it !=link.end(); ++it)
		cout<< *it<< "->";
	cout<<endl;
	
	return 0;
}

*/
