#include <iostream>
using namespace std;

int partition(int a[], int l, int r, int p)
{
    // p is the index of the chosen pivot
    // swap the pivot to one end
    int temp = a[p];
    a[p] = a[r];
    a[r] = temp;
    // perform the partitioning
    int j = l-1;
    for (int i =l;i<r;i++)
    {
        if (a[i] < a[r]) {
            j++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    // swap the pivot to the proper position
    temp = a[j+1];
    a[j+1] = a[r];
    a[r] = temp;
    return j+1;
}

void quicksort(int a[], int l, int r)
{
    // l is the leftmost index
    // r is the rightmost index
    if (l < r) {
        int p = l; // choose a pivot, here the leftmost element
        int m = partition(a, l, r, p);
        quicksort(a,l,m-1);
        quicksort(a,m+1,r);
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
    quicksort(a, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}