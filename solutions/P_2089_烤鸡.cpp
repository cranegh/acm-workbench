#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
using ll = long long;

vector<int> ans;
int a[11];
int n;
ll tt=0,cnt=0;

void dfs(int x)
{
    if(x==11){
        if(tt==n){
            cnt++;
            for(int i=1 ; i<=10 ; i++) ans.push_back(a[i]);
        }
        
        return;
    }

    for(int i=1 ; i<=3 ; i++){
        if(tt>n) break;

        a[x]=i;
        tt+=a[x];

        dfs(x+1);

        tt-=i;
    }

}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;
    
    dfs(1);
    cout<<cnt<<'\n';
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<(((i+1)%10==0)?'\n':' ');
    }

}

