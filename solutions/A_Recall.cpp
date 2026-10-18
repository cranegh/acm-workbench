#include<bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n; cin>>n;
    vector<char> ch(n);
    vector<int> x(n);
    vector<int> die(n);
    map<int,int> mp; 

    for(int i=0; i<n; i++) cin>>ch[i]>>x[i];

    for(int i=n-1; i>=0; i--){
        if(mp.count(x[i])){
            die[i] = mp[x[i]];
        }else{
            die[i] = i;
        }

        if(ch[i] == 'T'){
            if(mp.count(x[i])==0) mp[x[i]] = i;
        }else if(ch[i] == '+'){
            mp.erase(x[i]);
        }else if(ch[i] == 'F'){
            mp.erase(x[i]);
        }
    }

    stack<int> st;
    for(int i=0; i<n; i++){
        if(ch[i] == '+'){
            cout<<'+';
            st.push(i);
        }else if(ch[i] == 'T'){
            cout<<'?';
        }else if(ch[i] == 'F'){
            cout<<'?';
        }

        while(!st.empty() && die[st.top()]<=i){
            st.pop();
            cout<<'-';
        }
    }
    cout<<'\n';
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}