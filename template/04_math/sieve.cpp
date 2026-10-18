// 埃氏筛
// 筛出 2..n 所有素数；O(n log log n)
// 0<=n<N；vis=1 表示非素数；保留从 2*i 开始，只修正原 vis[i] 笔误
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6+9;
bitset<N> vis;
vector<int> pri;

void sieve(int n){
    vis.reset(); pri.clear();
    vis[0]=1,vis[1]=1;
    for(int i=2 ; i<=n ; i++){
        if(!vis[i]){
            for(int j=2*i ; j<=n ; j+=i) vis[j]=1;
        }
    }
    for(int i=1 ; i<=n ; i++) if(!vis[i]) pri.push_back(i);
}
