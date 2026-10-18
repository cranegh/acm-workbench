#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    
    string s; cin>>s;

    int cnt0=0; int cnt1 = 0; int cnt25 = 0;
    for(int i=0 ; i<s.length() ; i++){
        int num = (s[i]-'0');
        if(num==0) cnt0++;
        else if(num==1) cnt1++;
        else if(num<=5) cnt25++;
    }
    int cnt69=n-cnt0-cnt1-cnt25;

    int ans=0;
    while(1){
        if(cnt0>0){
            cnt0--;

            if(cnt69>0) cnt69--;
            else if(cnt25>0) cnt25--;
            else if(cnt1>0) cnt1--;
            else if(cnt0>0) cnt0--;
            else break;

            if(cnt25>0) cnt25--;
            else if(cnt1>0) cnt1--;
            else if(cnt0>0) cnt0--;
            else break;

            if(cnt69>0) cnt69--;
            else if(cnt25>0) cnt25--;
            else if(cnt1>0) cnt1--;
            else if(cnt0>0) cnt0--;
            else break;

            ans++;
        }else if(cnt1>=2){
            cnt1-=2;
            
            if(cnt25>0) cnt25--;
            else if(cnt1>0) cnt1--;
            else if(cnt0>0) cnt0--;
            else break;

            if(cnt69>0) cnt69--;
            else if(cnt25>0) cnt25--;
            else if(cnt1>0) cnt1--;
            else if(cnt0>0) cnt0--;
            else break;

            ans++;
        }else break;
    }

    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}