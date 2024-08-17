#include <bits/stdc++.h>
using namespace std;
int const N = 1e3;
void heapify(int maxHeap[], int &size, int curr)
{
    while (2 * curr <= size)
    {
        int leftChild = curr * 2;
        int rightChild = (curr * 2) + 1;
        int maxChild = leftChild;
        if (rightChild <= size && maxHeap[rightChild] > maxHeap[leftChild])
        {
            maxChild = rightChild;
        }
        if (maxHeap[maxChild] <= maxHeap[curr])
            return;
        swap(maxHeap[curr], maxHeap[maxChild]);
        curr = maxChild;
    }
}
void remove(int maxHeap[], int &size)
{
    swap(maxHeap[1], maxHeap[size]);
    size--;
    heapify(maxHeap, size, 1);
}
void heapSort(int maxHeap[], int &size)
{
    for (int i = size / 2; i > 0; i--)
    {
        heapify(maxHeap, size, i);
    }
    while (size > 0)
    {
        remove(maxHeap, size);
    }
}
int main()
{
    int maxHeap[N] = {-1, 60, 10, 80, 50, 5, 20, 70};
    int n = 7;
    heapSort(maxHeap, n);

    for (int i = 0; i <= 7; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;
    return 0;
}