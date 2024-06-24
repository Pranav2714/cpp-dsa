#include <bits/stdc++.h>
using namespace std;
int const N = 1e3;
void insertMax_heap(int maxHeap[], int &size, int &value)
{
    size++;
    int curr = size;
    maxHeap[size] = value;
    while (curr / 2 > 0 && maxHeap[curr / 2] < maxHeap[curr])
    {
        swap(maxHeap[curr], maxHeap[curr / 2]);
        curr /= 2;
    }
}
void removeMaxHeap(int maxHeap[], int &size)
{
    swap(maxHeap[1], maxHeap[size]);
    size--;
    int curr = 1;
    while (2 * curr <= size)
    {
        int lftChild = 2 * curr;
        int rightChild = (2 * curr) + 1;
        int maxChild = lftChild;
        if (rightChild <= size && maxHeap[rightChild] > maxHeap[lftChild])
        {
            maxChild = rightChild;
        }
        if (maxHeap[maxChild] <= maxHeap[curr])
        {
            return;
        }

        swap(maxHeap[maxChild], maxHeap[curr]);
        curr = maxChild;
    }
}
int main()
{
    int maxHeap[N] = {-1, 90, 80, 70, 20, 10, 50, 60};
    // 0    1   2   3   4   5   6   7
    int size = 7;
    int value = 100;
    // insertMax_heap(maxHeap, size, value);
    for (int i = 0; i <= size; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;
    removeMaxHeap(maxHeap, size);
    for (int i = 0; i <= size; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;

    return 0;
}