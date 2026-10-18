#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct modify{
    int idx;
    char ch;
    int val;
    bool operator < (const modify& u) const{
        return idx<u.idx;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s,t; cin>>s>>t;
    vector<modify> ans1;
    vector<modify> ans2;

    for(int i=0; i<s.length(); i++){
        if(s[i] != t[i]){
            int val = t[i] - s[i];
            if(val < 0)
                ans1.push_back({i,t[i],val});
            else
                ans2.push_back({i,t[i],val});
        }
    }

    sort(ans1.begin(),ans1.end());
    sort(ans2.begin(),ans2.end());
    reverse(ans2.begin(),ans2.end());

    cout<<ans1.size()+ans2.size()<<'\n';
    string cur = s;
    for(auto[idx,ch,val] : ans1){
        cur[idx] = ch;
        cout<<cur<<'\n';
    }
    
    for(auto[idx,ch,val] : ans2){
        cur[idx] = ch;
        cout<<cur<<'\n';
    }



}