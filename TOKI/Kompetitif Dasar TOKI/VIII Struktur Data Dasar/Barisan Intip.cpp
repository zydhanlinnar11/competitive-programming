#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
#define MXBIT 25
#define MXN 100005

vi lg(MXN);

inline int rmq(vvi &st, int l, int r) {
    int j = lg[r - l + 1];
    return max(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
    lg[1] = 0;
    for(int i=2; i<MXN; i++)
        lg[i] = lg[i >> 1] + 1;
    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
    vvi st(n, vi(MXBIT));
    for(int i=0; i<n; i++)
        st[i][0] = arr[i];
    for(int j=1; j<MXBIT; j++) {
        for(int i=0; i + (1 << j) < n; i++) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    long long ans = 1;
    for(int i=1; i<n; i++) {
        int mx = rmq(st, 0, i - 1);
        if(mx <= arr[i]) {
            ans += i + 1;
            continue;
        }
        int l = 0, r = i - 1;
        int tmp = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            mx = rmq(st, mid, i - 1);
            if(mx > arr[i]) {
                tmp = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans += i - tmp;
    }
    cout<<ans<<"\n";
}