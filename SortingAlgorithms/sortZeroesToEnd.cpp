#include<bits/stdc++.h>
using namespace std;
void sortZeroes(vector <int> &a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        int flag=false;
        for(int j=0;j<n-i-1;j++){
            if(a[j]==0 && a[j+1]!=0){
                swap(a[j],a[j+1]);
                flag=true;
            }
        }
        if(flag==false) break;
    }
}
int main(){
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sortZeroes(v);
    for(int ele : v){
        cout<<ele<<" ";
    }
    return 0;
}