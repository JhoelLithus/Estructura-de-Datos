#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include<fstream>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Edge //Aristas
{
    int r, c; //Fila -> Columna
    int cost;
    
    bool operator>(const Edge &e) const
    {
        return this->cost > e.cost;
    }
};

int main()
{    
	ifstream in("Uva 929.txt");
    int n;
    in >> n;
    while (n--)
    {
        int N, M;
        in >> N >> M;

        vector<vector<int> > lab(N, vector<int>(M));

        for (int r = 0; r < N; ++r)
        {
        	for (int c = 0; c < M; ++c)
            	in >> lab[r][c];	
		}
        priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
        vector<vector<int> > cost(N, vector<int>(M, -1));

        // min-heap.
        Edge e;
        e.r = 0;
        e.c = 0;
        e.cost = lab[0][0];
        pq.push(e);
        cost[0][0] = e.cost;
        while (!pq.empty())
        {
            Edge u = pq.top();
            pq.pop(); 
            for (int i = 0; i < 4; ++i)
            {
                int r = u.r + dx[i];
                int c = u.c + dy[i];
                if (r < 0 || r >= N || c < 0 || c >= M)
                    continue;
                if (cost[r][c] == -1 || cost[u.r][u.c] + lab[r][c] < cost[r][c])
                {
                    cost[r][c] = cost[u.r][u.c] + lab[r][c];
                    e.r = r;
                    e.c = c;
                    e.cost = cost[r][c];
                    pq.push(e);
                }
            }
        }
        cout << cost[N - 1][M - 1] << endl;
    }
    return 0;
}
