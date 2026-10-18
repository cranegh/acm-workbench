#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 110;
string name[N], vote[N];
int cnt[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m; cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>name[i];
    for(int i=1; i<=m; i++) cin>>vote[i];

    for(int i=1; i<=m; i++){
        int canmatch = 0;
        bool ext = false;
        int p = 0;
        
        for(int j=1; j<=n; j++){
            int curd = 0;
            if(vote[i].length() == name[j].length()){
                for(int k=0; k<name[j].length(); k++){
                    if(vote[i][k] != name[j][k]) curd++;
                }
                if(curd == 1){
                    canmatch++;
                    p = j;
                }
                else if(curd == 0){
                    ext = true;
                    cnt[j]++;
                }
            }
        }

        if(!ext && canmatch == 1){
            cnt[p]++;
        }
    }

    for(int i=1; i<=n; i++){
        cout<<cnt[i]<<'\n';
    }

    return 0;
}