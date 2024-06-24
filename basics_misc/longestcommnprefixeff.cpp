#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector <string> &str){
    string s1=str[0];
    int ans_length=s1.size();
    for(int i=1;i<str.size();i++){
        int j=0;
        while(j<s1.size() && j<str[i].size() && s1[j]==str[i][j]){
            j++;
        }
        ans_length=min(ans_length,j);
    }
    string ans = s1.substr(0,ans_length);
    return ans;
}
int main(){
    cout<<"Enter number of strings"<<endl;
    int n;
    cin>>n;
    vector <string> v(n);
    cout<<"Enter strings"<<endl;
    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    cout<<"Longest common prefix is :"<<longestCommonPrefix(v);
    return 0;
}