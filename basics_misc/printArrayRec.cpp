#include<bits/stdc++.h>
using namespace std;
void printArray(int a [],int idx,int n){
    if(idx==n) return;
    printArray(a,idx+1,n);
    cout<<a[idx]<<" ";
    
}
int findMax(int a[],int idx,int n){
    if(idx==n-1) return a[idx];
    int smallAns=findMax(a,idx+1,n);
    return max(a[idx],smallAns);
}
int findSum(int *a, int idx,int n){
    if(idx==n-1) return a[idx];
    return a[idx]+findSum(a,idx+1,n);

}
int main(){
    cout<<"Enter array size"<<endl;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // printArray(a,0,n);
    // cout<<endl;
    // cout<<"Max element is "<<findMax(a,0,n);
    cout<<findSum(a,0,n);
    return 0;
}