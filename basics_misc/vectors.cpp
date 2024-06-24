#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector <int> v ;
    v.push_back(5);
      cout<<"Size:"<<v.size()<<endl<<"Capacity :"<<v.capacity();
    v.push_back(10);
      cout<<"Size:"<<v.size()<<endl<<"Capacity :"<<v.capacity();
    v.push_back(20);
      cout<<"Size:"<<v.size()<<endl<<"Capacity :"<<v.capacity();
    v.push_back(35);
    v.push_back(6);
    cout<<"Size:"<<v.size()<<endl<<"Capacity :"<<v.capacity();
    int a[5];
    for(int i=0;i<5;i++){
      cin>>a[i];
    }
    for(int i=0;i<5;i++){
      cout<<a[i]<<" ";
    }
    
        return 0;
}