#ifndef REDBLACK_H
#define REDBLACK_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>
#include <queue>

using namespace std;

enum colors: bool {BLACK = 0, RED = 1};

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
        redblack(); 
        ~redblack();
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
    
    //Sobrecarga de operadores ()
    D & operator()(const K & _key);
    
    Node<K,D> * min(Node<K,D> **n);
        
    //Print Arbol
    void print_arbol(ofstream & os,Node<K,D> *n);
    void print_arbol(int num);
    
    //Print Color
    void print_color(ofstream & es,Node<K,D> *n);
    
	//Destructor
    void Destructor(Node<K,D> *n);
    
};
#include "RedBlack.inl"
#endif
