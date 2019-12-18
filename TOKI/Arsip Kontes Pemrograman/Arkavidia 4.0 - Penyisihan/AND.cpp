#include <bits/stdc++.h>
using namespace std;

int arr[200000], binary_sum[32][200000], n;

void countand() {
    for(int i=0; i<32; i++) {
        binary_sum[i][0] = ((arr[0] >> i) & 1);
        for(int j=1; j<n; j++) {
            binary_sum[i][j] = ((arr[j] >> i) & 1);
            binary_sum[i][j] += binary_sum[i][j-1];
        }
    }
}

int findand(int l, int r) {
    int res = 0;
    for(int i=0; i<32; i++) {
        int tmp;
        if(l == 1) {
            tmp = binary_sum[i][r-1];
        } else {
            tmp = binary_sum[i][r-1] - binary_sum[i][l-2];
        }
        if(tmp == (r - l + 1))
            res |= (1 << i);
    }
    return res;
}

int main() {
    int t;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>arr[i];
        }
        countand();
        int q;
        cin>>q;
        while(q--) {
            int l, r;
            cin>>l>>r;
            cout<<findand(l, r)<<'\n';
        }
    }
}