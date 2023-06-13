#include <iostream>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

list<int> adj[1000];
int top_order[1000];
bool visited[1000];
stack<int> stk;
int idx = 0;


void top_sort_util(int v) {
    visited[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            top_sort_util(*i);
        }
    }
    stk.push(v);
}

void top_sort(int n)
{
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            top_sort_util(i);
        }
    }
    while (!stk.empty()) {
        top_order[idx++] = stk.top();
        stk.pop();
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
    top_sort(n);
    for (int i = 0; i < n; i++)
    {
        cout << top_order[i] << endl;
    }
}