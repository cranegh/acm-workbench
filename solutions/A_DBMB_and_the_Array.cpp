#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stack>

using namespace std;
using ll = long long;

const int N = 12;
int a[N];

void solve()
{
    int n,s,x; cin>>n>>s>>x;
    ll sum=0;
    for(int i=1 ; i<=n ; i++){
        cin>>a[i];
        sum+=a[i];
    }

    if(s<sum) cout<<"NO\n";
    else{
        ll rem=s-sum;
        if(rem%x==0) cout<<"YES\n";
        else cout<<"NO\n";
    }
} 

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}