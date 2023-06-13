#include <iostream>
#include <algorithm>
#include <list>


using namespace std;

list<int> adj[1000];
int color[1000];




// return true if there is a valid two-coloring, and fill the "color" array
// return false if not
bool two_color(int n)
{
    for (int i = 0; i < n; i++)
    {
        color[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            list<int> q;
            q.push_back(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop_front();
                for (auto v : adj[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push_back(v);
                    }
                    if (color[v] == color[u])
                    {
                        return false;
                    }
                }
            }
        }
    }
    return true;
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
        adj[b].push_back(a);
    }
    if (two_color(n))
    {
        cout << "true" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << color[i] << endl;
        }
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}