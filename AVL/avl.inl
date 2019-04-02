

template<class K,class D>
bool avl<K,D>:: find(node<K, D> **& n, const K & key)
	{
		n = &p_root;
		while(*n)
		{
			if((*n)->key == key) return true;
				
			n = &(*n)->p_child[(*n)->key < key];
		}
			
		return false;
	}
		
template<class K,class D>
bool avl<K,D>:: insert(const K & key, const D & dato)
	{
		node<K, D> ** n;
		if(find(n, key)) return false;
			
		*n = new node<K, D>(key, dato);
		return true;
	}		


