// 二维凸包
// 保留原 P1452 的 Point、cross、dis 和上/下凸壳写法；O(n log n)
// 整数坐标 |x|,|y|<=1e9，保证本模板的差、叉积和距离平方在 ll 内
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point{
    ll x;
    ll y;
    Point() : x{0},y{0} {}
    Point(ll x_, ll y_) : x{x_},y{y_}{}
};

ll cross(Point a, Point b){
    return a.x*b.y - a.y*b.x;
}

Point operator+(Point a, Point b){
    return Point(a.x+b.x,a.y+b.y);
}

Point operator-(Point a, Point b){
    return Point(a.x-b.x,a.y-b.y);
}

// 沿用原 dis：返回距离平方，不是欧氏距离。
ll dis(Point a, Point b){
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

auto getHull(vector<Point> p){
    sort(p.begin(),p.end(),
    [&](auto a, auto b){
        return a.x<b.x || (a.x==b.x && a.y<b.y);
    });

    vector<Point> hi,lo;
    for(auto p : p){
        while(hi.size()>1 &&
              cross(hi.back()-hi[hi.size()-2] , p-hi.back() ) >= 0) hi.pop_back();

        while(!hi.empty() && hi.back().x == p.x) hi.pop_back();

        hi.push_back(p);

        while(lo.size()>1 &&
              cross(lo.back()-lo[lo.size()-2] , p-lo.back() ) <= 0) lo.pop_back();

        if(lo.empty() || lo.back().x < p.x) lo.push_back(p);
    }
    return make_pair(hi,lo);
}

// auto [hi,lo] = getHull(a); 两条链都按 x 递增，hi 是上壳、lo 是下壳。
// 它们不是一个按逆时针排列的点集；需要闭合边界时还要连两端。
// 同 x 的点：hi 留最高点、lo 留最低点；共线中间点被弹出。
// 空输入返回两条空链，调用 front()/back() 前先判空。
// 原 P2742 的实数坐标版把 Point/cross 改成 double，dis 再开根。
