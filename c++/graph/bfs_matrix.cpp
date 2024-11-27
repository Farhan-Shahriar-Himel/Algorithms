#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
int graph[N][N];
bool vis[N];

vector < int > sequence;

void bfs(int source, int node)
{
	queue < int > q;
	q.push(source);
	vis[source] = true;

	while (!q.empty())
	{
		int parent = q.front();
		q.pop();
		sequence.push_back(parent);

		for (int child = 1; child <= node; child++)
		{
			if (!vis[child] and graph[parent][child])
			{
				q.push(child);
				vis[child] = true;
			}
		}
	}
}

int main()
{
	int v, e; cin >> v >> e;
	for (int i = 0; i < v; i++)
	{
		int x, y; cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	bfs(1, v);

	for (auto el: sequence) cout << el << " ";

	cout << "\n";
	
	return 0;
}