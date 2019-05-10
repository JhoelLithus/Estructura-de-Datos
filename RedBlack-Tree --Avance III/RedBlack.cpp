#include "RedBlack.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    redblack<int, int> rb;
    int iSecret, jSecret;

    for(int i=1;i<10;i++)
	{ 
        rb(i) = i;
    }
    
    rb.print_arbol(20);
    return 0;
}

