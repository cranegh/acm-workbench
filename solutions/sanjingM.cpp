#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    ll l,r;
    ll ans=1;
    
    for(int i=0 ; i<n ; i++)
    {
        cin>>l>>r;
        int o=r-l+1;
        ans*=o;
    }
   
    if(ans<=1e5) cout<< "NO TLE";
    else if(ans>1e7) cout<< "TLE";
    else cout<< "POSSIBLE";

    return 0;
}
