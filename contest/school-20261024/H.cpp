#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 25;
int cnt[N][N][N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;
    for(int i=0; i<k; i++){
        int x,y,z; cin>>x>>y>>z;
        if(y>z) swap(y,z);

        cnt[x][y][z]++;
    }

    int ans = 0;
    int num = 0;

    int All = (1<<n);
    for(int i=0; i<All; i++){
        int cur_sore = 0;
        
        for(int x=1; x<=n; x++){
            if(i & (1<<(x-1))){
                for(int y=1; y<=n; y++){
                    if(i & (1<<(y-1))) continue;

                    for(int z=y+1; z<=n; z++){
                        if(i & (1<<(z-1))) continue;

                        cur_sore += cnt[x][y][z];
                    }
                }
            }
        }

        if(ans < cur_sore){
            ans = cur_sore;
            num = 1;
        }else if(ans == cur_sore){
            num++;
        }
    }

    cout<<ans<<" "<<num;

    return 0;
}