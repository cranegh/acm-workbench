#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    ll a; cin>>a;
    int n; cin>>n;
    vector<int> d(n); for(int i=0 ; i<n ; i++) cin>>d[i];
    vector<bool> has(10,false); for(int i=0 ; i<n ; i++) has[d[i]] = true;

    //get da
    ll aa = a;
    vector<int> da;
    while(aa>0)
    {
        ll cc = aa%10;
        aa/=10;
        da.push_back(cc);
    }
    int len = da.size();

    //check equal to a
    aa = a; int nn = 0;
    if(aa==0 && has[0]){
        cout<<0<<'\n';
        return;
    }
    while(aa>0)
    {
        ll cc = aa%10;
        aa/=10;
        if(has[cc]) nn++;
    }
    if(nn==da.size()){
        cout<<0<<'\n';
        return;
    }

    //check smaller than a
    bool pp = false;
    for(int i=len-1 ; i>=0 ; i--){
        int j=n-1;
        int cur;
        while(da[i]<d[j] && j>=0) j--;
        if(j<0) cur = 0;
        else cur =  d[++j];
    }


}   

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}