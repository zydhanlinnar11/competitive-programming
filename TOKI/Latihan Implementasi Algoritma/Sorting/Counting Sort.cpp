#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, count[1001] = {0}, tmp;
    cin>>n;
    for(int i=0; i<n; i++) {
        cin>>tmp;
        count[tmp]++;
    }
    for(int i=0; i<1001; i++) {
        while(count[i] > 0) {
            cout<<i<<'\n';
            count[i]--;
        }
    }
}