#include<iostream>

using namespace std;
using ll = long long;

const int N = 100;
int a[8][8];
int b[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int h,w,n; cin>>h>>w>>n;
    for(int i=1 ; i<=h ; i++)
        for(int j=1 ; j<=w ; j++)
            cin>>a[i][j];

    for(int i=1 ; i<=n ; i++) cin>>b[i];

    ll ans=0,cnt=0;
    for(int i=1 ; i<=h ; i++){
        cnt=0;
        for(int j=1 ; j<=w ; j++){
            for(int k=1 ; k<=n ; k++){
                if(a[i][j]==b[k]) cnt++;
            }
        }
        ans=max(ans,cnt);
    }

    cout<<ans;

    return 0;
}