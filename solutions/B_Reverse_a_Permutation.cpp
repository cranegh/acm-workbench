#include<iostream>
#include<algorithm>
#include<iomanip>
#include<stack>

using namespace std;
using ll = long long;

const int N = 2e5+9;
int a[N];

void solve()
{
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>a[i];

    int l=1;
    int mlen=n;
    while(a[l]==mlen){
        l++;
        mlen--;
    }
    int r=0;
    for(int i=1 ; i<=n ; i++){
        if(a[i]==mlen){
            r=i;
            break;
        }
    }

    reverse(a+l,a+1+r);
    for(int i=1 ; i<=n ; i++) cout<<a[i]<<' ';
    cout<<'\n';

} 

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; cin>>_;
    while(_--) solve();

    return 0;
}