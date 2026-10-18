#include<iostream>
#include<cstring>
using namespace std;
int main(){
    string word;
    string s;
    getline(cin,word);
    getline(cin,s);
    for( int i=0 ; i<word.length() ; i++){
        if( 'A'<=word[i] && word[i]<='Z' ){
            word[i]=word[i]+'a'-'A';
        }
    }
    for( int i=0 ; i<s.length() ; i++){
        if( 'A'<=s[i] && s[i]<='Z' ){
            s[i]=s[i]+'a'-'A';
        }
    }
    word=' '+word+' ';
    s=' '+s+' ';
    if( s.find(word)==-1 ){
        cout<<-1;
    }else{
        int firstpos,nextpos,cnt=0;
        firstpos=s.find(word);
        nextpos=s.find(word);
        while( nextpos!=-1 ){
            cnt++;
            nextpos=s.find(word,nextpos+1);
        }
        cout<<cnt<<" "<<firstpos<<endl;
    }
    return 0;
}