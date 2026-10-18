#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,q; cin>>n>>q;
    vector<int> p1(n+1);
    vector<int> p2(n+1);
    for(int i=1 ; i<=n ; i++) cin>>p1[i];
    for(int i=1 ; i<=n ; i++) p2[p1[i]] = i;
    
    int cnt2 = 0;
    for(int i=0 ; i<q ; i++){
        int op; cin>>op;
        if(op==1){
            int x,y; cin>>x>>y;
            swap(p1[x],p1[y]);
            swap(p2[p1[x]],p2[p1[y]]);

        }else if(op==2){
            swap(p1,p2);
        }
    }

    for(int i=1 ; i<=n ; i++) cout<<p1[i]<<" ";

    return 0;
}