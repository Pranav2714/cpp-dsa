#include <bits/stdc++.h>
using namespace std;
int const N = 1e3;
void addEleMin(int minHeap[], int ele, int &size)
{
    size++;
    minHeap[size] = ele;
    int curr = size;
    while (curr / 2 > 0 && minHeap[curr / 2] > minHeap[curr])
    {
        swap(minHeap[curr], minHeap[curr / 2]);
        curr /= 2;
    }
}
void maxHeapMax(int minHeap[], int ele, int &size)
{
    size++;
    minHeap[size] = ele;
    int curr = size;
    while (curr / 2 > 0 && minHeap[curr / 2] < minHeap[curr])
    {
        swap(minHeap[curr], minHeap[curr / 2]);
        curr /= 2;
    }
}
void delete_minHeap(int minHeap[], int &size)
{
    minHeap[1] = minHeap[size];
    size--;
    int curr = 1;
    while (2 * curr <= size)
    { // looping till current node has child nodes
        int leftChild = curr * 2;
        int rightchild = (curr * 2) + 1;
        int minChild = leftChild;
        if (rightchild <= size && minHeap[rightchild] < minHeap[leftChild])
        {
            minChild = rightchild;
        }
        if (minHeap[minChild] >= minHeap[curr])
            return;
        swap(minHeap[curr], minHeap[minChild]);
        curr = minChild;
    }
}
int main()
{
    int minHeap[N] = {-1, 10, 20, 30, 40, 50};
    int maxHeap[N] = {-1, 10, 20, 30, 40, 50};
    int size1 = 5;
    int ele = 5;
    addEleMin(minHeap, ele, size1);
    for (int i = 0; i <= size1; i++)
    {
        cout << minHeap[i] << " ";
    }
    cout << endl;
    int size2 = 5;
    maxHeapMax(maxHeap, ele, size2);
    for (int i = 0; i <= size2; i++)
    {
        cout << maxHeap[i] << " ";
    }
    cout << endl;
    delete_minHeap(minHeap, size1);
    maxHeapMax(maxHeap, ele, size2);
    for (int i = 0; i <= size1; i++)
    {
        cout << minHeap[i] << " ";
    }
    cout << endl;
    return 0;
}