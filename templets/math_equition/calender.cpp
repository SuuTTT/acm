int zeller(int y,int m,int d){//date->week%7 0 is 日
    int c=y/100;
    y=y%100;
    int ret=c/4-2*c+y+y/4+13*(m+1)/5+d-1;
    ret%=7;ret+=7;ret%=7;
    return ret;
}