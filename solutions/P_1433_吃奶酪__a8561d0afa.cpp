#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 20;
const ll INF = 0x3f3f3f3f3f3f3f3f;

double x[N], y[N];
double dis[N][N];

double dp[1<<N][N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>x[i]>>y[i];

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            double dx = x[i] - x[j];
            double dy = y[i] - y[j];
            dis[i][j] = sqrt((dx*dx) + (dy*dy));
        }
    }

    int All = 1<<n;
    for(int S=0; S<All; S++){
        for(int i=1; i<=n; i++){
            dp[S][i] = INF;
        }
    }

    for(int i=1; i<=n; i++){
        dp[1<<(i-1)][i] = sqrt(x[i]*x[i] + y[i]*y[i]);
    }

    for(int S=0; S<All; S++){
        for(int i=1; i<=n; i++){
            if(!(S>>(i-1) & 1)) continue;
            if(dp[S][i] == INF) continue;

            for(int j=1; j<=n; j++){
                if(S>>(j-1) & 1) continue;

                int nS = S|1<<(j-1);
                dp[nS][j] = min(
                    dp[nS][j],
                    dp[S][i]+dis[i][j]
                );
            }
        }
    }

    int full = All-1;
    double ans = INF;

    for(int i=1; i<=n; i++){
        ans = min(ans,dp[full][i]);
    }

    cout<<fixed<<setprecision(2);
    cout<<ans;

}