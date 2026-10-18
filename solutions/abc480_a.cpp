#include<bits/stdc++.h>

using namespace std;
using ll = long long;

char a[3][3];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for(int i=1; i<=2; i++){
        for(int j=1; j<=2; j++){
            cin>>a[i][j];
        }
    }

    bool ok = true;
    if(a[1][1] == 'A' && a[2][2] == 'D') ok = false;
    if(a[1][1] == 'D' && a[2][2] == 'A') ok = false;
    if(a[1][2] == 'A' && a[2][1] == 'D') ok = false;
    if(a[1][2] == 'D' && a[2][1] == 'A') ok = false;

    if(ok) cout<<"Yes\n";
    else cout<<"No\n";

    return 0;
}