#include <iostream>
using namespace std;

void selection_sort(int a[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // initialize a variable for the index to the minimum value
        int min = i ;
        // find smallest elements from a[i] ... a[n-1]
        for (int j =i+1;j < n;j++) {
            if (a[j] < a[min]) {
                // update the index to the minimum value
                min = j;
            }
        }
        // swap a[i] with the smallest element
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

int main()
{
    int a[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selection_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}