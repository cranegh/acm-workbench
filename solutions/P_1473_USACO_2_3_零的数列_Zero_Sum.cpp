#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>
#include<set>

using namespace std;
using ll = long long;

int n;
int ans=0;
char c[3]={' ','+','-'};

void dfs(int dep,int temp,int sign,int cnt,string s){
    if(dep==n){
        cnt+=sign*temp;
        if(cnt==0) cout<<s<<'\n';
        return;
    }

    for(int i=0 ; i<3 ; i++){
        if(i==0) dfs(dep+1,temp*10+dep+1,sign,cnt,s+' '+to_string(dep+1));
        else if(i==1) dfs(dep+1,dep+1,1,cnt+sign*temp,s+'+'+to_string(dep+1));
        else if(i==2) dfs(dep+1,dep+1,-1,cnt+sign*temp,s+'-'+to_string(dep+1));
    }

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    dfs(1,1,1,0,"1");    

    return 0;
}