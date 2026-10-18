#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

int main(){
    stack< int > st;
    int num=0;
        char s; while(cin>>s){

        if(s=='@') break;
        if(s=='.') {
            st.push(num);
            num=0;
            continue;
        }
        
        if(s=='-'){
            int x=st.top(); st.pop();
            int y=st.top(); st.pop();
            st.push(y-x);
        }else if(s=='+'){
            int x=st.top(); st.pop();
            int y=st.top(); st.pop();
            st.push(x+y);
        }else if(s=='*'){
            int x=st.top(); st.pop();
            int y=st.top(); st.pop();
            st.push(x*y);
        }else if(s=='/'){
            int x=st.top(); st.pop();
            int y=st.top(); st.pop();
            st.push(y/x);
        }
        else{
            num=num*10+s-'0';
        }
    }

    cout<<st.top();



}