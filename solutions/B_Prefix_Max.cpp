#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e4+9;

void solve()
{
    int max_v=0;
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        int temp; cin>>temp;
        max_v=max(max_v,temp);
    }
    max_v*=n;
    cout<<max_v<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}