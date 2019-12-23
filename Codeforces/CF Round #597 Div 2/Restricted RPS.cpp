#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, n, t;
    string bob;
    char alice[105];
    cin>>t;
    while(t--) {
        int lose = 0;
        cin>>n>>a>>b>>c>>bob;
        for(int i=0; i<n; i++) {
            if(bob[i] == 'R' && b-- > 0) alice[i] = 'P';
            else if(bob[i] == 'P' && c-- > 0) alice[i] = 'S';
            else if(bob[i] == 'S' && a-- > 0) alice[i] = 'R';
            else {
                lose++;
                alice[i] = 'X';
            }
        }
        if(lose <= (n >> 1)) {
            cout<<"YES\n";
            for(int i=0; i<n; i++) {
                if(alice[i] == 'X') {
                    if(a-- > 0) cout<<'R';
                    else if(b-- > 0) cout<<'P';
                    else if(c-- > 0) cout<<'S';
                } else cout<<alice[i];
            }
            cout<<'\n';
        } else cout<<"NO\n";
    }
    return 0;
}