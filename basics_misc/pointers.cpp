#include<bits/stdc++.h>
using namespace std;
int main(){
    int x =55;
    float y=9.7;

    int *ptr=&x;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    float *ptrf=&y;
    cout<<ptrf<<endl;
    

    *ptr=69;
    cout<<*ptr<<endl;
    cout<<x;
    return 0;
}