#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

const int N = 20;
int n,cnt=0;
bool dia1[2*N],dia2[2*N],l[N];
int a[N];

void print()
{
    if(cnt<=3){
    for(int i=1 ; i<=n ; i++) cout<<a[i]<<' ';
    cout<<'\n';
    }
}

void dfs(int r){
    if(r>n){
        cnt++;
        print();
        return;
    }
    for(int i=1 ; i<=n ; i++)
    {
        if(!dia1[i+r] && !dia2[i-r+n] && !l[i]){
         dia1[i+r]=true;
         dia2[i-r+n]=true;
         l[i]=true;
         a[r]=i;   
        

        dfs(r+1);

    

        dia1[i+r]=false;
        dia2[i-r+n]=false;
        l[i]=false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    cin>>n;

    dfs(1);

    cout<<cnt;

    return 0;

}