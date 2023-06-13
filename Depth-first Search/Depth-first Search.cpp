#include <iostream>
#include <algorithm>
#include <list>


using namespace std;

list<int> adj[1000];
int pre[1000];
int post[1000];


int dfs_clock = 0;

void dfs(int n, int s)
{
    pre[s] = dfs_clock++;
    for (auto u : adj[s])
    {
        if (pre[u] == -1)
        {
            dfs(n, u);
        }
    }
    post[s] = dfs_clock++;
}

int main()
{
    int n, m;
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a;
        cin >> b;
        adj[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
    {
        pre[i] = -1;
        post[i] = -1;
    }
    dfs(n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << pre[i] << " " << post[i] << endl;
    }
    return 0;
}