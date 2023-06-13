#include <iostream>

using namespace std;

class PriorityQueue
{
public:
    virtual void insert(int val) = 0;
    virtual int extract_min() = 0;
};

class Heap : public PriorityQueue
{
private:
    int h[1000];
    int h_size;

    void heap_swap(int pos_a, int pos_b) {
        int temp = h[pos_a];
        h[pos_a] = h[pos_b];
        h[pos_b] = temp;
    }

    // heapify up starting from index pos
    void heapify_up(int pos)
    {
        while (pos > 0 && h[pos] < h[(pos - 1) / 2])
        {
            heap_swap(pos, (pos - 1) / 2);
            pos = (pos - 1) / 2;
        }

    }

    // heapify down starting from index pos
    void heapify_down(int pos)
    {
        int smallest = pos;
        int left = 2 * pos + 1;
        int right = 2 * pos + 2;

        if (left < h_size && h[left] < h[smallest])
        {
            smallest = left;
        }

        if (right < h_size && h[right] < h[smallest])
        {
            smallest = right;
        }

        if (smallest != pos)
        {
            heap_swap(pos, smallest);
            heapify_down(smallest);
        }
    }

public:
    Heap()
    {
        h_size = 0;
    }

    void insert(int val)
    {
        h[h_size++] = val;
        heapify_up(h_size-1);
    }

    int extract_min()
    {
        if (h_size == 0)
        {
            return -1;
        }

        int min_val = h[0];
        h[0] = h[--h_size];
        heapify_down(0);
        return min_val;
    }
};

int main()
{
    Heap h;
    int n;
    string operation;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> operation;
        if (operation == "insert") {
            int val;
            cin >> val;
            h.insert(val);
        } else if (operation == "extract-min") {
            cout << h.extract_min() << endl;
        }
    }
    return 0;
}