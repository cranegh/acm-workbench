#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e6+9;

int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    string s; cin>>s;
    int len = s.length();
    vector<int> v(len);
    for(int i=0 ; i<s.length() ; i++){
        v[i]=s[i]-'A';
    }

    //for(int &i : v) cout<<i<<' ';

    ll sum=0;
    for(int i=0 ; i<26 ; i++){
        ll cur=0;
        for(int j=0 ; j<len ; j++){
            cur+=holes_cnt[(v[j]+i)%26];
        }
        sum=max(sum,cur);
    }

    cout<<sum;

    return 0;
}