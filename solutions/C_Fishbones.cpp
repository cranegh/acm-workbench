#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int M = 2e5+9;
int a[15],b[15];
string s[M];
bool has_char[15][15][30];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>a[i]>>b[i];
    }

    int m; cin>>m;
    for(int i=1 ; i<=m ; i++){
        cin>>s[i];
        int len=s[i].length();

        for(int j=0 ; j<len ; j++){
            char cur_ch=s[i][j];
            has_char[len][j+1][cur_ch-'a']=true;
        }
    }

    for(int i=1 ; i<=m ; i++){
        string cur_s=s[i];

        if(cur_s.length()!=n){
            cout<<"No\n";
            continue;
        }

        bool PP=true;
        for(int j=1 ; j<=n ; j++){
            int len=a[j];
            bool p = false;
            if(has_char[len][b[j]][cur_s[j-1]-'a']) p=true;

            if(p==false){
                PP=false;
                break;
            }
        }

        if(PP) cout<<"Yes\n";
        else cout<<"No\n";
    }

    return 0;
}