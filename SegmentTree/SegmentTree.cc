#include<bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
int a[N], seg[4 * N];
void build(int now, int l, int r) {
    if(l == r) {
        seg[now] = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(now * 2, l, mid);
    build(now * 2 + 1, mid + 1, r);
    seg[now] = max(seg[now * 2], seg[now * 2 + 1]);
}
void update(int l, int r, int idx, int val, int now) {
    if(l > r || l > idx || r < idx)
        return ;
    if(l == r) {
        seg[now] = val;
        return ;
    }
    int mid = (l + r) >> 1;
    update(l, mid, idx, val, now * 2);
    update(mid + 1, r, idx, val, now * 2 + 1);
    seg[now] = max(seg[now * 2], seg[now * 2 + 1]);
}
int query(int l, int r, int ll, int rr, int now) {
    if(l > r || l > rr || r < ll)
        return -1e9;
    if(l >= ll && r <= rr)
        return seg[now];
    int mid = (l + r) >> 1;
    return max(query(l, mid, ll, rr, now * 2), query(mid + 1, r, ll, rr, now * 2 + 1));
}
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    while(q--) {
        char opr;
        cin >> opr;
        if(opr == 'U') {
            int idx, val;
            cin >> idx >> val;
            update(1, n, idx, val, 1);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << query(1, n, l, r, 1) << "\n";
        }
    }
    return 0;
}
