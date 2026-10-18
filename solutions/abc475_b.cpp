#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005;
ll a[N];
int ans[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];

    for(int i=1; i<=n; i++){
        int cur = 1000 - a[i]%1000;

        for(int j=0; j<3; j++){
            ans[j] += cur%10;
            cur/=10;
        }

    }

    for(int i=0; i<3; i++) cout<<ans[i]<<" ";


    return 0;
}
