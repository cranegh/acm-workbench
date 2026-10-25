#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int k;

void solve(){
    int n; cin>>n;
    string s; cin>>s;

    string ans = "";
    bool ud = false;
    for(int i=n-1; i>=0; i--){
        char u = s[i];
        
        if(!ud){
            if(u == 'M'){
                ans += 'M';
            }
            else{
                ans += 'O';
                ud = !ud;
            }
        }else{
            if(u == 'M'){
                ans += 'O';
                ud = !ud;
            }
            else{
                ans += 'M';
            } 
        }
    }
    reverse(ans.begin(),ans.end());

    cout<<"YES\n";
    if(k == 1) cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1; cin>>T>>k;
    while(T--) solve();

    return 0;
}