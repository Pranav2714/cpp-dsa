#include <bits/stdc++.h>
using namespace std;
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
int remove(int minHeap[], int &size)
{
    int a = minHeap[0];
    minHeap[0] = minHeap[size - 1];
    size--;
    heapify(minHeap, size, 0);
    return a;
}
int sumOfelementsBtwk1k2(int arr[], int n, int k1, int k2)
{
    int last_parent = (n / 2) - 1;
    for (int i = last_parent; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    int x = k1;
    while (x--)
    {
        remove(arr, n);
    }
    int ele = k2 - k1 - 1;
    int sum = 0;
    while (ele--)
    {
        sum += remove(arr, n);
    }
    return sum;
}
int main()
{
    int arr[7] = {20, 8, 22, 4, 12, 10, 14};
    int n = 7;
    int k1 = 3;
    int k2 = 5;
    cout << sumOfelementsBtwk1k2(arr, n, k1, k2) << endl;
    return 0;
}