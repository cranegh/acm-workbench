#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

const int N = 2e5+9;

struct pai{
    int num;
    char c;
    int idx;
    bool operator < (const pai& u) const{
        if(num==u.num) return c<u.c;
        else return num<u.num;
    }
}p[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int n; cin>>n;
    for(int i=1 ; i<=n ; i++) cin>>p[i].num>>p[i].c;
    for(int i=1 ; i<=n ; i++) p[i].idx=i;

    sort(p+1,p+1+n);

    vector<int> ans;
    int cnt=1;
    int tempn=0;
    char tempc='a';
    while(cnt<=n){
        if(p[cnt+1].num==p[cnt].num && p[cnt+1].c!=p[cnt].c && !(p[cnt].num==tempn && p[cnt].c==tempc) ){
            ans.push_back(p[cnt].idx);
            ans.push_back(p[cnt+1].idx);
            tempn=p[cnt+1].num;
            tempc=p[cnt+1].c;
            cnt+=2;
        }else cnt++;
    }

    cout<<ans.size()<<'\n';
    for(int i=0 ; i<ans.size() ; i+=2){
        cout<<ans[i]<<' '<<ans[i+1]<<'\n';
    }

    return 0;
}