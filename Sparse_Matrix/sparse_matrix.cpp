#include <iostream>
#include <cstring>
#include <iomanip> 
using namespace std;

template <class T>
class sparse_matrix
{
	struct node
	{
		T value;
		size_t pos[2];		// pos[0] = i-row, pos[1] = i-col
		node * p_next[2];	// p_next[0]: next row node
							// p_next[1]: next col node
		
		node(size_t i, size_t j, node * nr, node * nc)
		{
			pos[0] = i;
			pos[1] = j;
			p_next[0] = nr;
			p_next[1] = nc;
		}
	};
	
	private:
		node ** p_head[2];
		size_t n_rows, n_cols;
		
	public:
		
	sparse_matrix(size_t nr = 0, size_t nc = 0): n_rows(nr), n_cols(nc)
	{
		if(!n_cols) n_cols = n_rows;
		if(!n_rows)
		{
			p_head[0] = p_head[1] = NULL;
			return;
		}			
			
		p_head[0] = new node * [n_rows];
		p_head[1] = new node * [n_cols];
			
		memset(p_head[0], 0, sizeof(node *) * n_rows);
		memset(p_head[1], 0, sizeof(node *) * n_cols);
	}
		
	~sparse_matrix()
	{	
		this->destructor();
	}
		
		
/*		
	~sparse_matrix()			//destructor
	{								
		for (int i = 0; i < n_rows; i++)
		{
			if (p_head[i] == NULL)
			{
				delete p_head[i];
			}
			else
			{
				node * current = p_head[i];
				while (current->p_next[2] != NULL)
				{
					current = current->p_next[2];
					delete p_head[i];
					p_head[i] = current;
				}
			}
		}
		delete[] p_head[2];
	}
	*/	
		
	void destructor(void)
	{
		if (this->p_head[2] != NULL)
		{
		
			if(p_head[0])
			{
				for(int i=0;i<n_rows;i++)
				{
					for(int j=0; j<n_cols;j++)
					{
					delete[]p_head[i];
					delete[]p_head[j];
					}
				}
			}
			else
			{
			
			}
		}
		
	}
		
		
	void remove(size_t row, size_t col)
	{
		if (this->p_head[2] != NULL)
		{
			
		}
	}
		
	bool find(node **& n, size_t i, size_t j, bool c)
	{
		n = &p_head[c][i];
		while(*n && (*n)->pos[!c] < j)
			n = &(*n)->p_next[c];
			
		return (*n) && (*n)->pos[!c] == j;
	}
		
	T & operator () (size_t i, size_t j)
	{
		node ** nr;
		if(!find(nr, i, j, 0))
		{
			node ** nc;
			find(nc, j, i, 1);
			*nr = *nc = new node(i, j, *nr, *nc);
		}
			
		return (*nr)->value;
	}
		
	print()
	{	
		node ** n;
		for(int i=0; i<n_rows; i++)
		{
			for(int j=0; j<n_cols; j++)
			{
				if(!find(n, i, j, 0))
				{
					cout<<0<<"  ";
				}
				else
				{
					cout<<(*n)->value<<"  ";
				}
			}
			cout<<endl;
		}		
	}
		
	void transpuesta()
	{
		node ** n;
		for(int i=0; i<n_rows; i++)
		{
			for(int j=0; j<n_cols; j++)
			{
				if(!find(n, j, i, 0))
				{
					cout<<0<<"  ";
				}
				else
				{
					cout<<(*n)->value<<"  ";
				}
			}
			cout<<endl;
		}	
	}		
	
};

int main()
{
	sparse_matrix<int> m(3, 4);
	sparse_matrix<int> sq(3);
	
	sq(0, 1) = 12;
	sq(1, 2) = 23;
	sq(1, 0) = 32;
	sq(2, 2) = 21;
	sq(2, 0) = 11;
	//sq.remove(0,1);
	sq.print();
	
	cout<<"XxX"<<endl;

	sq.transpuesta();
	return 0;
}

//destructror   	TODO
//print				TODO
//remove (i,j)		NADA
//to  csr			NADA
//to csc			NADA
//Transpueesta		TODO
//implementar csr	NADA

/*
class csc
{
	
};
csr to csr()
{
	
}


*/
