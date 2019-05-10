#include "RedBlack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    redblack<int, int> rb;

    for(int i=1;i<100;i++)
	{
       
        rb(i) = i;
    }
    
    rb.print_arbol(20);
    
    for(int i=1;i<7;i++)
	{
       
        rb.remove(i,1);
    }
    
    rb.print_arbol(21);


    return 0;
}

