#include <iostream>
using namespace std;

void insertion_sort(int a[], int n)
{
    for (int i = 0; i < n; i++) {
        int j = i;  // try to insert a[i] in to the already sorted array a[0],...,a[i-1]
        while (j > 0 && a[j] < a[j-1]) {
            // need to swap a[j] with its preceding element
            // and also update j
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
            j--;

        }
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
    insertion_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}