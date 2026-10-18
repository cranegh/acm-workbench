#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,q; cin>>n>>q;
    vector<int> p(n);
    for(int i=0; i<n; i++) cin>>p[i];
    vector<int> cnt(n+1,0);
    
    for(int i=0; i<q; i++){
        int a; cin>>a;
        p.push_back(a);
        cnt[a]++;
    }

    vector<int> had(n+1,0);
    for(int i=0; i<p.size(); i++){
        int c = p[i];
        if(had[c] == cnt[c]) cout<<c<<" ";
        else had[c]++;
    }

    return 0;
}