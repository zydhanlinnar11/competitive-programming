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
    return segTree[idx] = max(construct(segTree, arr, low, mid, 2*idx + 1), construct(segTree, arr, mid + 1, high, 2*idx + 2));
}

void constructSegmentTree(ll segTree[], ll arr[], int n) {
    segTree[0] = construct(segTree, arr, 0, n - 1, 0);
}

ll getMax(ll segTree[], int &lquery, int &rquery, int low, int high, int idx) {
    if(rquery < low || lquery > high)
        return INT64_MIN;
    if(lquery <= low && rquery >= high)
        return segTree[idx];
    int mid = low + (high - low) / 2;
    return max(getMax(segTree, lquery, rquery, low, mid, 2*idx + 1), getMax(segTree, lquery, rquery, mid + 1, high, 2*idx + 2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin>>n;
    int near = getNearPowerTwo(n);
    ll arr[near];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=n; i<near; i++)
        arr[i] = 0;
    ll segTree[near*2 - 1];
    constructSegmentTree(segTree, arr, near);
    cin>>q;
    while(q--) {
        int l, r;
        cin>>l>>r;
        ll maks = getMax(segTree, --l, --r, 0, near - 1, 0);
        if(arr[l] == arr[r] && maks == arr[l])
            cout<<"YA\n";
        else cout<<"TIDAK\n";
    }
    return 0;
}