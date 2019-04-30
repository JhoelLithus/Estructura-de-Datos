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

