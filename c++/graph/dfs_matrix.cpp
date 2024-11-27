#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int graph[N][N];
bool vis[N];

vector < int > sequence;

void dfs(int source, int nodes)
{
	vis[source] = true;
	sequence.push_back(source);

	for (int child = 1; child <= nodes; child++)
	{
		if (!vis[child] and graph[source][child])
		{
			dfs(child, nodes);
		}
	}
}

int main()
{
	int v, e; cin >> v >> e;
	for (int i = 0; i < e; i++)
	{
		int x, y; cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	dfs(1, v);

	for (auto el: sequence) cout << el << " ";

	cout << "\n";

	return 0;
}