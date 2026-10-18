#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m,q; cin>>n>>m>>q;
    vector<bool> changedx(n+1,0);
    vector<bool> changedy(m+1,0);

    ll ans = 0;
    int cntx = 0;
    int cnty = 0;

    for(int i=0 ; i<q ; i++){
        int op,x; cin>>op>>x;
        if(op==1){
            if(!changedx[x]){
                ans += m;
                ans -= 2*cnty;
                cntx++;
            }else if(changedx[x]){
                ans -= m;
                ans += 2*cnty;
                cntx--;
            }
            changedx[x] = !changedx[x];
        }else if(op==2){
            if(!changedy[x]){
                ans += n;
                ans -= 2*cntx;
                cnty++;
            }else if(changedy[x]){
                ans -= n;
                ans += 2*cntx;
                cnty--;
            }
            changedy[x] = !changedy[x];
        }
        cout<<ans<<'\n';
    }
    
    return 0;
}