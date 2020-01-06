#include <bits/stdc++.h>
using namespace std;
int n, q, m, l, r, arr[100001] = {0};
void comp() {
    for(int i = 0; i <= 100000; i++) {
        if(i > 0)
            arr[i] += arr[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    while(n--) {
        int tmp;
        cin>>tmp;
        arr[tmp]++;
    }
    cin>>q;
    comp();
    while(q--) {
        cin>>l>>r;
        cout<<(arr[r] - ((l > 0) ? arr[l - 1] : 0))<<'\n';
    }
    return 0;
}