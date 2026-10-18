#include<iostream>
using namespace std;
const int N = 110;
char a[N][N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++)
            cin>>a[i][j];

    for(int i=1 ; i<=n ; i++)
        for(int j=1 ; j<=m ; j++){
            int cnt=0;
            if(a[i][j]=='?'){
                if(a[i-1][j-1]=='*') cnt++;
                if(a[i-1][j]=='*') cnt++;
                if(a[i-1][j+1]=='*') cnt++;
                if(a[i][j-1]=='*') cnt++;
                if(a[i][j+1]=='*') cnt++;
                if(a[i+1][j-1]=='*') cnt++;
                if(a[i+1][j]=='*') cnt++;
                if(a[i+1][j+1]=='*') cnt++;
                a[i][j]=cnt+'0';
            }
        }
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cout<<a[i][j];
        }
        cout<<'\n';
    }

    return 0;
}