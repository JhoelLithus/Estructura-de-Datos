#include <iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

#define N 200

vector<int> G[N];

int bfs(int u)
{
	int color[N]={0};
	int visite[N]{0};
	queue <int> q;
	q.push(u);
	color[u]=1;
	while(!q.empty())
	{
		int v=q.front();
		q.pop();
		int d=color[v]==1?2:1;
		int tam=G[v].size();
		for(int i=0; i<tam;i++)
		{
			u=G[v][i];
			if(color[v]==color[u])
				return 0;
			if(!visite[u])
			{
				q.push(u);
				color[u]=d;
				visite[u]=1;
			}
		}
	}
	return 1;
}

main()
{
	int n;
	int q;
	int x;
	int y;
	
	while(1)
	{	
		scanf("%d", &n);
		if(n==0)
			break;
		scanf("%d",&q);
		
		for(int i=0; i<q; i++)
		{
			scanf("%d%d",&x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		
		if((bfs(0)))
			printf("BICOLORABLE.\n");	
		else 
			printf("NOT BICOLORABLE.\n");
			
		for (int i=0;i<n;i++) G[i].clear();
	}
	
	return 0;
}
