// Manacher
// 最长回文子串长度；O(n)
// 原程序：读入非空字符串；输入不可含 @/#/$；输出最长回文长度
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string ss; cin>>ss;

    string s = "@";
    for(char c : ss){
        s += '#';
        s += c;
    }
    s += "#$";

    int n = s.length();
    vector<int> p(n);

    int C=0,R=0;
    for(int i=1; i<n-1; i++){
        int j = 2*C-i;
        if(i<R) p[i] = min(R-i,p[j]);
        while(s[i+p[i]+1] == s[i-p[i]-1]) p[i]++;
        if(i+p[i] > R){
            C = i;
            R = i+p[i];
        }
    }

    int ans =  *max_element(p.begin(),p.end());
    cout<<ans;

    return 0;
}