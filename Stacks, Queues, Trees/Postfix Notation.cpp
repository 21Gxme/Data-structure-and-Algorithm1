#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int n;
    stack<int> s;
    string item;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> item;
        if (item.compare("+") == 0)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a + b);
        }
        else if (item.compare("-") == 0)
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            s.push(a - b);
        }
        else if (item.compare("*") == 0)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            s.push(a * b);
        }
        else if (item.compare("/") == 0)
        {
            int b = s.top();
            s.pop();
            int a = s.top();
            s.pop();
            s.push(a / b);
        }
        else
        {
            // stoi converts string to integer
            int val = stoi(item);
            s.push(val);
        }
    }

    cout << s.top() << endl;
    return 0;
}