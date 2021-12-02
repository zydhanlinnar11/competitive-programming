#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getNearPowerTwo(int n) {
    return (int)pow(2, ceil(log2(n)));
}

ll construct(ll segTree[], ll arr[], int low, int high, int idx) {
    if(low == high) {
        segTree[idx] = arr[low];
        return segTree[idx];
    }
    int mid = low + (high - low) / 2;
    return segTree[idx] = construct(segTree, arr, low, mid, 2*idx + 1) + construct(segTree, arr, mid + 1, high, 2*idx + 2);
}

void constructSegmentTree(ll segTree[], ll arr[], int n) {
    segTree[0] = construct(segTree, arr, 0, n - 1, 0);
}

ll getSum(ll segTree[], int &lquery, int &rquery, int low, int high, int idx) {
    if(rquery < low || lquery > high)
        return 0LL;
    if(lquery <= low && rquery >= high)
        return segTree[idx];
    int mid = low + (high - low) / 2;
    return getSum(segTree, lquery, rquery, low, mid, 2*idx + 1) + getSum(segTree, lquery, rquery, mid + 1, high, 2*idx + 2);
}

ll update(ll segTree[], int &lquery, int &rquery, int low, int high, int idx, int &bit) {
    if(rquery < low || lquery > high)
        return segTree[idx];
    if(lquery <= low && rquery >= high && low == high)
        return segTree[idx] = segTree[idx] ^ (1 << bit);
    int mid = low + (high - low) / 2;
    return segTree[idx] = update(segTree, lquery, rquery, low, mid, 2*idx + 1, bit)
    + update(segTree, lquery, rquery, mid + 1, high, 2*idx + 2, bit);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n>>q;
    int near = getNearPowerTwo(n);
    ll arr[near];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=n; i<near; i++)
        arr[i] = 0;
    ll segTree[near*2 - 1];
    constructSegmentTree(segTree, arr, near);
    while(q--) {
        int cmd;
        cin>>cmd;
        if(cmd == 1) {
            int l, r, b;
            cin>>l>>r>>b;
            l--, r--;
            update(segTree, l, r, 0, near - 1, 0, b);
        } else {
            int l, r;
            cin>>l>>r;
            cout<<getSum(segTree, --l, --r, 0, near - 1, 0)<<'\n';
        }
    }
    return 0;
}