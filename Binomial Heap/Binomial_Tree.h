#ifndef Binomial_Tree
#define Binomial_Tree 

#include<iostream>  
#include<vector>
#include <cstring>
#include <fstream>

using namespace std; 

template<class T,size_t tam=64>
class bh;
  
template<class T>
class bt
{
private:
	T dato;
	vector<bt<T>*>children;
	int cant;
public:
	bt(const T _dato)
	{
		dato=_dato;
	}
	~bt();
	void print(ostream & os)
	{
		os<<"p"<<this<<" [label=\""<<dato<<"\"]"<<endl;
		for(bt<T>*p:children)
		{
			p->print(os);
			os<<"p"<<this<<" -> p"<<p<<endl;
		}
	}
	friend class bh<T>;
};
template<class T,size_t tam>
class bh
{
private:
	bt<T>* trees[tam];
public:
	bh()
	{
		memset(trees,0,sizeof(trees));
	}
	~bh()
	{

	}
	bt<T>* unir(bt<T>* t1,bt<T>* t2)
	{
		if(t1->dato>t2->dato)
		{
			t2->children.push_back(t1);
			return t2;
		}	
		t1->children.push_back(t2);
		return t1;
	}  
	void insert(const T & d)
	{
		insert(new bt<T>(d));
	}
	void insert(bt<T> * b)
	{
		int i = b->children.size();
		if(trees[i]==NULL)
		{
			trees[i]=b;
			return;
		}
		insert(unir(trees[i],b));
		trees[i]=NULL;
	}
  bt<T>* getMin() 
  { 
    bt<T>* t;
    bool c=1;
    for(int i=0;i<tam;i++)
	{
    	if(trees[i])
	  	{
      		if(c)
      			t=trees[i];
      	
        if (trees[i]->dato<t->dato)
        	t=trees[i];
      	c=0;
	  	}
	}
    
    return t;
  } 
  //remove
  void remove()
  {  
    bt<T>* heap,lo,temp,it; 

    temp = getMin(); 
    for (int i = 0; i < tam; ++i)
    {
    	if(!trees[i])
		{
    		trees[i]=temp;
    	}
    	else
    		unir(trees[i],temp);
    }
    delete temp;
  }
	//print
	void print()
	{
		ofstream os("binh.dot");
		os<<"digraph bh{ "<<endl;
		for(int i=0; i<sizeof(trees); i++)
		{
			if(trees[i]) trees[i]->print(os);
		}
		os<<"}"<<endl;
		os.close();
	}
	
	//printArbol
	void printArbol(int num)
	{
	    string num_arch = to_string(num);
	    string ext1 = ".dot";
	    string num_xt1=""+ num_arch +""+ ext1 +"";
	    ofstream os(num_xt1);
	
	    string s = to_string(num);
	    string pt1="dot.exe -Tpng  < ";
	    string pt2=" > ";
	    string pt3=".png";
	    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
	    const char *buffer = rt.c_str();
	
	    os<<"graph {"<<endl;
	    os<<trees->dato<<endl;
	    printArbol(os,trees);
	    os<<"}"<<endl;
	    os.close();
	    system(buffer);
	}
	
	void printArbol(ofstream & os, bt<T> *n)
	{
	    if(n!=NULL)
	    {    
	        if(n->children[0]!=NULL)
			{
	            os<<n->key;
	            os<<"--";
	            os<<n->children[0]->key<<endl;
	            printArbol(os,n->children[0]);
	        }
	        if(n->children[1]!=NULL)
			{
	            os<<n->key;
	            os<<"--";
	            os<<n->children[1]->key<<endl;
	            printArbol(os,n->p_children[1]);
	        }
	    }
	}
		
};
#endif
