#include <iostream>
#include "avl.h"


using namespace std;

int main()
{
	avl<int,int> avl;
	
    for(int i=1;i<10;i++)
	{
        if(avl.insert(i)==true)
		{
            //cout<<"Se inserto "<<i<<endl;
           //avl.printArbol(i);
        }
	}
	avl.printArbol(4);
	
	for(int j=1;j<5;j++)
	{
        if(avl.remove(j)==true)
		{
            //cout<<"Se elimino "<<j<<endl;
            //avl.printArbol(10);
        }
	}
	avl.printArbol(10);
	return 0;
}



