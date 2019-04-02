#ifndef AVL_H_
#define AVL_H_

#include <iostream>

using namespace std;

template <class K, class D>
class avl;

template <class K, class D>
class node
{
	private:
		K key;
		D dato;
		node<K, D> * p_child[2]; // 0 left, 1 right
	
	public:
		node(const K & _key, const D & _dato): key(_key), dato(_dato)
		{
			p_child[0] = p_child[1] = NULL;
		}
		
		~node() = default;
	
	friend class avl<K, D>;
};

template <class K, class D>
class avl
{
	private:
		node<K, D> * p_root;
	
	public:
		avl(): p_root(NULL) {}
		~avl() 
		{
		}
		find(node<K, D> **& n, const K & key);
		insert(const K & key, const D & dato);
		void print();
};

#include "avl.inl"
#endif
