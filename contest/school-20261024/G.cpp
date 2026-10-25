#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int T,k;
void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    
    if(n%2){
        cout<<-1<<endl;
        return;
    }

    assert(n%2==0);
    vector<int> ans(3*n,1);
    int mid = 3*n/2;

    if(s.substr(0,mid) == s.substr(mid)){
        cout<<1<<'\n';
        for(int i=0; i<3*n; i++) cout<<ans[i]<<" ";
        cout<<'\n';
        return;
    }

    for(int i=0; i<mid; i+=3){
        string s1 = s.substr(i,3);
        string s2 = s.substr(i+mid,3);

        if(s1 == s2) continue;

        if(s1 == "COW" && s2 == "OWC"){
            ans[i] = 2;
            ans[i+mid+2] = 2;
        }
        else if(s1 == "COW" && s2 == "WCO"){
            ans[i+2] = 2;
            ans[i+mid] = 2;
        }
        else if(s1 == "OWC" && s2 == "WCO"){
            ans[i] = 2;
            ans[i+mid+2] = 2;
        }
        else if(s1 == "OWC" && s2 == "COW"){
            ans[i+2] = 2;
            ans[i+mid] = 2;
        }
        else if(s1 == "WCO" && s2 == "COW"){
            ans[i] = 2;
            ans[i+mid+2] = 2;
        }
        else if(s1 == "WCO" && s2 == "OWC"){
            ans[i+2] = 2;
            ans[i+mid] = 2;
        }
    }

    cout<<2<<'\n';
    for(int x : ans) cout<<x<<" ";
    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>T>>k;
    while(T--) solve();

    return 0;

}