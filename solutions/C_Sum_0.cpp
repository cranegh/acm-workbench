#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

const int N = 2e5+9;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    vector<ll> vl(n+1);
    vector<ll> vr(n+1);

    ll suml=0,sumr=0;
    for(int i=1 ; i<=n ; i++){
        cin>>vl[i]>>vr[i];
        suml+=vl[i];
        sumr+=vr[i];
    }

    if(suml>0 || sumr<0){
        cout<<"No\n";
        return 0;
    }else cout<<"Yes\n";

    ll cur_sum=suml;
    ll tar=0-suml;

    for(int i=1 ; i<=n ; i++){
        ll cur=min(vr[i]-vl[i],tar);

        vl[i]+=cur;
        tar-=cur;

        if(tar==0) break;
    }

    for(int i=1 ; i<=n ; i++) cout<<vl[i]<<' ';
    cout<<'\n';

    return 0;
}