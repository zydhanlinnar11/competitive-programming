#include <bits/stdc++.h>
#define MXX 505
using namespace std;
typedef long long ll;
typedef bitset<MXX> bt;
typedef vector<bt> vbt;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int v, h, n;
vbt arr, computed;
vvl res;

inline ll compute(int i, int j) {
    if(j < 0 || j >= h || i >= v)
        return 0;
    if(computed[i][j]) return res[i][j];
    computed[i][j] = true;
    if(!arr[i][j]) {
        res[i][j] = compute(i + 1, j);
        return res[i][j];
    }
    int l = j, r = j;
    while(l >= 0 && arr[i][l]) l--;
    while(r < h && arr[i][r]) r++;
    res[i][j] = 1 + compute(i, l) + compute(i, r);
    return res[i][j];
}

int main() {
    cin>>v>>h>>n;
    arr = vbt(v);
    computed = vbt(v);
    res = vvl(v, vl(h));
    for(int i=0; i<n; i++) {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        a--, b--, c--, d--;
        for(int j=a; j<=c; j++) {
            for(int k=b; k<=d; k++) {
                arr[j].set(k);
            }
        }
    }
    ll mx = 0;
    for(int i=0; i<h; i++) {
        mx = max(mx, compute(0, i));
    }
    cout<<mx<<"\n";
}