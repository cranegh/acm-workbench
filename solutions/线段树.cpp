#include<iostream>

using namespace std;
using ll = long long;

const int N =5e5+9;
int a[N];
int add[4*N];
int sum[4*N];

void update(int i)
{
    sum[i]=sum[i<<1]+sum[i<<1 | 1];
}

void lazy(int i, int v, int n)
{
    sum[i]+=v*n;
    add[i]+=v;
}

void down(int i, int ln, int rn)
{
    if(add[i]!=0){
        lazy(i<<1,add[i],ln);
        lazy(i<<1|1,add[i],rn);
        add[i]=0;
    }
}

void build(int l, int r, int i)
{
    if(l==r) sum[i]=a[l];
    else{
        int mid=(l+1)>>1;

        build(l,mid,i<<1);
        build(mid+1,r,i<<1|1);
        update(i);
    }
    add[i]=0;
}

int query(int jobl, int jobr, int l, int r, int i)
{
    if(jobl<=l && r<=jobr) return sum[i];
    int mid = (l+r)>>1;
    down(i,mid-l+1,r-mid);
    
    int ans=0;
    if(jobl<=mid){
        ans+=query(jobl,jobr,l,mid,i<<1);
    }
    if(jobr>=mid){
        ans+=query(jobl,jobr,mid+1,r,i<<1|1);
    }
 
    return ans;
}

void fadd(int jobl, int jobr, int jobv, int l, int r, int i)
{
    if(jobl<=l && r<=jobr) lazy(i,jobv,r-l+1);
    else {
        int mid=(l+r)>>1;
        down(i,mid-l+1,r-mid);

        if(jobl<=mid){
            fadd(jobl,jobr,jobv,l,mid,i<<1);
        }
        if(jobr>=mid){
            fadd(jobl,jobr,jobv,mid+1,r,i<<1|1);
        }
        update(i);
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    
    
    return 0;
}