#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005;
ll a[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,k,x; cin>>n>>k>>x;
    for(int i=1; i<=n; i++) cin>>a[i];
    
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    ll cost = 0;
    int num = 0;

    for(int i=1; i<=n; i++){
        ll sp = (num+1)*x + k;
        if(sp < a[i]){
            cost += sp;
            num++;
        }
        else{
            cost += a[i];
        }
    }

    cout<<cost<<endl;


}