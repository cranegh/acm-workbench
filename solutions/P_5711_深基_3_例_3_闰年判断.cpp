#include<iostream>
using namespace std;
int main(){
    int x;
    cin>>x;
    bool p1=!(x%4),p2=(x%100),p3=!(x%400);
    cout<<((p1&&p2)||p3);
    return 0;
}