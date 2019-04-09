#ifndef AVL_H
#define AVL_H

#include <iostream>
#include <cstdlib>
#include <cstdio>  
#include <malloc.h>
#include <fstream>
#include <string>

using namespace std;

template <class K,class D>
class avl;

template <class K,class D>
class Node
{
    private:
        K key;
        D data;
        Node<K,D> * p_children[2];
        int hgt;
    public:
         Node(const K & k,const D & d);
         ~Node();
    friend class avl<K,D>;
};

template <class K,class D>
class avl
{
    private:
        Node<K,D> * root;

    public:
        avl(); 
        virtual ~avl();

        void destructor(Node<K,D> *n);
        bool find(K key);
        bool find(K _key,Node<K,D> **&tmp);
        bool insert(Node<K,D>** n,K key);
        bool insert(K key);
        void remove(Node<K,D>** n,K key);
        bool remove(K key);
        Node<K,D>* Min(Node<K,D> **n);
        int altura(Node<K,D> * n);
        int altura();
        int max(int a,int b);
        void rotar(Node<K,D>** n, bool side);
        bool balance(Node<K,D> **n,bool child);
        bool Delete(Node<K,D> **n, K k);
        
        void printArbol(int num);
    	void printArbol(ofstream & os, Node<K,D> *n);
        
};
#include "avl.inl"
#endif
