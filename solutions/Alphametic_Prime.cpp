#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 10000005;
bitset<N> vis;
vector<int> prime;

void init()
{
    vis[0] = true;
    vis[1] = true;
    for(int i=2; i<N; i++){
        if(!vis[i]){
            prime.push_back(i);
            for(int j=i+i; j<N; j+=i) vis[j] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    init();
    string s; cin>>s;
    int n = s.length();

    bool had = false;
    for(int &x : prime){
        string c = to_string(x);
        if(c.length() != n) continue;

        bool pp = true;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if((c[i] == c[j] && s[i] != s[j]) || (c[i] != c[j] && s[i] == s[j])){
                    pp = false;
                    break;
                }
            }
        }

        if(pp){
            had = true;
            cout<<x;
            break;
        }
    }

    if(!had) cout<<-1;

    return 0;
}