#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=(t/7); i>=0; i--) {
        if((t - (7 * i)) % 4 == 0) {
            for(int j=0; j <((t - (7 * i)) / 4); j++)
                cout<<4;
            for(int j=0; j<i; j++)
                cout<<7;
            cout<<'\n';
            exit(0);
        }
    }
    cout<<"-1\n";
    return 0;
}