struct node{
    int x,y,d;
    node (int xx,int yy,int dd):x(xx),y(yy),d(dd){}
    bool operator< (node const &a)const { return d>a.d; }
};