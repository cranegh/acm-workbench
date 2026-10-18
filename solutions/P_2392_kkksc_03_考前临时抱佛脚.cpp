#include<iostream>
#include<algorithm>

using namespace std;
using ll = long long;

int a[22];
int maxdeep,nowtime,sum,maxtime,ans=0;

void dfs(int x){
    if(x>maxdeep){
        maxtime=max(maxtime,nowtime);
        return;
    }
    if(nowtime+a[x]<=sum/2){
        nowtime+=a[x];
        dfs(x+1);
        nowtime-=a[x];
    }

    dfs(x+1);

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int s[4];
    for(int i=0 ; i<4 ; i++) cin>>s[i];

    for(int i=0 ; i<4 ; i++){
        nowtime=0;
        maxdeep=s[i];
        sum=0;
        for(int j=1 ; j<=s[i] ; j++){
            cin>>a[j];
        }
        for(int j=1 ; j<=s[i] ; j++){
            sum+=a[j];
        }
        maxtime=0;
        dfs(1);
        ans+=(sum-maxtime);
    }

    cout<<ans;

    return 0;
}