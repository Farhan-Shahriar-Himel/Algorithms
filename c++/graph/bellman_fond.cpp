#include <bits/stdc++.h>
using namespace std;

class Edge{
public:
	int source, destination, weight;
	Edge(int s, int d, int w)
	{
		source = s;
		destination = d;
		weight = w;
	}
};

const int N = 1e3 + 7;
const int inf = 1e9 + 7;
vector < Edge > edges;
vector < int > dist(N, inf);
bool vis[N];

bool belman_ford(int source, int n)
{
	dist[source] = 0;
	for (int i = 1; i < n; i++)
	{
		for (auto edge: edges)
		{
			int u = edge.source;
			int v = edge.destination;
			int w = edge.weight;

			if (dist[u] != inf and dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
			}
		}
	}

	for (auto edge: edges)
	{
		int u = edge.source;
		int v = edge.destination;
		int w = edge.weight;

		if (dist[u] != inf and dist[u] + w < dist[v])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int n, e; cin >> n >> e;
	for (int i = 0; i < e; i++)
	{
		int x, y, z; cin >> x >> y >> z;
		edges.push_back(Edge(x, y, z));
	}

	bool neg_cycle = belman_ford(1, n);

	if (neg_cycle)
	{
		cout << "There is a negetive Cycle.\n";
		return 0;
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dist[i] << "\n";
	}

	return 0;
}