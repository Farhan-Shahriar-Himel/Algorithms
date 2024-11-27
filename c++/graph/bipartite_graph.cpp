#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
vector < int > adj[N];
bool vis[N];
bool color[N];

bool dfs(int source, int clr)
{
    vis[source] = true;
    color[source] = clr;

    bool res = true;

    for (auto child: adj[source])
    {
        if (!vis[child])
        {
            res &= dfs(child, 1 - clr);
        }
        else if (color[child] == color[source])
        {
            res = false;
        }
    }

    return res;
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    bool ok = dfs(1, 0);

    if (ok) cout << "The graph is bipartite" << "\n";
    else cout << "The graph is not bipartite" << "\n";
    return 0;
}