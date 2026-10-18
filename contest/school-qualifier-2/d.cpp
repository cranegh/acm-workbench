#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll r;

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

double getd(Point a, Point b){
    if(dis(a,b)==0) return r;
    return abs(cross(a,b))/dis(a,b);
}

double getS(double d){
    return r*r*acos(d/r) - d*sqrt(r*r-d*d);
}

auto getHull(vector<Point> p){
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
    cin>>r;
    vector<Point> a(n);
    for(int i=0 ; i<n ; i++){
        ll xx, yy; cin>>xx>>yy;
        a[i]={xx,yy};
    }

    auto [hi,lo] = getHull(a);

    double S = 0;

    bool isin = true;
    Point O(0,0);

    if (0<=lo[0].x || 0>=lo.back().x) isin = false;


    for(int i=0 ; i<hi.size()-1 ; i++){
        double cur_d = getd(hi[i],hi[i+1]);
        double cur_s = getS(cur_d);

        Point AB = hi[i+1]-hi[i];
        Point AO = O - hi[i];
        if(cross(AB,AO)>=0) isin = false;

        if(cur_s>S) S = cur_s; 
    }
    
    for(int i=0 ; i<lo.size()-1 ; i++){
        double cur_d = getd(lo[i],lo[i+1]);
        double cur_s = getS(cur_d);

        Point AB = lo[i+1]-lo[i];
        Point AO = O - lo[i];
        if(cross(AB,AO)<=0) isin = false;

        if(cur_s>S) S = cur_s; 
    }

    double cur_d1 = getd(lo[0],hi[0]);
    double cur_s1 = getS(cur_d1);
    if(cur_s1>S) S = cur_s1; 
    
    double cur_d2 = getd(lo[lo.size()-1],hi[hi.size()-1]);
    double cur_s2 = getS(cur_d2);
    if(cur_s2>S) S = cur_s2; 

    if(!isin) S = acos(-1.0)*r*r/2;
    cout<<fixed<<setprecision(9)<<S;
    
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; //cin>>T;
    while(T--) solve();

    return 0;
}