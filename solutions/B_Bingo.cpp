#include<iostream>

using namespace std;
using ll = long long;

char s[6][6];

bool px=0,py=0,p_s=0,p_j=0;
bool bingo=0;

void check_x(){
    for(int i=1 ; i<=5 ; i++){
        px=1;
        for(int j=1 ; j<=5 ; j++){
            if(s[i][j]!='1') px=0;
        }
        if(px==1){
            bingo=1;
            break;
        }
    }
}

void check_y(){
    for(int j=1 ; j<=5 ; j++){
        py=1;
        for(int i=1 ; i<=5 ; i++){
            if(s[i][j]!='1') py=0;
        }
        if(py==1){
            bingo=1;
            break;
        }
    }
}

void check_s(){
    p_s=1;
    for(int i=1 ; i<=5 ; i++){
        int j=6-i;
        if(s[i][j]!='1') p_s=0;
    }
    if(p_s==1) bingo=1;
}

void check_j(){
    p_j=1;
    for(int i=1 ; i<=5 ; i++){
        int j=i;
        if(s[i][j]!='1') p_j=0;
    }
    if(p_j==1) bingo=1;
}

ll point(int x, int y){
    if(s[x][y]=='0') return 0;

    ll cur_point=1;
    
    ll cur_x=1;
    for(int j=-1 ; y+j>=1 ; j--){
        if(s[x][y+j]=='0') break;
        cur_x++;
    }
    for(int j=1 ; y+j<=5 ; j++){
        if(s[x][y+j]=='0') break;
        cur_x++;
    }
    if(cur_x>cur_point) cur_point=cur_x;

    ll cur_y=1;
    for(int i=-1 ; x+i>=1 ; i--){
        if(s[x+i][y]=='0') break;
        cur_y++;
    }
    for(int i=1 ; x+i<=5 ; i++){
        if(s[x+i][y]=='0') break;
        cur_y++;
    }
    if(cur_y>cur_point) cur_point=cur_y;


    ll cur_s=1;
    for(int i=-1,j=1 ; x+i>=1 && y+j<=5 ; i--,j++){
        if(s[x+i][y+j]=='0') break;
        cur_s++;
    }
    for(int i=1,j=-1 ; x+i<=5 && y+j>=1 ; i++,j--){
        if(s[x+i][y+j]=='0') break;
        cur_s++;
    }
    if(cur_s>cur_point) cur_point=cur_s;


    ll cur_j=1;
    for(int i=-1,j=-1 ; x+i>=1 && y+j>=1 ; i--,j--){
        if(s[x+i][y+j]=='0') break;
        cur_j++;
    }
    for(int i=1,j=1 ; x+i<=5 && y+j<=5; i++,j++){
        if(s[x+i][y+j]=='0') break;
        cur_j++;
    }
    if(cur_j>cur_point) cur_point=cur_j;

    if(cur_point==4) cur_point=3;
    else if(cur_point==3) cur_point=2;
    else cur_point=1;

    return cur_point;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    for(int i=1 ; i<=5 ; i++) for(int j=1 ; j<=5 ; j++) cin>>s[i][j];

    check_x(); check_y(); check_s(); check_j();

    if(bingo){
        cout<<"Bingo!";
        return 0;
    }

    ll sum=0;

    for(int i=1 ; i<=5 ; i++){
        for(int j=1 ; j<=5 ; j++){
            sum+=point(i,j);
        }
    }

    cout<<sum;

    return 0;
}