#include <iostream>
#include <algorithm>
#include <list>
#include <unordered_set>


using namespace std;

list<int> adj[1000];


bool has_cycle_helper(int node, unordered_set<int>& visited, unordered_set<int>& visiting) {
    visited.insert(node);
    visiting.insert(node);

    for (int neighbor : adj[node]) {
        if (visited.find(neighbor) == visited.end()) {
            if (has_cycle_helper(neighbor, visited, visiting)) {
                return true;
            }
        } else if (visiting.find(neighbor) != visiting.end()) {
            return true;
        }
    }

    visiting.erase(node);
    return false;
}

// return true if there is a cycle
// return false if not
bool has_cycle(int n)
{
    unordered_set<int> visited;
    unordered_set<int> visiting;

    for (int i = 0; i < n; i++) {
        if (visited.find(i) == visited.end()) {
            if (has_cycle_helper(i, visited, visiting)) {
                return true;
            }
        }
    }

    return false;
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

    if (has_cycle(n))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}