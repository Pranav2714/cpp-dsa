#include <bits/stdc++.h>
using namespace std;
string countSort( string &str){
      vector <int> freq(26,0);
    for (int i = 0; i < str.size(); i++)
    { // creating a frequency array
        int idx = str[i] - 'a';
        freq[idx]++;
    } 
    int j=0;
    for(int i=0;i<26;i++){
     while(freq[i]--){
        str[j++]=i+'a';
     }
    }
    return str;
}
int main()
{
    string str = "dcba";
  
    string ans = countSort(str);
    cout<<ans;
    

    return 0;
}