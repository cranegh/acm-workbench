#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 105;
int cnt[N];

int main(){
    int n; cin>>n;

    for(int i=1 ; i<=n ; i++){
        int a; cin>>a;
        cnt[a]++;
    }

    int ans = 0;
    for(int i=1 ; i<=100 ; i++){
        if(cnt[i]%2) ans += i;
    }

    cout<<ans;

    return 0;
}