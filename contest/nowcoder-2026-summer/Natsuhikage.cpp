#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point{
    ll x,y;
};

ll dot(Point a, Point b){
    return a.x*b.x + a.y*b.y;
}

ll cross(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}

Point operator- (Point a, Point b){
    ll xx = a.x-b.x;
    ll yy = a.y-b.y;
    Point res = {xx,yy};
    return res;
}

ll getlength(Point p){
    return p.x*p.x + p.y*p.y;
}

void solve()
{
    ll sx,sy,ax,ay,bx,by;
    cin>>sx>>sy>>ax>>ay>>bx>>by;

    Point S = {sx,sy};
    Point A = {ax,ay};
    Point B = {bx,by};
    Point O = {0ll,0ll};

    Point SO = O-S;
    Point OA = A-O;
    Point OB = B-O;

    double sinb = sqrt(1.0 - 1.0*SO.x*SO.x/getlength(SO)); 
    
    double sina1 = abs(cross(OA,SO)/(sqrt(getlength(OA))*sqrt(getlength(SO))));
    double sina2 = abs(cross(OB,SO)/(sqrt(getlength(OB))*sqrt(getlength(SO))));
    
    double ans1 = sina1*sqrt(getlength(OA))/sinb;
    double ans2 = sina2*sqrt(getlength(OA))/sinb;
    
    double mx = max(ans1,ans2);
    double mn = min(ans1,ans2);
    if( (dot(SO,OA)<0 && dot(SO,OB)>0) || (dot(SO,OA)>0 && dot(SO,OB)<0) ){
        mx = sqrt(getlength(OA))/sinb;
    }
    if( (cross(SO,OA)<0 && cross(SO,OB)>0) || (cross(SO,OA)>0 && cross(SO,OB)<0) ){
        mn = 0;
    }

    cout<<fixed<<setprecision(15)<<mn<<" "<<mx<<'\n';

}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    int T = 1; cin>>T;
    while(T--) solve();

    return 0;
}