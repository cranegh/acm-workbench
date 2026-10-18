#include<bits/stdc++.h>

using namespace std;
using ll = long long;

double mul(double ac){
    if(ac>=100.0000) return 0.25;
    else if(ac>=97.0000) return 0.22;
    else if(ac>=94.0000) return 0.17;
    else if(ac>=90.0000) return 0.15;
    else if(ac>=80.0000) return 0.12;
    else if(ac>=70.0000) return 0.08;
    return 0.05;
}

struct w{
    int id;
    double con,ach;
    bool operator <(const w &b)const
    {
        return con*ach*mul(ach) > b.con*b.ach*mul(b.ach);
    }
};

int rating(w a){
    return int(a.con*a.ach*mul(a.ach));
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    priority_queue<w>q,p;
    map<int,w>ma,mb,mc;
    for(int i=0;i<a;i++){
        w x;
        cin>>x.id>>x.con>>x.ach;
        if(x.ach > ma[x.id].ach) ma[x.id]=x;
    }
    for(int i=0;i<b;i++){
        w x;
        cin>>x.id>>x.con>>x.ach;
        if(x.ach > mb[x.id].ach) mb[x.id]=x;
    }
    for(int i=0;i<c;i++){
        w x;
        cin>>x.id>>x.con>>x.ach;
        if(x.ach > mc[x.id].ach) mc[x.id]=x;
    }
    int ans1=0,ans2=0;
    for(auto [x,y]:ma){
        if(q.empty()||q.size()<35){
            ans1+=rating(y);
            q.push(y);
        }
        else {
            w xx=q.top();
            if(rating(xx)<rating(y)){
                q.pop();
                ans1-=rating(xx);
                ans1+=rating(y);
                q.push(y);
            }
        }
    }
    //while(!q.empty())q.pop();
    for(auto [x,y]:mb){
        if(q.empty()||q.size()<35){
            ans1+=rating(y);
            q.push(y);
        }
        else {
            w xx=q.top();
            if(rating(xx)<rating(y)){
                q.pop();
                ans1-=rating(xx);
                ans1+=rating(y);
                q.push(y);
            }
        }
    }
    // for(auto [x,y]:mb){
    //     if(p.empty()||p.size()<15){
    //         ans2+=rating(y);
    //         p.push(y);
    //     }
    //     else {
    //         w xx=p.top();
    //         if(rating(xx)<rating(y)){
    //             p.pop();
    //             ans2-=rating(xx);
    //             ans2+=rating(y);
    //             p.push(y);
    //         }
    //     }
    // }
    for(auto [x,y]:mc){
        if(p.empty()||p.size()<15){
            ans2+=rating(y);
            p.push(y);
        }
        else {
            w xx=p.top();
            if(rating(xx)<rating(y)){
                p.pop();
                ans2-=rating(xx);
                ans2+=rating(y);
                p.push(y);
            }
        }
    }
    int ks=ans1+ans2;
    cout<<ks<<endl;
}