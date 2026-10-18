int gcd(int da,int xiao){
    int temp;
    while(xiao!=0){
        temp=da%xiao;
        da=xiao;
        xiao=temp;
    }
    return da;  
}

int gcd(int da,int xiao){
    if(xiao==0) return da;
    else return gcd(xiao,da%xiao);
}