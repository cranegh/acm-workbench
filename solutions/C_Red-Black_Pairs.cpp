#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<vector<bool>> vis(2,vector<bool>(n));
    vector<vector<char>> s(2,vector<char>(n));
    string ss;
    cin>>ss; for(int i=0 ; i<n ; i++) s[0][i]=ss[i];
    cin>>ss; for(int i=0 ; i<n ; i++) s[1][i]=ss[i];

    int cnt=0;
    for(int i=0 ; i<n ; i++)
    {
        if(s[0][i]==s[1][i]){
            cnt++;
            vis[0][i]=1;
            vis[1][i]=1;
        }
    }

    for(int i=0 ; i<2 ; i++){
        for(int j=0 ; j<n ; j++){
            if(vis[i][j]) continue;
            if(j+1<n && !vis[i][j+1] && s[i][j]==s[i][j+1]){
                cnt++;
                vis[i][j]=1; vis[i][j+1]=1;
            }
        }
    }

    cout<<n-cnt<<'\n';

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin>>T;
    while(T--) solve();
    
    return 0;
}