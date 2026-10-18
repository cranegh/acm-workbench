#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n,k; cin>>n>>k;
    string s; cin>>s;

    int nn = 0;
    for(int i=0 ; i<n ; i++) if(s[i]==')') nn++;

    int aans = n;

    int kk = 0;
    
    for(int k1 = 0 ; k1<=k ; k1++){
        int k2 = k - k1;

        int end = nn-k2; 

        string ss = "";
        int n1 = 0;
        int n2 = 0;
        for(int i=0 ; i<n ; i++){
            char ch = s[i];

            if(ch=='('){
                if(++n1>k1) ss+='(';
            }else if(ch==')'){
                if(++n2<=end) ss+=')';
            }
        }

        int cnt = 0;
        int ans = 0;
        for(int i=0 ; i<ss.length() ; i++){
            if(ss[i]=='(') cnt++;
            else if(ss[i]==')'){
                if(cnt>0){
                    ans++;
                    cnt--;
                }
            }
        }
        
        if(ans<aans){
            kk = k1;
            aans = ans;
        }
    }

    vector<bool> flag(n,false);

    int k2 = k - kk;
    int end = nn-k2; 
    
    string ss = "";
    int n1 = 0;
    int n2 = 0;
    for(int i=0 ; i<n ; i++){
        char ch = s[i];

        if(ch=='('){
            if(++n1>kk) flag[i] = true;
        }else if(ch==')'){
            if(++n2<=end) flag[i] = true;
        }
    }

    for(int i=0 ; i<n ; i++){
        if(!flag[i]) cout<<1;
        else if(flag[i]) cout<<0;
    }

    cout<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();
    
    return 0;
}