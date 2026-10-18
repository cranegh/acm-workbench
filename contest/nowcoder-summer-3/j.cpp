#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;cin>>n;
    //cout<<n<<endl;
    vector<bool>vis(n);
    if(n==1){
        cout<<1<<endl;
        cout<<1<<" "<<1<<endl;
    }
    else  if(n<=4){
        cout<<n-1<<endl;
        for(int i=1;i<=n-1;i++){
            cout<<i<<" "<<i<<endl;
        }
    }
    else {
        int a1=2,b1=3;
        int a2=3,b2=2;
        vis[a1]=1;
        vis[a2]=1;
        vector<pair<int,int>>ans;
        ans.push_back({1,1});
        
        int k=1;
        for(int i=2;i<=n;i+=2){
            ans.push_back({a1,b1});
            ans.push_back({a2,b2});
            k++;
            //a1++;
            while(vis[a1])a1++;
            a2=a1+k;
            vis[a1]=1;vis[a2]=1;
            b1=a2;b2=a1;
            if(b1>n)break;
        }
        cout<<ans.size()<<endl;
        for(auto [x,y]:ans){
            cout<<x<<" "<<y<<endl;
        }
    }
}