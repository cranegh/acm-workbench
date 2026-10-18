#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1005;
int a[10];
int w[10];
bool dp[N];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    for(int i=1; i<=6; i++) cin>>a[i];
    w[1] = 1;
    w[2] = 2;
    w[3] = 3;
    w[4] = 5;
    w[5] = 10;
    w[6] = 20;

    int sum = 0;
    for(int i=1; i<=6; i++)
        sum += a[i] * w[i];

    dp[0] = true;
    for(int i=1; i<=6; i++){
        for(int j=1; j<=a[i]; j++){
            for(int k=sum; k>=w[i]; k--)
            dp[k] |= dp[k-w[i]];
        }
    }

    int ans = 0;
    for(int i=1; i<=sum; i++)
        if(dp[i]) ans++;

    cout << "Total=" << ans << '\n';

    return 0;
}