#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main(){
    int n;
    cin>>n;
    stack<int> s;
    while(n--)
    {
        string op;
        cin>>op;
        if (op=="push"){
            int x;
            cin>>x;
            s.push(x);
        }
        if (op=="pop"){
            if(s.empty()) cout<<"Empty\n";
            else s.pop();
        }
        if (op=="query"){
            if(s.empty()) cout<<"Empty\n";
            else cout<<s.top()<<endl;
        }
        if (op=="size") cout<<s.size()<<endl;
    }
    return 0;
}
