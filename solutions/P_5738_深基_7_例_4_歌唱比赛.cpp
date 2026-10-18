#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int s[n][m];
    for( int i=0 ; i<n ; i++){
        for( int j=0 ; j<m ; j++){
            cin>>s[i][j];
        }
    }
    double p[n]={0},max=0;
    for( int i=0 ; i<n ; i++){
        sort(&s[i][0],&s[i][m]);
        for( int j=1 ; j<m-1 ; j++){
            p[i]+=s[i][j];
        }
        p[i]/=(m-2);
        if(p[i]>max) max=p[i];
    }
    printf("%.2f",max);
    return 0;
}