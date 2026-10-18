#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 35;
string s[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>s[i];

    int ans = 0;

    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){

            bool ok = true;
            for(int k=0; k<m; k++){
                if(s[i][k] == 'x' && s[j][k] == 'x'){
                    ok = false;
                    break;
                }
            }

            if(ok) ans++;

        }
    }

    cout<<ans<<endl;

}