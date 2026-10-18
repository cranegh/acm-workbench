#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    multiset<int> a;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        a.insert(x);
    }

    vector<int> b(n);
    for(int i=0; i<n; i++) cin>>b[i];

    int ans = 0;

    for(int i=0; i<n; i++){
        int cur = b[i];

        auto it = a.upper_bound(cur);
        if(it == a.end()){
            a.erase(*a.begin());
        }else{
            ans++;
            a.erase(*it);
        }
    }

    cout<<ans;

}