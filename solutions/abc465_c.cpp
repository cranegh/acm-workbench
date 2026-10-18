#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    string s; cin>>s;
    
    deque<int> dq;
    bool rev = false;
    for(int i=0 ; i<n ; i++){
        if(s[i]=='o'){
            if(!rev){
                dq.push_back(i+1);
            }else if(rev){
                dq.push_front(i+1);
            }
            rev = !rev;
        }else if(s[i]=='x'){
            if(!rev){
                dq.push_back(i+1);
            }else if(rev){
                dq.push_front(i+1);
            }
        }
    }
    
    if(!rev){
        for(int i=0 ; i<n ; i++) cout<<dq[i]<<" ";
    }else if(rev){
        for(int i=n-1 ; i>=0 ; i--) cout<<dq[i]<<" ";
    }
    
    return 0;
}