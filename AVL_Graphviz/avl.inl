template<class K,class D>
Node<K,D>::Node(const K & k,const D & d):key(k),data(d)
{
    hgt=0;
    p_children[1]=NULL;
    p_children[0]=NULL;
}
template<class K,class D>
Node<K,D>::~Node(){}

template<class K,class D>
avl<K,D>::avl()
{
    root=NULL;
}

template<class K,class D>
avl<K,D>::~avl()
{
    destructor(root);
}

template<class K,class D>
bool avl<K,D>::find(K key)
{
    Node<K,D> **aux;
    if(find(key,aux)==true)
	{
        cout<<"elemento "<<key<<" fue encontrado"<<endl;
    }
	else
	{
        cout<<key<<" El elemento no ha podido ser encontrado";
    }
}

template<class K,class D>
bool avl<K,D>::find(K key,Node<K,D> **&tmp)
{
    tmp=&root;
    while(*tmp)
	{
            if((*tmp)->key==key)
                return true;
            tmp=&(*tmp)->p_children[((*tmp)->key<key)];
    }
    return false;
}

template<class K,class D>
bool avl<K,D>::insert (Node<K,D> **n,K key)
{
 if(*n==NULL)
    { 
        *n=new Node<K,D>(key,1); 
        (*n)->key=key; 
        return true;
    }

    if((*n)->key == key)
        return false;

    bool child = (*n)->key < key; 
    if(insert(&(*n)->p_children[child],key))    
        balance(n,child);
}
template<class K,class D> 
bool avl<K,D>::insert(K key) 
{ 
    return insert(&root,key); 
}

template<class K,class D>
bool  avl<K,D>::balance(Node<K,D> **n,bool child)
{
    Node<K,D> * son  = (*n)->p_children[child];
    int f = altura((*n)->p_children[0])-altura((*n)->p_children[1]);
    int c= altura(son->p_children[0])-altura(son->p_children[1]);
        
    if (f == -2 or f==2)
    {
        if (f*c<=0)
		{
            rotar(&(*n)->p_children[child],!child);
        }
        rotar(n,child);
        return false;
    }
    return true;
}



template<class K,class D>
void avl<K,D>::rotar(Node<K,D>** n, bool side)
{
    Node<K,D>* k1; 
    k1=(*n)->p_children[side]; 
    (*n)->p_children[side]=k1->p_children[!side]; 
    k1->p_children[!side]=*n; 
    *n=k1;
    (*n)->hgt=max(altura((*n)->p_children[side]),altura((*n)->p_children[side]))+1; 
    k1->hgt=max(altura(k1->p_children[side]),altura((k1)->p_children[side]))+1;
}

template<class K,class D>
int avl<K,D>::altura(Node<K,D> * n)
{
    int Altura_dere=0;
    int Altura_izq=0;
    if(n==NULL){
        return 0;
    }
	else
	{
        Altura_dere=altura(n->p_children[1]);
        Altura_izq=altura(n->p_children[0]);
        return max(Altura_dere,Altura_izq)+1;
    }
}

template<class K,class D>
int avl<K,D>::max(int a,int b)
{
    if(a<b)
        return b;
    else
        return a;
}
template<class K,class D>
int avl<K,D>::altura()
{
    Node<K,D> *tmp=root;
    return altura(tmp);
}

template<class K,class D>
Node<K,D>* avl<K,D>::Min(Node<K,D> **n)
{
    if(*n == NULL)
        return NULL;
    else if((*n)->p_children[0] == NULL)
        return *n;
    else
        return Min(&(*n)->p_children[0]);
}

template<class K,class D>
bool avl<K,D>::remove(K key)
{
    return Delete(&root, key);
}

template<class K,class D>
bool avl<K,D>::Delete(Node<K,D> **n, K k)
{
    Node<K,D>* temp;
    if (*n == NULL)
        return false;
    if((*n)->key == k)
	{
        if((*n)->p_children[0] && (*n)->p_children[1])
        {  
            temp =Min(&(*n)->p_children[1]);
            (*n)->key = temp->key;
            Delete(&(*n)->p_children[1],(*n)->key);
            
        }
		else
		{
            temp = *n;
            if((*n)->p_children[0] == NULL)
                *n = (*n)->p_children[1];
            else if((*n)->p_children[1]== NULL)
                *n = (*n)->p_children[0];
            delete temp;
        }
        if(*n==NULL)
            return false;
    }
    bool child = (*n)->key < k; 
    if(Delete(&(*n)->p_children[child],k))
        return balance(n,child);
}
template<class K,class D>
void avl<K,D>::destructor(Node<K,D> *n)
{
    if(n)
    {
    destructor(n->p_children[0]);
    destructor(n->p_children[1]);
        delete(n);
    }   
}

template <class K, class D>
void avl<K,D>::printArbol(int num)
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
    os<<root->key<<endl;
    printArbol(os,root);
    os<<"}"<<endl;
    os.close();
    system(buffer);
}

template <class K, class D>
void avl<K,D>::printArbol(ofstream & os, Node<K,D> *n)
{
    if(n!=NULL)
    {    
        if(n->p_children[0]!=NULL)
		{
            os<<n->key;
            os<<"--";
            os<<n->p_children[0]->key<<endl;
            printArbol(os,n->p_children[0]);
        }
        if(n->p_children[1]!=NULL)
		{
            os<<n->key;
            os<<"--";
            os<<n->p_children[1]->key<<endl;
            printArbol(os,n->p_children[1]);
        }
    }
}

