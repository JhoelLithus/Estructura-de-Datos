#include "RedBlack.h"
#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

int main()
{
    redblack<int, int> rb;
    int iSecret, jSecret;
    //srand (time(NULL));

    for(int i=1;i<10;i++)
	{
       
        rb(i) = i;
        //rb.print_arbol(i);
    }
    
    rb.print_arbol(20);


    return 0;
}

/*
int main()
{
    
    redblack<int,int> avl;

    //int iSecret, jSecret;
    //srand (time(NULL));

    for(int i=1;i<30;i++){
        //iSecret = rand() % 30 + 1;
        //redblack.insert(i,1);
        redblack.insert(1,2,1,1,1,1);
            //cout<<"Se inserto "<<iSecret<<endl;
            //avl.print_arbol(iSecret);
    }
    redblack.print_arbol(21);
       

	return 0;
}
*/
