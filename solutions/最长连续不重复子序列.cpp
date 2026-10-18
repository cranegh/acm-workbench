#include<iostream>
#include<algorithm>
using namespace std;
using ll =long long;

const int N = 1e5+9;
int a[N],c[N];

void solve();

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int t; cin>>t;
    while(t--) solve();
    return 0;

}

void solve(){
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    for(int i=1 ; i<=n ; i++) c[a[i]]=0;

    int l=0;
    for(int i=1,j=0 ; i<=n ; i++)
    {
        while(j<n && !(c[a[j+1]]) ){
            c[a[++j]]++;
        }
        l=max(l,j-i+1);
        c[a[i]]--;
    }
    cout<<l;
}