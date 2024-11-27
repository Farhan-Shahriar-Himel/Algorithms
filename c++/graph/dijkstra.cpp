#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 7;
const int inf = 2e16 + 7;
vector < pair < int, int > > adj[N];
vector < int > dist(N, inf);


void dijkstra(int src)
{
	priority_queue < 
		pair < int, int >,
		vector < pair < int, int > >,
		greater < pair < int, int > >
	> pq;
	
	dist[src] = 0;
	pq.push({dist[src], src});

	while (!pq.empty())
	{
		int wt = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (wt > dist[u]) continue;

		for (auto child: adj[u])
		{
			int v = child.first;
			int w = child.second;

			if (dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
}


int32_t main()
{
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		adj[u].push_back({v, w});
	}


	dijkstra(1);

	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << " ";
	}

	return 0;
}