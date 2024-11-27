#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector < int > adj[N];
bool vis[N];

vector < int > sequence;

void bfs(int source)
{
	queue < int > q;
	q.push(source);
	vis[source] = true;

	while (!q.empty())
	{
		int parent = q.front();
		q.pop();
		sequence.push_back(parent);

		for (auto child: adj[parent])
		{
			if (!vis[child])
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
	for (int i = 0; i < e; i++) 
	{
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	bfs(1);

	for (int i = 0; i < sequence.size(); i++) cout << sequence[i] << " ";

	cout << "\n";
	
	return 0;
}