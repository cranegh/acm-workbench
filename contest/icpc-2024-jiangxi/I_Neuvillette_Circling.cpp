#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 100+5;
double x[N];
double y[N];
pair<int,int> edge[5050];
vector<double> ans[N];
double r[5050];

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>x[i]>>y[i];

    int idx=0;
    for(int i=1 ; i<n ; i++){
        for(int j=i+1 ; j<=n ; j++){
            edge[idx++]={i,j};
        }
    }

    for(int i=1 ; i<=n ; i++){
        double xx=x[i];
        double yy=y[i];
        
        for(int j=0 ; j<n*(n-1)/2 ; j++){
            double cur_x1 = x[edge[j].first];
            double cur_y1 = y[edge[j].first];
            double cur_x2 = x[edge[j].second];
            double cur_y2 = y[edge[j].second];

            double d1 = dist(xx,yy,cur_x1,cur_y1);
            double d2 = dist(xx,yy,cur_x2,cur_y2);
    
            double cur_d = max(d1,d2);

            ans[i].push_back(cur_d);
        }

        sort(ans[i].begin(),ans[i].end());
        //for(double &x : ans[i]) cout<<x<<' ';
        //cout<<'\n';
    }

    for(int i=0 ; i<=n*(n-1)/2 ; i++) r[i]=2e4;

    for(int i=0 ; i<n*(n-1)/2 ; i++){
        for(int j=1 ; j<=n ; j++)
        r[i]=min(r[i],ans[j][i]);
    }

    for(int i=0 ; i<n*(n-1)/2 ; i++){
        cout<<fixed<<setprecision(8)<<r[i]<<'\n';
    }
    
    return 0;
}