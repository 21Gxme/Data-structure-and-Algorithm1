#include <iostream>
using namespace std;

void bubble_sort(int a[], int n)
{
    bool swapped = true ;
    while (swapped) {
        swapped = false;
        for (int i = 1; i < n; i++) {
            // compares a[i] with a[i-1]
            if (a[i] < a[i-1]) {
                // wrong order, swap them; don't forget to update swapped variable
                int temp = a[i];
                a[i] = a[i-1];
                a[i-1] = temp;
                swapped = true;
            }
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
    bubble_sort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}