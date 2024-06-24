#include<bits/stdc++.h>
using namespace std;
int frogJump(int *a,int idx,int n){
    if(idx==n-1) return 0;
    if(idx==n-2) return frogJump(a,idx+1,n)+abs(a[idx]-a[idx+1]);
    int smallJump=frogJump(a,idx+1,n)+abs(a[idx]-a[idx+1]);
    int bigJump=frogJump(a,idx+2,n)+abs(a[idx]-a[idx+2]);
    return min(smallJump,bigJump);
}
int main(){
    int a[4]={10,30,40,20};
    cout<<frogJump(a,0,4);
    return 0;
}