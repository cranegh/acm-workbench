#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>

using namespace std;
using ll = long long;

const int N = 110;

int next_x(int x){
    int res=1;
    while(x!=0){
        res*=x%10;
        x/=10;
    }
    return res;
}

int cxx(int x){
    int res=0;
    while(x>=10){
        res++;
        x=next_x(x);
    }
    return res;
}

vector<pair<int,int>> v;

void solve()
{
    int a,b; cin>>a>>b;
    for(int i=a ; i<=b ; i++){
        v.push_back({cxx(i),i});
    }
    sort(v.begin(),v.end());
    int max_cxx=v[v.size()-1].first;
    cout<<max_cxx<<'\n';

    bool flag=true;
    for(int i=0 ; i<v.size() ; i++){
        if(!flag) cout<<' ';
        if(v[i].first==max_cxx){
            cout<<v[i].second;
            flag=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; _=1;
    while(_--) solve();

    return 0;
}