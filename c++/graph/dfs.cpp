//Complexity : O(V+E)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
vector < int > adj[N]; 
bool vis[N];

vector < int > sequence;

void dfs(int source)
{
	vis[source] = true;
	sequence.push_back(source);

	for (auto child: adj[source])
	{
		if (!vis[child])
		{
			dfs(child);
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

	dfs(1);

	for (auto el: sequence) cout << el << " ";

	cout << "\n";

	return 0;
}