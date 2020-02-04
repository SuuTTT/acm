/*
结构体型线段树，区间加，区间求和。
build里的初始化要注意。
*/
const int MAXN = 200010;
typedef long long LL;
struct Node {
    int l, r;
    LL lazy;
    LL sum;
} segTree[MAXN * 4];
void build(int i, int l, int r) {
    segTree[i].l = l;
    segTree[i].r = r;
    if (l == r) {
        segTree[i].sum=a[i];
        return;
    }
    int mid = l + r >> 1;
    build(i << 1, l, mid);
    build(i << 1 | 1, mid + 1, r);
    segTree[i].sum = segTree[i << 1].sum + segTree[i << 1 | 1].sum;
}
void push_up(int i, LL v) {
    segTree[i].sum += (segTree[i].r - segTree[i].l + 1) * v;
    segTree[i].lazy += v;
}
void push_down(int i) {
    if (segTree[i].l == segTree[i].r) return;
    push_up(i << 1, segTree[i].lazy);
    push_up(i << 1 | 1, segTree[i].lazy);
    segTree[i].lazy = 0;
}
void add(int i, int l, int r, LL v) {
    if (segTree[i].l >= l && segTree[i].r <= r) {
        push_up(i, v);
        return;
    }
    push_down(i);
    int mid = segTree[i].l + segTree[i].r >> 1;
    if (mid >= l) add(i << 1, l, r, v);
    if (mid < r) add(i << 1 | 1, l, r, v);
    segTree[i].sum = segTree[i << 1].sum + segTree[i << 1 | 1].sum;
}
LL query(int i, int l, int r) {
    if (segTree[i].l == l && segTree[i].r == r) return segTree[i].sum;
    push_down(i);
    int mid = segTree[i].l + segTree[i].r >> 1;
    if (r <= mid) return query(i << 1, l, r);
    else if (l > mid) return query(i << 1 | 1, l, r);
    else return query(i << 1, l, mid) + query(i << 1 | 1, mid + 1, r);
}
