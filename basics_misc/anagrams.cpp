#include<bits/stdc++.h>
using namespace std;
bool checkAnagram(string s1, string s2){
    vector<int> freq(26,0);
    if(s1.length()!=s2.length()) return false;
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
        freq[s2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }
    return true;
}
int main(){
    string str1="anagram";
    string str2="nagaram";
    cout<<checkAnagram(str1,str2)<<endl;
    return 0;
}