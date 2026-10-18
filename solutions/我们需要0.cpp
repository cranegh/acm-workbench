#include<iostream>
using namespace std;
using ll = long long;
int a[1010];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int t;cin>>t;
    while(t--){
        int n; cin>>n;
        for (int i=1 ; i<=n ; i++){
            cin>>a[i];
        }
        int x=0;
        for (int i=1 ; i<=n ; i++){
            x^=a[i];
        }
        cout<<x<<'\n';
    }
    return 0;
}