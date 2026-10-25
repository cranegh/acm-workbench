#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int cnt[32];
int tot = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;

    int mn = 0;
    int mx = n;

    for(int i=0; (1<<i)<=n; i++){
        if(n & (1<<i)){
            cnt[i]++;
            mn++;
        }
        
    }
    tot = mn;
    assert(tot == __builtin_popcount(n));

    if(mn<=k && k<=mx){
        cout<<"YES\n";
        for(int i=31; i>=0; i--){
            while(cnt[i]>0 && tot<k){
                cnt[i]--;
                cnt[i-1] += 2;
                tot++;
            }
        }
        for(int i=0; i<=31; i++){
            if(cnt[i]){
                for(int j=0; j<cnt[i]; j++){
                    cout<<(1<<i)<<" ";
                }
            }
        }
    }else{
        cout<<"NO\n";
    }

}
