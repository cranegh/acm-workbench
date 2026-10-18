#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 200005;
int p[N], cnt[N], under[N], ans[N];
set<int> st;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>p[i];

    for(int i=1; i<=n; i++){
        int x = p[i];
        auto it = st.lower_bound(x);
        if(it == st.end()){
            st.insert(x);
            cnt[x] = 1;
        }else{
            int y = *it;
            st.insert(x);
            st.erase(y);
            under[x] = y;
            cnt[x] = cnt[y]+1;
        }

        if(cnt[x] == k){
            ans[x] = i; 
            int cur = x;
            while(under[cur]){
                cur = under[cur];
                ans[cur] = i;
            }
            st.erase(x);
        }
        
    }

    for(int i=1; i<=n; i++){
        int cur = -1;
        if(ans[i]) cur = ans[i];
        cout<<cur<<'\n';
    }

    return 0;
}