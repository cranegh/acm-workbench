#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, s;
int a[maxn];
int ans = 0, sum = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    ans = n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    if(sum == s){
        cout << ans;
        return 0;
    }
    cout << ans - 1 << endl;
    return 0;
}