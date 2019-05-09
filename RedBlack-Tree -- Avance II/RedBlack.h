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
	// Insert
		
        bool insert(const K & _key, const D & _data);
    	Node<K,D> * insert(const K & _key, const D & _data, Node<K,D> ** n,  Node<K,D> ** p);  	
	// Balancear
	
	void turn_side( Node<K,D> ** n, bool side);
	// Remove
		
    bool remove(const K & key,const D & data);
    Node<K,D> * remove(const K & key,const D & data, Node<K,D> ** n, Node<K,D> ** p);    
	//Color
	
	bool Red(Node<K, D> * n);
    bool Black(Node<K, D> * n);
    
    
    Node<K,D> * min(Node<K,D> **n);
    
};
#include "redblack.inl"
#endif
