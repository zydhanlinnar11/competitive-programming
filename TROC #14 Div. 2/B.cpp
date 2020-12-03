#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>>n>>m;
    char arr[n][m];
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout<<((j & 1) ? 'B' : 'W');
        }
        cout<<'\n';
    }
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<m; j++) {
    //         int botw = 0, botb = 0;
    //         if(j != 0 && i != n - 1) {
    //             if(arr[i])
    //         }
    //     }
    // }
    return 0;
}