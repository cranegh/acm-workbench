#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    cout<<2*n<<'\n';

    for(int i=0 ; i<n ; i++){
        int x = i/10;
        int y = i%10;
        double xx = x*0.011;
        double yy = y*0.011;

        cout<<xx<<" "<<yy<<" "<<0<<'\n';
    }
    
    for(int i=0 ; i<n ; i++){
        int x = i/10;
        int y = i%10;
        double xx = x*0.011;
        double yy = y*0.011;
    
        cout<<xx<<" "<<yy<<" "<<1<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}