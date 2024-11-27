#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1007;
const int inf = 1e16 + 7;
int graph[N][N];

void set_env(int n)
{
	for (int i = 0; i < n + 7; i++)
	{
		for (int j = 0; j < n + 7; j++)
		{
			if (i == j) continue;
			graph[i][j] = inf;
		}
	}
}

int32_t main()
{
	int n, e; cin >> n >> e;

	set_env(n);

	for (int i = 0; i < e; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		graph[u][v] = min(graph[u][v], w);
		graph[v][u] = min(graph[v][u], w);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int res = graph[i][j] == inf ? -1 : graph[i][j];
			cout << res << " ";
		}
		cout << "\n";
	}

	return 0;
}