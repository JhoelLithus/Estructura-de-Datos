#ifndef REDBLACK_H
#define REDBLACK_H

#include <iostream>
#include <string>

using namespace std;

enum colors: bool {Black = 0, Red = 1};

template <class K,class D>
class redblack;

template <class K,class D>
class Node
{
    private:
        K key;
        D data;
        Node<K,D> * p_children[2];
        colors color;
    public:
         Node(const K & k,const D & d);
         ~Node();
    friend class redblack<K,D>;
};

template <class K,class D>
class redblack
{
    private:
        Node<K,D> * root;

    public:
        kedblach(); 
        virtual ~redblack();
	// Busqueda

        bool find(K _key);
  		bool find(const K & _key, Node<K,D> *temp);
   
};
#include "redblack.inl"
#endif
