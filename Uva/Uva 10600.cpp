#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 100

using namespace std;

struct UnionFind
{
	int comp[N];

	int unionfind(const int & n)
	{
		for(int i = 1; i <= n; i++)
			comp[i] = i;
	}

	int find(int & x)
	{
		if(x==comp[x])
			return x;
		return comp[x] = find(comp[x]);
	}

	bool join(int x, int y)
	{
		x = find(x);
		y = find(y);

		if(x == y)
		return false;

		comp[y] = x;
		return true;
	}

	int n_comp(int n)
	{
		int count = 0;
		for(int i = 1; i <= n; i++)
			if(comp[i] == i) count++;

		return count;
	}
};

struct Edge
{
	int u;
	int v;
	int w;
	
	bool operator < (const Edge & e)
	{
		return w < e.w;
	}
};
int main()
{
	int ncas;
	int n; //n= nescuela -> m=nconexion
	int m;
	int a;
	int b;
	int c;
	int mincost;
	bool mst[300];
	Edge E[300];
	UnionFind uf;
	
	cin>> ncas;
	
	while(ncas--)
	{
		cin>> n>>m;
		for(int i=0; i<m; i++)
		{
			cin>>a>>b>>c;
		}
		sort(E, E + m);
		
		memset(mst,0,sizeof(mst));
		
		
		uf.unionfind(n);
		c = 0;
		
		for(int i = 0; i < m; i++)
			if(uf.join(E[i].u, E[i].v))
			{
				mst[i] = 1;
				c += E[i].w;
			}
		
		printf("%d ", c);

		mincost = c * n;
		for(int i = 0; i < m; i++) if(mst[i])
		{
			uf.unionfind(n);
			c = 0;
			for(int j = 0; j < m; j++)
				if(i != j && uf.join(E[j].u, E[j].v))
					c += E[j].w;

			if(uf.n_comp(n) == 1 && c < mincost) mincost = c;
		}
		
		printf("%d\n", mincost);
		
	}
	
	
}
