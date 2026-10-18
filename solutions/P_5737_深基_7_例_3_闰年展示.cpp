#include<iostream>
#include<vector>
using namespace std;
bool runnian(int x);
int main(){
    int x,y,cnt=0;
    vector<int> s;
    cin>>x>>y;
    for(int i=x ; i<=y ; i++){
        if(runnian(i)){
            cnt++;
            s.push_back(i);
        }
    }
    cout<<cnt<<endl;
    for (int i=0; i<size(s) ; i++)
        {
            cout<<s[i]<<" ";
        }
        return 0;
}
bool runnian(int x){
    if((x%4==0) && (x%100!=0) || (x%400==0))
    return true;
    else return false;
}