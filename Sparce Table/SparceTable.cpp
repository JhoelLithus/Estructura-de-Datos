#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SparceTable
{
	private:
		int tam=10
		int Sparce[50][50];
		int data[tam];
		
	public:
		SparceTable()
		{
		}
		~SparceTable();
		
		void Matriz()
		{
			int i;
			int j;
			
			for(i=0; i<tam; i++)
			{
				Sparse[i][0]=i;
			}
			
			for(j=1; (1<<j)<=n; j++)
			{
				if(Sparce[i][j-1] < Space[(i<<(j-1))][j-1])
				{
					Sparce[i][j] = Sparce[i][j-1];
				}
				else
				{
					Sparce[i][j] = Sparce[i + (1 << (j - 1))][j - 1];
				}
			}
			return Sparce;
		}
		
		int Query(int i; int d)
		{
			
		}
};

int main()
{
		
}
