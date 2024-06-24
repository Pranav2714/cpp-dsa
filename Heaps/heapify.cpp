#include <bits/stdc++.h>
using namespace std;
int const N = 1e3;
void heapify_min(int minHeap[], int &size, int curr)
{
    while (2 * curr <= size)
    {
        int leftChild = curr * 2;
        int rightChild = (curr * 2) + 1;
        int minChild = leftChild;
        if (rightChild <= size && minHeap[rightChild] < minHeap[leftChild])
        {
            minChild = rightChild;
        }
        if (minHeap[minChild] >= minHeap[curr])
            return;
        swap(minHeap[curr], minHeap[minChild]);
        curr = minChild;
    }
}
void heapify_max(int maxHeap[], int &size, int curr)
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
int main()
{
    int minHeap[N] = {-1, 60, 10, 80, 50, 5, 20, 70};
    int maxHeap[N] = {-1, 60, 10, 80, 50, 5, 20, 70};
    int n = 7;
    for (int i = n / 2; i > 0; i--)
    {
        heapify_min(minHeap, n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << minHeap[i] << " ";
    }
    cout << endl;
    for (int i = n / 2; i > 0; i--)
    {
        heapify_max(maxHeap, n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;
    return 0;
}