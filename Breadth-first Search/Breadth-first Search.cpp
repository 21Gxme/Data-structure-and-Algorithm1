#include <iostream>
#include <queue>
#include <list>

using namespace std;

queue<pair<int, int> > bag;
list<int> adj[1000];
bool mark[1000];
int parent[1000];
int dist[1000];

/* breadth-first search starting from s */
void bfs(int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        mark[i] = false;
        dist[i] = 9999;    /* set distance to "infinite" */
        parent[i] = -1;
    }

    /* set initial distance */
    dist[s] = 0;

    bag.push(pair<int, int>(-1,s));
    while (!bag.empty()) {
        pair<int, int> bag_item = bag.front();
        int p = bag_item.first;
        int v = bag_item.second;
        bag.pop();
        if (!mark[v]) {
            mark[v] = true;
            if (p != -1)
            {
                dist[v] = dist[p] + 1;
            }
            for (int w : adj[v]) {
                bag.push(pair<int, int>(v,w));
            }
        }
    }
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
    bfs(n, 0);
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << endl;
    }
    return 0;
}