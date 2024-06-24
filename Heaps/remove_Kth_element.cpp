#include <bits/stdc++.h>
using namespace std;
int const N = 1e7;
void heapify(int minHeap[], int n, int curr)
{
    while ((2 * curr + 1) < n)
    {
        int leftChild = (curr * 2) + 1;
        int rightChild = (curr * 2) + 2;
        int minChild = leftChild;
        if (rightChild < n && minHeap[rightChild] < minHeap[leftChild])
        {
            minChild = rightChild;
        }
        if (minHeap[minChild] >= minHeap[curr])
            return;
        swap(minHeap[curr], minHeap[minChild]);
        curr = minChild;
    }
}
void remove(int minHeap[], int &size)
{
    swap(minHeap[0], minHeap[size - 1]);
    size--;
    heapify(minHeap, size, 0);
}
int findKthLargest(int minHeap[], int n, int k)
{
    int last_parent = (n / 2) - 1;
    for (int i = last_parent; i >= 0; i--)
    {
        heapify(minHeap, n, i);
    }
    for (int i = 1; i < k; i++)
    {
        remove(minHeap, n);
    }
    return minHeap[0];
}
int main()
{
    int n = 6;
    int minHeap[] = {7, 10, 4, 3, 20, 15};
    int k = 4;
    int ans = findKthLargest(minHeap, n, k);
    cout << ans << endl;
    return 0;
}