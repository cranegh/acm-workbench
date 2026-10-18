#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    vector<int> a(n,0);
    vector<int> pos;
    int ans = 0;

    for(int i=0 ; i<q ; i++){
        int op; cin>>op;
        if(op==1){
            int x; cin>>x;
            if(a[x-1] == 0) pos.push_back(x-1);
            ans ^= (a[x-1]);
            ans ^= (++a[x-1]);
        }else if(op==2){
            int idx = 0;
            for(int& cur : pos){
                if(a[cur]>0){
                    ans ^= (a[cur]);
                    ans ^= (--a[cur]);
                }
                if(a[cur]>0) pos[idx++] = cur;
            }
            pos.resize(idx);
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}