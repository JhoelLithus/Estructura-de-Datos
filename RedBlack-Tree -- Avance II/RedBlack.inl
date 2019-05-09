template <class K, class D>
bool redblack<K,D>::find(K _key){
    Node<K,D> * temp = root;
    if(!temp) return false;
    while(temp){
        if(temp->key == _key) return true;
        temp = temp->p_children[temp->key < _key];
    }
    return false;
}

template <class K, class D>
bool redblack<K,D>::find(const K & _key, Node<K,D> *temp){
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
        (*n)->color = Red;
		root->color = Black;
        return (*n);
	}
	if((*n)->key == _key)
		return NULL;
	
	int idx_children = ((*n)->key < _key);		//idx_children -> Direccion del Nodo Hijo
    Node <K,D> *children = insert(_key,_data,&(*n)->p_children[idx_children],n);
    if(!children) return (*n);
    if(!p) return NULL;
        
    if(is_red(children) && is_red(*n))
	{
        int idx_parent = ((*p)->p_children[1] == (*n));
        Node<K,D> *uncle = (*p)->p_children[!idx_parent];
        if(is_red(uncle))
		{
            (*n)->color = Black;
            uncle->color = Black;
            (*p)->color = Red;
            root->color = Black;
            return (*n );
        }
        
        if(is_black(uncle))
		{
            if(idx_children != idx_parent)
			{
                turn_side(n,idx_children);
                turn_side(p,idx_parent);
                (*p)->color = Black;
                (*p)->p_children[0]->color = Red;
                (*p)->p_children[1]->color = Red;
                root->color = Black;
            }
            
            else
			{
                turn_side(p,idx_parent);
                (*p)->color = Black,
                (*p)->p_children[!idx_parent]->color = Red;
                root->color =Black;
            }
        }
    }
    return (*n );
	
}

template <class K, class D>
void redblack<K,D>::turn_side( Node<K,D> ** n, bool side)
{
    Node<K,D> *aux = (*n)->p_children[side];
    (*n)->p_children[side] = aux->p_children[!side];
    aux->p_children[!side] = (*n);
    (*n) = aux;
}

template <class K, class D>
bool redblack<K,D>::Red(Node<K, D> * n){
    if(!n)
		return false;
    if(n->color == Red)
		return true;
    else return false;
}

template <class K, class D>
bool redblack<K,D>::Black(Node<K, D> * n){
    if(!n)
		return true;
    if(n->color == Black)
		return true;
    else return false;
}


//Revove

template<class K,class D>
bool redblack<K,D>::remove(const K & key,const D & data){
    remove(key, data, &p_root, NULL);
    return true;
}

template<class K, class D>
Node<K,D> * redblack<K,D>::remove(const K & key,const D & data, Node<K,D> ** n, Node<K,D> ** p){
    Node<K,D> *tmp;
    if(!(*n))
        return NULL;
    
    if((*n)->key==key){
        if((*n)->p_children[0] and (*n)->p_children[1]){
            tmp = min(&(*n)->p_children[1]);
            (*n)->key = tmp->key;
            remove((*n)->key,(*n)->data,&(*n)->p_children[1],NULL);
        }
        else{
            tmp = (*n);
            if(!((*n)->p_children[0])){
                (*n) = (*n)->p_children[1];
            }
            else{
                if(!((*n)->p_children[1])){
                    (*n) = (*n)->p_children[0];
                }
            }
            delete tmp;
        }
        if(!(*n)){
            return NULL;
        }
    }
    bool idx_children = ((*n)->key < key);
    Node<K,D> *children = remove(key,data,&(*n)->p_children[idx_child],n);
    if(!children){
        return (*n);
    }
    if(!p){
        return NULL;
    }
    if(Red(children) and Red(*n)){
        bool idx_parent = ((*p)->p_children[1] == (*n));
        Node<K,D> *uncle = (*p)->p_children[!idx_parent];
        if(Red(uncle)){
            (*n)->color = Black;
            uncle->color = Black;
            (*p)->color = Red;
            root->color = Black;
            return (*n);
        }
        if(is_black(uncle)){
            if(idx_children!=idx_parent){
                turn_side(n,idx_children);
                turn_side(p,idx_parent);
                (*p)->color = Black;
                (*p)->p_children[0]->color = Red;
                (*p)->p_children[1]->color = Red;
                root->color = Black;
            }
            else{
                turn_side(p,idx_parent);
                (*p)->color = Black;
                (*p)->p_children[!idx_parent]->color = Red;
                root->color = Black;
            }
        }   
    }
    return (*n); 
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

