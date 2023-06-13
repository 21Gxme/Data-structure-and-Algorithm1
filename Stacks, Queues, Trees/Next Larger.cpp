#include <iostream>
#include <stack>

using namespace std;

void next_larger(int n, int a[], int b[])
{
    // populate the answer array b with the default value
    for (int i = 0; i < n; i++)
    {
        b[i] = -1;
    }

    // begin here
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while(!s.empty() && a[i] > a[s.top()])
        {
            b[s.top()] = a[i];
            s.pop();
        }
        s.push(i);
    }
}

int main()
{
    int n, a[1000], b[1000];

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> a[i];
    }
    next_larger(n, a, b);

    for (int i = 0; i < n; i++)
    {
        int x;
        cout << b[i] << endl;
    }
    return 0;
}