
template<class K,class D>
Node<K,D>::Node(const K & k,const D & d):key(k),data(d)
{
    p_children[1]=NULL;
    p_children[0]=NULL;
}
template<class K,class D>
Node<K,D>::~Node()
{
	delete(p_children[0]);
	delete(p_children[1]);
	//color = NULL;
}

template<class K,class D>
redblack<K,D>::redblack()
{
    root=NULL;
}

//Destructor
template<class K,class D>
redblack<K,D>::~redblack()
{
    Destructor(root);
}

//find
template <class K, class D>
bool redblack<K,D>::find(K _key)
{
    Node<K,D> * temp = root;
    if(!temp) return false;
    while(temp)
	{
        if(temp->key == _key) return true;
        temp = temp->p_children[temp->key < _key];
    }
    return false;
}

template <class K, class D>
bool redblack<K,D>::find(const K & _key, Node<K,D> *temp)
{
    temp = root;
    while(temp)
    {
        if( (temp)->key == _key ) return true;
        temp = temp->p_children[ (temp)->key < _key ];
    }
    return false;
}

//insert

template <class K, class D>
bool redblack<K,D>::insert(const K & _key, const D & _data)
{
	insert(_key,_data,& root,NULL);
    return true;
}

template <class K, class D>
Node<K,D> * redblack<K,D>::insert(const K & _key, const D & _data, Node<K,D> ** n,  Node<K,D> ** p)
{
	if(!(*n))
	{
		(*n) = new Node<K,D>(_key,_data);
        (*n)->color = RED;
		root->color = BLACK;
        return (*n);
	}
	if((*n)->key == _key)
		return NULL;
	
	int idx_children = ((*n)->key < _key);		//idx_children -> Direccion del Nodo Hijo
    Node <K,D> *children = insert(_key,_data,&(*n)->p_children[idx_children],n);
    if(!children) return (*n);
    if(!p) return NULL;
        
    if(Red(children) && Red(*n))
	{
        int idx_parent = ((*p)->p_children[1] == (*n));
        Node<K,D> *uncle = (*p)->p_children[!idx_parent];
        if(Red(uncle))
		{
            (*n)->color = BLACK;
            uncle->color = BLACK;
            (*p)->color = RED;
            root->color = BLACK;
            return (*n );
        }
        
        if(Black(uncle))
		{
            if(idx_children != idx_parent)
			{
                turn_side(n,idx_children);
                turn_side(p,idx_parent);
                (*p)->color = BLACK;
                (*p)->p_children[0]->color = RED;
                (*p)->p_children[1]->color = RED;
                root->color = BLACK;
            }
            
            else
			{
                turn_side(p,idx_parent);
                (*p)->color = BLACK,
                (*p)->p_children[!idx_parent]->color = RED;
                root->color =BLACK;
            }
        }
    }
    return (*n );
	
}

template <class K, class D>
bool redblack<K,D>::Red(Node<K, D> * n)
{
    if(!n)
		return false;
    if(n->color == RED)
		return true;
    else 
		return false;
}

template <class K, class D>
bool redblack<K,D>::Black(Node<K, D> * n){
	
    if(!n)
		return true;
    if(n->color == BLACK)
		return true;
    else 
		return false;
}

//Turn side
template <class K, class D>
void redblack<K,D>::turn_side( Node<K,D> ** n, bool side)
{
    Node<K,D> *aux = (*n)->p_children[side];
    (*n)->p_children[side] = aux->p_children[!side];
    aux->p_children[!side] = (*n);
    (*n) = aux;
}


//Revove

template<class K,class D>
bool redblack<K,D>::remove(const K & key,const D & data){
    remove(key, data, &root, NULL);
    return true;
}

