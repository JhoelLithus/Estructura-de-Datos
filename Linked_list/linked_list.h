#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>
using namespace std;


template <class T>
class linked_list;

template <class T>
class node
{
	private:
		T dato;
		node<T> * p_next;
	
	public:
		node(){

		}
		node(const T & d, node<T> * n = NULL){
			dato=d;
			p_next=n;
		}
		virtual ~node(){

		}
		void print();
	
	friend class linked_list<T>;
};

// Class Iterator

template <class T>
class linked_list
{
	private:
		node<T> * p_head;//primero 
		node<T> * p_last;//ultimo
		node<T> * aux;
		node<T> * size;
		node<T> * free;
		int idxfree;
		int freeme;
		
	public:
		linked_list();
		linked_list(const linked_list<T>& copy);
		virtual ~linked_list(){}

		linked_list<T>& operator =(const linked_list<T>& copia);
		void insert_front(const T & d);
		void insert_back(const T & d);
		void remove_front();
		void remove_back();
		void reverse();
		void print();
		void remove(const T & d);
		

		class iterator
		{
			private:
				node<T> * p_current;
			
			public:
				iterator(node<T> * n = NULL): p_current(n) {}
				~iterator() = default;
				
				iterator & operator ++ ()
				{
					p_current = p_current->p_next;
					return *this;
				}
				
				T & operator * ()
				{
					return p_current->dato;
				}
				
				bool operator != (const iterator & it)
				{
					return p_current != it.p_current;
				}	
		};
	
		const iterator begin()
		{
			return {p_head};
		}
		
		const iterator end()
		{
			return {NULL};
		}
		
};
#include "linked_list.inl"
#endif

