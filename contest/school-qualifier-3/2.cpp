#include<bits/stdc++.h>

using namespace std;
using ll = long long;

bool had[1000005];
bool cur_had[1000005];

void solve()
{
    int n; cin>>n;
    vector<vector<int>> v(n);

    for(int i=0 ; i<n ; i++){
        int k; cin>>k;
        for(int j=0 ; j<k ; j++){
            int tt; cin>>tt;
            v[i].push_back(tt);
        }
    }

    vector<int> ans;

    vector<bool> used(n,false);

    for(int i=0 ; i<n ; i++){
        vector<int> cur_best;
        int best_idx = -1;
        cur_best.push_back(1000000+5);

        for(int j=0 ; j<n ; j++){
            vector<int> cur;
            if(used[j]) continue;

            for(int k=v[j].size()-1 ; k>=0 ; k--){
                if(!had[v[j][k]] && !cur_had[v[j][k]]){
                    cur.push_back(v[j][k]);
                    cur_had[v[j][k]] = true;
                }
            }

            for(int &song : cur) cur_had[song] = false;

            if(cur<cur_best){
                cur_best = cur;
                best_idx = j;
            }
        }

        used[best_idx] = true;

        for(int &song : cur_best){
            ans.push_back(song);
            had[song] = true;
        }
    }

    for(int &song : ans) cout<<song<<" ";
    for(int &song : ans) had[song] = false;
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}