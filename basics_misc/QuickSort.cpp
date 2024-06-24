#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int start, int end)
{
    int pivot = end;
    int i=start-1,j=start;
    for(;j<end;j++){
        if(a[j]<a[pivot]){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[end]);
    return i+1;
}
void quickSort(int a[], int start, int end)
{
    if (start >= end)
        return;
    int pi = partition(a, start, end);
    quickSort(a, start, pi - 1);
    quickSort(a, pi + 1, end);
}

int partition2(int a[], int start, int end){
    int pivot = a[start];
    int count =0;
    for(int i=start+1;i<=end;i++){
        if(a[i]<pivot) count++;
    }
    int pivotIdx=start+count;
    swap(a[start],a[pivotIdx]);
    int i=start,j=end;
    while(i<pivotIdx && j>pivotIdx){
        while(a[i]<=pivot){
            i++;
        }
        while (a[j]>=pivot)
        {
            j--;
        }
        
        if(i<pivotIdx && j>pivotIdx){
        swap(a[i],a[j]);
        i++;
        j--;
        }
    }
    return pivotIdx;
}
void quickSort2(int a[], int start, int end)
{
    if (start >= end)
        return;
    int pi = partition2(a, start, end);
    quickSort(a, start, pi - 1);
    quickSort(a, pi + 1, end);
}
int main()
{
    int a [] = {20,12,35,16,18,30};
    int size = sizeof(a) / sizeof(a[0]);
    quickSort2(a, 0, size - 1);
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}