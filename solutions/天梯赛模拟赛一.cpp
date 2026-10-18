#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<set>
#include<map>

using namespace std;
using ll = long long;

const int N = 109;
string s[N];
char ch[N];

map<string,char> mp;

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n,m; cin>>n>>m;
    for(int i=1 ; i<=n ; i++) cin>>s[i]>>ch[i];
    for(int i=1 ; i<=n ; i++) mp[s[i]]=ch[i];
    
    for(int i=1 ; i<=m ; i++){
        string q; cin>>q;
        vector< pair<int,string> > cur;
        for(int j=1 ; j<=n ; j++){
            int idx=q.find(s[j]);
            if(idx!=-1) cur.push_back({idx,s[j]});
        }

        if(cur.empty()){
            cout<<'D'<<'\n';
            continue;
        }
        sort(cur.begin(),cur.end());
        
        if(cur[0].first!=0){
            cout<<'D'<<'\n';
            continue;
        }
        bool D=0;
        for(int i=0 ; i<cur.size()-1 ; i++){
            if(cur[i].first+cur[i].second.size()!=cur[i+1].first){
                cout<<'D'<<'\n';
                D=1;
                break;
            }
        }
        if(D) continue;
        if(cur[cur.size()-1].first+cur[cur.size()-1].second.size()!=q.size()){
            cout<<'D'<<'\n';
            continue;
        }

        for(int i=0 ; i<cur.size() ; i++) cout<<mp[cur[i].second];
        cout<<'\n';
    }

    return 0;
}