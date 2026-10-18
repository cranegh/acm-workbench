#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<bitset>
#include<set>

using namespace std;
using ll = long long;

int n;
int a[6][6];

int ans=0;

bool checkx(int x)
{
    int res=0;
    for(int i=1 ; i<=5 ; i++){
        res+=a[x][i];
    }
    if(res==5 || res==-5) return false;
    return true;
}//合法返回true

bool checky(int y)
{
    int res=0;
    for(int i=1 ; i<=5 ; i++){
        res+=a[i][y];
    }
    if(res==5 || res==-5) return false;
    return true;
}//合法返回true

bool checkzu()
{
    int res=0;
    for(int i=1 ; i<=5 ; i++){
        res+=a[i][i];
    }
    if(res==5 || res==-5) return false;
    return true;
}//合法返回true

bool checkfu()
{
    int res=0;
    for(int i=1 ; i<=5 ; i++){
        res+=a[i][6-i];
    }
    if(res==5 || res==-5) return false;
    return true;
}//合法返回true

void dfs(int x, int y,int cnt,int b, int h){

    if(b>13 || h>12) return;

    if(cnt==25){
        for(int i=1 ; i<=5 ; i++) if(!checkx(i)) return;
        for(int i=1 ; i<=5 ; i++) if(!checky(i)) return;
        if(!checkzu()) return; if(!checkfu()) return;

        ans++;
        return;
    }

    if(x>5) return;

    int ne_x = y==5 ? x+1 : x;
    int ne_y = y==5 ? 1 : y+1;

    a[x][y]=1;
    dfs(ne_x,ne_y,cnt+1,b+1,h);

    a[x][y]=-1;
    dfs(ne_x,ne_y,cnt+1,b,h+1);

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    dfs(1,1,0,0,0);

    cout<<ans;

    return 0;
}