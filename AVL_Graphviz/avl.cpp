#include <iostream>
#include "avl.h"


using namespace std;

int main()
{
	avl<int,int> avl;
	
    for(int i=1;i<15;i++)
	{
        if(avl.insert(i)==true)
		{
            cout<<"Se inserto "<<i<<endl;
            avl.printArbol(i);
        }
	}
	return 0;
}



