#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
int pos[3][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    string s[3];
    for(int i=0 ; i<3 ; i++) cin>>s[i];

    for(int i=0 ; i<3 ; i++){
        int idx = 0;
        for(int j=0 ; j<s[i].length() ; j++){
            if(s[i][j]=='1') pos[i][idx++] = j;
        }
    }

    ll ans = 0;
    string ss(2*n,'0');

    for(int i=0 ; i<n ; i++){
        int a = pos[0][i];
        int b = pos[1][i];
        int c = pos[2][i];
        int v[3] = {a,b,c};
        sort(v,v+3);

        ans += abs(1ll*pos[0][i] - v[1]);
        ans += abs(1ll*pos[1][i] - v[1]);
        ans += abs(1ll*pos[2][i] - v[1]);
        ss[v[1]] = '1';
    }

    cout<<ans<<'\n';
    cout<<ss;

    return 0;
}