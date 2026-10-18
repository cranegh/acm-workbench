#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
using ll = long long;

const int N = 3600*24+9;

int diff[N];

int to_seconds(int h,int m,int s){
    return 3600*h+60*m+s;
}

void solve()
{
    int n ; cin>>n;
    for(int i=1 ; i<=n ; i++){
        int h1,m1,s1,h2,m2,s2; scanf("%d:%d:%d",&h1,&m1,&s1) ; scanf("%d:%d:%d",&h2,&m2,&s2);
        int start = to_seconds(h1,m1,s1);
        int finish = to_seconds(h2,m2,s2);
        diff[start]++;
        diff[finish+1]--;
    }

    int sum=0, max_sum=0;
    for(int i=1 ; i<=N-9 ; i++){
        sum+=diff[i];
        max_sum=max(sum,max_sum);
    }

    cout<<max_sum;

}

int main(){

    int _; _=1;
    while(_--) solve();

    return 0;
}