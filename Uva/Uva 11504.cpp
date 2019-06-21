#include <bits/stdc++.h>

using namespace std;
#define MAX 100000

int node;
int edge;
int num ;
int color[MAX];
vector <long> graph[MAX];
vector <long> dipto;

void dfsvisit(int u)
{
    int i;
	int j;
    color[u] = true;
    for(i=0;i<graph[u].size();i++)
    {
        int v = graph[u][i];
        if(color[v]==0)
        {
            dfsvisit(v);
        }
    }
    dipto.push_back(u);
}

void dfs()
{
    memset(color,0,sizeof(color));
    for(int i=1; i<=node; i++)
    {
        if(color[i]==0)
        {
            dfsvisit(i);
        }
    }
}
void dfs2()
{
    memset(color,0,sizeof(color));
    int j = dipto.size()-1;
    for(int i=j; i>=0; i--)
    {
        if(color[dipto[i]]==0)
        {
            dfsvisit(dipto[i]);
            num++;
        }
    }
}

int main()
{
    int n,a,b; // a= número de fichas de dominó  --- b=número de líneas a seguir en el caso de prueba
    scanf("%d",&n);
    
    while(n--)
    {
        num = 0;
        scanf("%d %d",&node, &edge);
        
        for(int i=1;i<=edge;i++)
        {
            scanf("%d %d",&a,&b);
            graph[a].push_back(b);
        }
        dfs();
        dfs2();

        printf("%d\n",num);

        dipto.clear();
        for(int j=0;j<MAX;j++)
        {
            graph[j].clear();
        }
    }
}