template<class K, class D>
Node<K,D> * redblack<K,D>::remove(const K & key,const D & data, Node<K,D> ** n, Node<K,D> ** p){
    Node<K,D> *tmp;
    if(!(*n))
        return NULL;
    
    if((*n)->key==key)
	{
        if((*n)->p_children[0] and (*n)->p_children[1])
		{
            tmp = min(&(*n)->p_children[1]);
            (*n)->key = tmp->key;
            remove((*n)->key,(*n)->data,&(*n)->p_children[1],NULL);
        }
        else
		{
            tmp = (*n);
            if(!((*n)->p_children[0]))
                (*n) = (*n)->p_children[1];
            else
			{
                if(!((*n)->p_children[1]))
                    (*n) = (*n)->p_children[0];
            }
            delete tmp;
        }
        if(!(*n))
            return NULL;
    }
    
    bool idx_children = ((*n)->key < key);
    Node<K,D> *children = remove(key,data,&(*n)->p_children[idx_children],n);
    if(!children)
        return (*n);
    if(!p)
        return NULL;
    if(Red(children) and Red(*n))
	{
        bool idx_parent = ((*p)->p_children[1] == (*n));
        Node<K,D> *uncle = (*p)->p_children[!idx_parent];
        if(Red(uncle))
		{
            (*n)->color = BLACK;
            uncle->color = BLACK;
            (*p)->color = RED;
            root->color = BLACK;
            return (*n);
        }
        if(Black(uncle))
		{
            if(idx_children!=idx_parent)
			{
                turn_side(n,idx_children);
                turn_side(p,idx_parent);
                (*p)->color = BLACK;
                (*p)->p_children[0]->color = RED;
                (*p)->p_children[1]->color = RED;
                root->color = BLACK;
            }
            else{
                turn_side(p,idx_parent);
                (*p)->color = BLACK;
                (*p)->p_children[!idx_parent]->color = RED;
                root->color = BLACK;
            }
        }   
    }
    return (*n); 
}

template <class K, class D>
D & redblack<K,D>::operator()(const K & _key)
{
    D _data =0;
    Node<K,D> *temp;
    if(find(_key,temp))
        return root->data;
        
    else
	{
        insert(_key,_data);
        find(_key,temp);
        return root->data;
    }
}

template<class K,class D>
Node<K,D>* redblack<K,D>::min(Node<K,D> **n)
{
    if (!(*n))
    {
        return NULL;
    }
    else{
        if(!((*n)->p_children[0])){
            return (*n);
        }
        else{
            return min(&((*n)->p_children[0]));
        }
    }
}

//Draw
template <class K, class D>
void redblack<K,D>::draw()
{
    ofstream newFile;
    draw(root,newFile);
}

//Print Color
template<class K, class D>
void redblack<K,D>::print_color(ofstream & os,Node<K,D> *ptr)
{
  	if (ptr == NULL)
    	return;
  	if(ptr->color == 0)
  	{
		os<< ptr->key << "[style=filled, fillcolor=black, fontcolor=white]"<< endl;
  	}
  	else os<< ptr->key << "[style=filled, fillcolor=red]"<< endl;
  	print_color(os,ptr->p_children[0]);
  	print_color(os,ptr->p_children[1]);
}

//Print Arbol
template<class K, class D>
void redblack<K,D>::print_arbol(int num)
{
    string num_arch = to_string(num);
    string ext1 = ".dot";
    string num_xt1=""+ num_arch +""+ ext1 +"";
    ofstream os(num_xt1);
    ////////
    string s = to_string(num);
    string pt1="dot.exe -Tpng  < ";
    string pt2=" > ";
    string pt3=".png";
    string rt=""+ pt1 +""+ num_xt1 +""+ pt2 +""+ s +""+ pt3 +"";
    const char *buffer = rt.c_str();
    ////////
    os<<"Graph  {"<<endl;
    print_arbol(os,root);
    //os<<root->key<<endl;
    print_color(os,root);
    os<<"}"<<endl;
    os.close();
    system(buffer);
}

template<class K, class D>
void redblack<K,D>::print_arbol(ofstream & os,Node<K,D> *n)
{
    if(n!=NULL){
        if(n->p_children[0]!=NULL)
		{
            os<<n->key;
            os<<" -- ";
            os<<n->p_children[0]->key<<endl;
            print_arbol(os,n->p_children[0]);
        }
        if(n->p_children[1]!=NULL)
		{
            os<<n->key;
            os<<" -- ";
            os<<n->p_children[1]->key<<endl;
            print_arbol(os,n->p_children[1]);
        }
    }
}

template<class K,class D>
void redblack<K,D>::Destructor(Node<K,D> *n)
{
 	if(n)
 	{
 		Destructor(n->p_children[0]);
		Destructor(n->p_children[1]);	
		delete(n);	
	}
 }

