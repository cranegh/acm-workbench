#include<iostream>
#include<cstring>
using namespace std;
long long w(long a,long b,long c);
long long f[22][22][22];
int main(){
    int a,b,c;
    memset(f,-1,sizeof(f));
    while (cin>>a>>b>>c)
    {
        if(a==-1 && b==-1 && c==-1) break;
        cout<<"w("<<a<<", "<<b<<", "<<c<<")"<<" = "<<w(a,b,c)<<endl;
    }
    return 0;
    
}
long long w(int a,int b,int c){
    if (f[a][b][c]!=-1) return f[a][b][c]; 
    if(a<=0 || b<=0 || c<=0){
        return 1;
    }else if(a>20 || b>20 || c>20){
        return f[a][b][c]=w(20,20,20);
    }else if(a<b && b<c){
        return f[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }else return f[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
}