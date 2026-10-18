#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string ss; cin>>ss;
    string s = "Rounddo";
    int n; cin>>n;
    for(int i=0 ; i<n ; i++) s+="g";

    
    int slen = s.length();
    int sslen = ss.length();
    vector<int> diff(2*sslen,0);

    ss += ss;

    for(int i=0 ; i+slen <= 2*sslen ; i++){
        if(ss[i]=='R'){
            if(ss.substr(i,slen)==s){
                int l = max(0,i+slen-sslen);
                int r = min(i,sslen-1); 
                diff[l]++;
                diff[r+1]--;
            }
       }
    }

    int sum = 0;
    int ans = 0;

    for(int i=0 ; i<sslen ; i++){
        sum += diff[i];
        if(sum>0) ans++;
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}
