#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;
using ll = long long;

const int N = 1e3+9;
ll d[N];

void solve()
{
    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>d[i];

    ll ans_n=0; ll m_h=0;
    vector<ll> va;
    vector<ll> vb;

    va.push_back(d[1]);

    for(int i=2 ; i<=n ; i++){
        if(d[i]<va[va.size()-1]) va.push_back(d[i]);
        else{
            if(vb.empty() || d[i]>vb[vb.size()-1]) vb.push_back(d[i]);
            else{
                ans_n++;
                ll cur_h=va.size();
                m_h=max(m_h,cur_h);
                va.clear();
                ll temp_h=vb.size();
                for(int j=1 ; j<=temp_h ; j++){
                    if(vb[temp_h-j]>d[i]) va.push_back(vb[temp_h-j]),vb.erase(vb.begin()+temp_h-j);
                }
                va.push_back(d[i]);
            }
        }
    }
    
    if(!va.empty()){
        ans_n++;
        ll cur_h=va.size();
        m_h=max(m_h,cur_h);
    }

    if(!vb.empty()){
        ans_n++;
        ll cur_h=vb.size();
        m_h=max(m_h,cur_h);
    }

    cout<<ans_n<<' '<<m_h;



}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int _; _=1;
    while(_--) solve();

    return 0;
}



