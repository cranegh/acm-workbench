#include<bits/stdc++.h> 

using namespace std;
using ll = long long;

int main( )
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0 ; i<n ; i++) cin>>a[i];

    int cnt = 0;
    int x = 0;
    int mx = 0;

    bool only = true;
    for(int i=0 ; i<n ; i++){
        if(a[i]==-1) x++;
        else{
            if(mx == a[i]) only = false;
            if(mx<a[i]){
                mx = a[i];
                only = true;
            }
            cnt += a[i];
        }
    }

    if(x==0){
        for(int i=0 ; i<n ; i++){
            int cur_x = i+1;
            if(a[i]==mx) cout<<cur_x;
        }
        return 0;
    }

    
    int possible_mx = n-cnt;
    int possible_mn = (n-cnt+x-1)/x;

    for(int i=0 ; i<n ; i++){
        int cur_x = i+1;
        if(a[i]==-1){
            if(possible_mx>mx) cout<<cur_x<<" ";
        }else{
            if((a[i]==mx) && only && (a[i]>possible_mn)) cout<<cur_x<<" ";
        }
    }
    

    return 0;
}