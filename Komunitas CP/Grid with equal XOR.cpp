#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        int start = ((i % 4) * 4) + ((i / 4) * (32 + (((n - 8) / 4) * 16)));
        for(int j=0; j<n; j++) {
            cout<<(start + (j % 4) + ((j / 4) * 16));
            if(j < (n - 1))
                cout<<' ';
        }
        cout<<'\n';
    }
    return 0;
}