#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point{
    double x;
    double y;
    Point() : x{0},y{0} {}
    Point(double x_, double y_) : x{x_},y{y_}{}
};

double cross(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}

Point operator+(Point a, Point b){
    return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a, Point b){
    return Point(a.x-b.x,a.y-b.y);
}

double dis(Point a, Point b){
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}

auto getHudouble(vector<Point> p){
    sort(p.begin(),p.end(),
    [&](auto a, auto b){
        return a.x<b.x || (a.x==b.x && a.y<b.y);
    });

    vector<Point> hi,lo;
    for(auto p : p){
        while(hi.size()>1 && cross(hi.back()-hi[hi.size()-2] , p-hi.back() ) >= 0) hi.pop_back();
        
        while(!hi.empty() && hi.back().x == p.x) hi.pop_back();

        hi.push_back(p);

        while(lo.size()>1 && cross(lo.back()-lo[lo.size()-2] , p-lo.back() ) <= 0) lo.pop_back();

        if(lo.empty() || lo.back().x < p.x) lo.push_back(p);
    }
    return make_pair(hi,lo);
}

void solve()
{
    int n; cin>>n;
    vector<Point> a(n);
    for(int i=0 ; i<n ; i++){
        double xx, yy; cin>>xx>>yy;
        a[i]={xx,yy};
    }

    auto [hi,lo] = getHudouble(a);

    double ans = 0;
    for(int i=0 ; i<hi.size()-1 ; i++) ans += dis(hi[i],hi[i+1]);
    for(int i=0 ; i<lo.size()-1 ; i++) ans += dis(lo[i],lo[i+1]);

    ans += dis(hi[0], lo[0]); 
    ans += dis(hi.back(), lo.back());

    cout<<fixed<<setprecision(2)<<ans;
    
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}