#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string s; cin>>s;
    int q; cin>>q;
    
    int m = s.length();
    vector<int> nxtl(m+1,-1);
    vector<int> nxtr(m+1,-1);
    vector<int> nxtlr(m+1,-1);
    
    for(int i=m-1; i>=0; i--){
        nxtl[i] = nxtl[i+1];
        nxtr[i] = nxtr[i+1];
        nxtlr[i] = nxtlr[i+1];
        
        if(s[i] == 'L') nxtl[i] = i; 
        if(s[i] == 'R') nxtr[i] = i; 
        if(i+1<m && s[i] == 'L' && s[i+1] == 'R') nxtlr[i] = i; 
    }
    
    for(int k=0; k<q; k++){
        bool pp = true;
        string t; cin>>t;
        int len = t.length();
        
        if(t[0] == 'R' && s[0] != 'R'){
            cout<<"NO\n";
            continue;
        }
        
        if(t.back() == 'L' && s.back() == 'R'){
            cout<<"NO\n";
            continue;
        }
        
        int p = 0;
        for(int i=0; i<len-1; i++){
            if(t[i] == 'L' && t[i+1] == 'L'){
                p = nxtl[p];
                if(p == -1){
                    pp = false;
                    break;
                }
                p++;
            }
            else if(t[i] == 'L' && t[i+1] == 'R'){
                p = nxtlr[p];
                if(p == -1){
                    pp = false;
                    break;
                }
                p++;
            }
            else if(t[i] == 'R' && t[i+1] == 'L'){
                p++;
            }
            else if(t[i] == 'R' && t[i+1] == 'R'){
                p = nxtr[p+1];
                if(p == -1){
                    pp = false;
                    break;
                }
            }
            
            if(p >= m){
                pp = false;
                break;
            }
        }
        
        
        if(pp){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}