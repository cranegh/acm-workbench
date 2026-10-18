// KMP
// 拼接串前缀函数，输出匹配起点和模式串 pi；O(n+m)
// 原程序：读入正文 s1、模式 s2；两串非空且不含 #；输出起点为 1-index
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s1,s2; cin>>s1>>s2;
    string s = s2 + '#' + s1;
    vector<int> pi(s.length());

    for(int i=1 ; i<s.length() ; i++){
        int len = pi[i-1];
        while(s[i]!=s[len] && len){
            len = pi[len-1];
        }
        if(s[i] == s[len]){
            pi[i] = len+1;
        }
        if(pi[i] == s2.length()) cout<<i-2*s2.length()+1<<'\n';
    }

    for(int i=0 ; i<s2.length() ; i++) cout<<pi[i]<<" ";


    return 0;
}