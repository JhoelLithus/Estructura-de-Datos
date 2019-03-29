template<class T>
		linked_list<T>::linked_list()
		{
			size=new node<T>[100];
			p_head=NULL;
			p_last=NULL;
			idxfree=0;
			free=NULL;
			freeme=1;
		}

		template<class T>
		linked_list<T>::linked_list(const linked_list<T>& copy)
		{
			const node<T> *Headcopy = copy.p_head;
	    	node<T> *tmp = NULL;

	    	if(Headcopy != NULL){
	        	p_head = new node<T>(Headcopy -> dato);
	        	tmp = p_head;

	        	Headcopy = Headcopy -> p_next;
	        }
	        while (Headcopy != NULL) {
	        	node<T> *newnode = new node<T>(Headcopy -> dato);
	        	tmp -> p_next = newnode;
	        	tmp = tmp -> p_next;
	        	Headcopy = Headcopy -> p_next;
	    	}	
    	}
    	
		template<class T>
		linked_list<T>& linked_list<T>:: operator =(const linked_list<T>& copia) 
		{	
	    	linked_list<T> copy(copia);
	    	std::swap(copy.p_head, p_head);
	    	return *this;
		}
		
		template<class T>
		void linked_list<T>::insert_front(const T & d)
		{
			
				if(p_head==NULL)
				{
					aux=&size[idxfree];
					aux->dato=d;
					p_head=aux;
					p_last = aux;
					aux->p_next=NULL;
					idxfree++;
					
				}
				else if(free!=NULL)
				{
					free->dato=d;
					free->p_next=p_head;
					p_head=free;


				}
				else
				{
					aux=&size[idxfree];
					aux->dato=d;
					aux->p_next=p_head;
					p_head=aux;
					idxfree++;
				}
			
		}

		template<class T>
		void linked_list<T>:: insert_back(const T & d)
		{
	
				
				if(p_head==NULL)
				{
					aux=&size[idxfree];
					aux->dato=d;
					p_head = aux;
					p_last = aux;
					p_head->p_next=NULL;
	
					p_last=aux;
					idxfree++;


				}
				else if(free!=NULL)
				{
					free->dato=d;
					p_last->p_next=free;
					p_last=free;


				}
				else
				{
					aux=&size[idxfree];
					aux->dato=d;
					p_last->p_next=aux;
					p_last=aux;
					idxfree++;
				}
				
				p_last->p_next=NULL;

				cout<<idxfree<<endl;
			
		}
		
		template<class T>
		void linked_list<T>::remove_front()
		{
			
			if(p_head==p_last)
			{
				free=p_head;
				p_head=NULL;
				p_last=NULL;
			}
			else
			{
			free=p_head; 
			
			p_head=p_head->p_next; 
			free->p_next=free;
			
			}
		}

		template<class T>
		void linked_list<T>::remove_back()
		{
			aux=p_head;
			if(aux->p_next!=NULL){
				while((aux->p_next)->p_next!=NULL)
				{
					aux=aux->p_next;
				}
				free=aux->p_next;
				aux->p_next=NULL;
			}
			else{
				free= p_last;
				p_head=NULL;
				p_last=NULL;

			}
		}
		
		template<class T>
		void linked_list<T>::reverse()
		{
			node<T> *next = NULL;    
			node<T>*auxx=p_head;
			node<T>*newfin= NULL;
			while(auxx){
				next=auxx->p_next;
				auxx->p_next=newfin;
				newfin=auxx;
				auxx=next;		
			}						
			p_head=p_last;		
		}

		template<class T>
		void linked_list<T>::print()
		{
			
			cout<<endl;
			cout<<"Listas enlazadas: "<<endl;
			aux=p_head;
			while(aux!=NULL){
				cout<<aux->dato<<", ";
				aux=aux->p_next;
			}
		}

		template<class T>
		void linked_list<T>::remove(const T & d)
		{
			node<T> * tmp;
			node<T> *tmp2;
			tmp=p_head;

			if(p_head==p_last)
			{
				free=p_head;
				p_head=NULL;
				p_last=NULL;
			}
			else if(d==p_head->dato)
			{
				free=p_head; 
				p_head=p_head->p_next; 
				free->p_next=free;
			}
			else
			{
			while(d!=tmp->dato){
				if(tmp->p_next!=NULL)
				{
					tmp2=tmp;
					tmp=tmp->p_next;			
				}
				else
				{
					cout<<"no se pudo encontrar en objeto."<<endl;
					return;
				}

			}	
				free=tmp2->p_next;
				tmp2->p_next=tmp->p_next;

			}		
		}
