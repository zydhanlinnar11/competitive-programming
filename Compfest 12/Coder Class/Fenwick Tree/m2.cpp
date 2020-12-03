#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int getParent(int x) {
    return x - (((~x) + 1) & x);
}

int getNext(int x) {
    return x + (((~x) + 1) & x);
}

ll * constructFenwick(ll arr[], int n) {
    ll *fen = new ll[n + 1];
    for(int i=0; i<=n; i++)
        fen[i] = 0;
    for(int i=0; i<n; i++) {
        int curr = i + 1;
        while(curr <= n) {
            fen[curr] += arr[i];
            curr = getNext(curr);
        }
    }
    return fen;
}

ll getSum(ll *fen, int n) {
    ll sum = 0;
    n++;
    while(n > 0) {
        sum += fen[n];
        n = getParent(n); 
    }
    return sum;
}

ll* updateFenwick(ll *fen, ll diff, int n, int idx) {
    idx++;
    while(idx <= n) {
        fen[idx] += diff;
        idx = getNext(idx);
    }
    return fen;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    ll *fen = constructFenwick(arr, n);
    for(int i=0; i<m; i++) {
        int c1, c2, c3;
        cin>>c1>>c2>>c3;
        if(c1 == 1) {
            ll diff = (arr[c2 - 1] ^ c3) - arr[c2 - 1];
            arr[c2 - 1] += diff;
            fen = updateFenwick(fen, diff, n, c2 - 1);
        } else {
            if(c2 == 1)
                cout<<getSum(fen, c3 - 1)<<'\n';
            else cout<<getSum(fen, c3 - 1) - getSum(fen, c2 - 2)<<'\n';
        }
    }
    return 0;
}